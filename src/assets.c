// Loading textures and sounds from ./resources, and the audio mixer.
#include "game.h"
#include "png.h"
#include <stdio.h>
#include <stdlib.h>

Image g_tileset;
Sprite g_spr[104];
Image g_tooltips[26];
Image g_tutorial[10];
Image g_win_img;
Sound g_snd_squawk;
Sound g_snd_pickaxe;

#include "sprite_table.inc"

f64 time_now(void) { return platform_time(); }
u64 rdrand64(void) { return platform_random64(); }
u32 rdrand32(void) { return (u32)platform_random64(); }

static void fail(const char *msg, const char *detail) {
    char buf[512];
    int n = snprintf(buf, sizeof buf, "%s%s\n", msg, detail ? detail : "");
    platform_log(buf, (u64)n);
}

// 0x1400101e0: load resources/textures/<name>, swapping R and B so pixels read as 0xAARRGGBB
static b32 load_image(Image *img, const char *name) {
    char path[256];
    snprintf(path, sizeof path, "resources/textures/%s", name);
    u32 size = 0;
    u64 mark = g_scratch.used;
    u8 *data = platform_read_file(path, &size, &g_scratch);
    u32 w = 0, h = 0;
    u8 *rgba = data ? png_decode(data, size, &w, &h) : NULL;
    g_scratch.used = mark;
    if (!rgba) {
        fail("Failed to read image: ", path);
        return 0;
    }
    u8 *px = arena_push(&g_arena, (u64)w * h * 4, 4);
    memcpy(px, rgba, (u64)w * h * 4);
    free(rgba);
    for (u64 i = 0; i < (u64)w * h; i++) {
        u8 t = px[i * 4];
        px[i * 4] = px[i * 4 + 2];
        px[i * 4 + 2] = t;
    }
    img->pixels = (u32 *)px;
    img->w = (i32)w;
    img->h = (i32)h;
    return 1;
}

// 0x14000dd80
b32 assets_load(void) {
    if (!load_image(&g_tileset, "tileset.png")) return 0;
    for (int i = 0; i < 104; i++) {
        Sprite *s = &g_spr[i];
        s->img = &g_tileset;
        s->x = k_sprite_table[i][0];
        s->y = k_sprite_table[i][1];
        s->w = k_sprite_table[i][2];
        s->h = k_sprite_table[i][3];
        s->frames = k_sprite_table[i][4];
        s->unused = 1;
    }
    static const char *k_tooltips[26] = {
        "assembler",  "assembler_big", "bee",        "cam_lens",  "camera",     "chute",    "circuit",
        "conveyor",   "copper_ore",    "copper_wire", "cyber_seagull", "elevator", "feather", "furnace",
        "gear",       "hive",          "hive_big",   "honey",     "iron_ore",   "iron_plate", "landing",
        "pollen",     "power_core",    "seagull",    "splitter",  "uranium",
    };
    for (int i = 0; i < 26; i++) {
        char name[64];
        snprintf(name, sizeof name, "tooltip_%s.png", k_tooltips[i]);
        if (!load_image(&g_tooltips[i], name)) return 0;
    }
    for (int i = 0; i < 9; i++) {
        char name[64];
        snprintf(name, sizeof name, "tutorial_%d.png", i);
        if (!load_image(&g_tutorial[i], name)) return 0;
    }
    if (!load_image(&g_tutorial[9], "controls.png")) return 0;
    if (!load_image(&g_win_img, "win_message.png")) return 0;
    return 1;
}

// 0x14000fd80: 16-bit PCM wav -> mono float samples (first channel) scaled by volume
b32 sound_load(Sound *s, const char *path, f32 volume) {
    memset(s, 0, sizeof *s);
    u32 size = 0;
    u64 mark = g_scratch.used;
    u8 *d = platform_read_file(path, &size, &g_scratch);
    b32 ok = 0;
    const char *err = NULL;
    if (!d) err = "Failed to load audio file: ";
    else if (size < 0x2d) err = "Wav file not big enough: ";
    else if (size != *(u32 *)(d + 4) + 8) err = "Wav length didn't match: ";
    else if (memcmp(d, "RIFF", 4) || memcmp(d + 8, "WAVE", 4)) err = "WAV magic invalid: ";
    else if (memcmp(d + 12, "fmt ", 4)) err = "Fmt chunk id invalid: ";
    else if (*(u32 *)(d + 16) != 16) err = "Format chunk size invalid: ";
    else if (*(u16 *)(d + 20) != 1) err = "Formats other than pcm int unsupported: ";
    else if (*(u16 *)(d + 34) != 16) err = "Must be 16 bit: ";
    else if (memcmp(d + 36, "data", 4)) err = "Data chunk id invalid: ";
    else if (size + 0x14 < *(u32 *)(d + 40)) err = "Not enough audio data in file: ";
    if (err) {
        fail(err, path);
    } else {
        u16 channels = *(u16 *)(d + 22);
        u32 rate = *(u32 *)(d + 24);
        u64 n = channels ? (u64)(*(u32 *)(d + 40) >> 1) / channels : 0;
        if ((u32)n != 0) {
            f32 *out = arena_push(&g_arena, n * 4, 4);
            const i16 *pcm = (const i16 *)(d + 0x2c);
            for (u64 i = 0; i < (u32)n; i++) out[i] = ((f32)(i32)pcm[i * channels] / 32767.0f) * volume;
            s->samples = out;
            s->count = (u32)n;
            s->rate = rate;
            s->duration = (f64)((f32)(i64)n / (f32)rate);
        }
        ok = 1;
    }
    g_scratch.used = mark;
    return ok;
}

// ---------------------------------------------------------------------------
// Mixer (0x140010300 / 0x140007fb0). Voices are kept in an arena array as in
// the original; the audio thread and the game thread share it under a lock.
typedef struct Voice { Sound *sound; f64 start; f32 volume; u32 pad; } Voice;
static DARRAY(Voice) s_voices;   // 0x14002a8a8
static f64 s_audio_time;         // 0x14002a8a0
static u32 s_rate;

// 0x140012a70
void play_sound(Sound *s, f32 volume) {
    platform_audio_lock();
    Voice v = {s, s_audio_time, volume, 0};
    da_push(&s_voices, v, 8);
    platform_audio_unlock();
}

static void mix(f32 *out, u32 frames, u32 channels, f32 dt) {
    memset(out, 0, (u64)frames * channels * 4);
    for (u32 i = 0; i < s_voices.count; i++) {
        Voice *v = &s_voices.data[i];
        if (s_audio_time < v->sound->duration + v->start) {
            for (u32 j = 0; j < frames; j++) {
                Sound *s = v->sound;
                u32 idx = (u32)(u64)(((((f64)j / (f64)frames) * (f64)dt + s_audio_time) - v->start) * (f64)s->rate);
                f32 x = 0.0f;
                // the original scales by 0.5 while its window has focus and by 20 otherwise
                if (idx < s->count) x = s->samples[idx] * v->volume * (platform_has_focus() ? 0.5f : 20.0f);
                f32 *o = out + (u64)j * channels;
                for (u32 c = 0; c < channels; c++) o[c] = x + o[c];
            }
        } else {
            s_voices.count--;
            s_voices.data[i] = s_voices.data[s_voices.count];
            i--;
        }
    }
    for (u64 k = 0; k < (u64)frames * channels; k++) out[k] = sse_min(1.0f, sse_max(-1.0f, out[k]));
}

static void audio_callback(f32 *out, u32 frames, u32 channels, f32 dt) {
    (void)dt;
    f32 d = (f32)frames / (f32)s_rate;
    mix(out, frames, channels, d);
    s_audio_time = (f64)d + s_audio_time;
}

b32 audio_start(void) {
    u32 channels = 0;
    if (!platform_audio_start(audio_callback, &s_rate, &channels)) {
        // no audio device: keep running silently like a game with sound muted
        s_rate = 48000;
    }
    return 1;
}

void audio_stop(void) { platform_audio_stop(); }
