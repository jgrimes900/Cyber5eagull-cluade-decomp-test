// SDL2 implementation of the platform layer. Stands in for the original's
// Win32 window + GDI DIB section, raw-input mouse, keyboard messages and the
// WASAPI audio thread.
//
// Setting CYBERSEAGULL_SCRIPT=<file> runs a deterministic headless test mode
// instead: input comes from the script (see test_script.h), the clock advances
// exactly 1/60 s per frame, "RDRAND" is a fixed splitmix64 sequence, and frames
// marked with D are written to CYBERSEAGULL_OUT as raw dumps. The same scripts
// drive tools/oracle, which runs the original executable, so the two can be
// compared frame by frame.
#include "platform.h"
#include "test_script.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

u32 *g_backbuffer;
i32 g_bb_w, g_bb_h;
u8 g_key_down[256];
u8 g_mouse_down[6];
b32 g_quit;
extern V2i g_raw_mouse_delta;

static KeyCallback s_key_cb;
static MouseCallback s_mouse_cb;
static SDL_Window *s_window;
static SDL_Renderer *s_renderer;
static SDL_Texture *s_texture;
static SDL_AudioDeviceID s_audio_dev;
static AudioCallback s_audio_cb;
static u32 s_audio_channels;
static volatile int s_focused = 1;
static u64 s_perf_freq;

// test mode
static b32 s_test;
static Script *s_script;
static const char *s_out_dir;
static int s_frame;
static u64 s_qpc;
static u64 s_rand_state = 0x1234567887654321ull;
static V2i s_cursor;
#define TEST_QPC_FREQ 10000000ull

static void alloc_backbuffer(i32 w, i32 h) {
    free(g_backbuffer);
    g_bb_w = w;
    g_bb_h = h;
    g_backbuffer = calloc((size_t)(w > 0 ? w : 1) * (h > 0 ? h : 1), 4);
    if (s_renderer) {
        if (s_texture) SDL_DestroyTexture(s_texture);
        s_texture = SDL_CreateTexture(s_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
    }
}

b32 platform_init(const char *title, i32 w, i32 h, KeyCallback key, MouseCallback mouse) {
    s_key_cb = key;
    s_mouse_cb = mouse;
    const char *script = getenv("CYBERSEAGULL_SCRIPT");
    if (script) {
        s_test = 1;
        s_script = calloc(1, sizeof *s_script);
        script_load(s_script, script);
        s_out_dir = getenv("CYBERSEAGULL_OUT");
        if (!s_out_dir) s_out_dir = ".";
        if (s_script->dir[0] && chdir(s_script->dir) != 0) perror("chdir");
        alloc_backbuffer(w, h);
        return 1;
    }
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0) {
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return 0;
    }
    s_perf_freq = SDL_GetPerformanceFrequency();
    s_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_RESIZABLE);
    if (!s_window) return 0;
    SDL_Surface *icon = NULL;
    (void)icon;
    s_renderer = SDL_CreateRenderer(s_window, -1, SDL_RENDERER_ACCELERATED);
    if (!s_renderer) s_renderer = SDL_CreateRenderer(s_window, -1, SDL_RENDERER_SOFTWARE);
    if (!s_renderer) return 0;
    SDL_GetWindowSize(s_window, &w, &h);
    alloc_backbuffer(w, h);
    SDL_ShowWindow(s_window);
    return 1;
}

void platform_shutdown(void) {
    if (s_test) return;
    platform_audio_stop();
    if (s_texture) SDL_DestroyTexture(s_texture);
    if (s_renderer) SDL_DestroyRenderer(s_renderer);
    if (s_window) SDL_DestroyWindow(s_window);
    SDL_Quit();
}

// SDL key -> Windows virtual-key code
static u32 vk_from_sdl(SDL_Keycode k) {
    if (k >= SDLK_a && k <= SDLK_z) return (u32)('A' + (k - SDLK_a));
    if (k >= SDLK_0 && k <= SDLK_9) return (u32)('0' + (k - SDLK_0));
    if (k >= SDLK_F1 && k <= SDLK_F12) return 0x70 + (u32)(k - SDLK_F1);
    if (k >= SDLK_KP_1 && k <= SDLK_KP_9) return 0x61 + (u32)(k - SDLK_KP_1);
    switch (k) {
    case SDLK_KP_0: return 0x60;
    case SDLK_BACKSPACE: return VK_BACK;
    case SDLK_TAB: return VK_TAB;
    case SDLK_RETURN: case SDLK_KP_ENTER: return VK_RETURN;
    case SDLK_LSHIFT: case SDLK_RSHIFT: return VK_SHIFT;
    case SDLK_LCTRL: case SDLK_RCTRL: return VK_CONTROL;
    case SDLK_CAPSLOCK: return VK_CAPITAL;
    case SDLK_ESCAPE: return VK_ESCAPE;
    case SDLK_SPACE: return VK_SPACE;
    case SDLK_PAGEUP: return 0x21;
    case SDLK_PAGEDOWN: return 0x22;
    case SDLK_END: return 0x23;
    case SDLK_HOME: return 0x24;
    case SDLK_LEFT: return VK_LEFT;
    case SDLK_UP: return VK_UP;
    case SDLK_RIGHT: return VK_RIGHT;
    case SDLK_DOWN: return VK_DOWN;
    case SDLK_INSERT: return 0x2d;
    case SDLK_DELETE: return VK_DELETE;
    case SDLK_SEMICOLON: return 0xba;
    case SDLK_EQUALS: case SDLK_PLUS: return 0xbb;
    case SDLK_COMMA: return 0xbc;
    case SDLK_MINUS: return 0xbd;
    case SDLK_PERIOD: return 0xbe;
    case SDLK_SLASH: return 0xbf;
    case SDLK_BACKQUOTE: return 0xc0;
    case SDLK_LEFTBRACKET: return 0xdb;
    case SDLK_BACKSLASH: return 0xdc;
    case SDLK_RIGHTBRACKET: return 0xdd;
    case SDLK_QUOTE: return 0xde;
    case SDLK_KP_MINUS: return 0x6d;
    case SDLK_KP_PLUS: return 0x6b;
    default: return 0x100;  // ignored (the original drops codes > 0xfe)
    }
}

static void key_event(u32 vk, b32 down) {
    if (vk > 0xfe) return;
    g_key_down[vk] = (u8)(down != 0);
    if (s_key_cb) s_key_cb(vk, down);
}

static void button_event(i32 b, b32 down) {
    if (b < 1 || b > 5) return;
    g_mouse_down[b] = (u8)(down != 0);
    if (s_mouse_cb) s_mouse_cb(b, down, 0.0f);
}

static void pump_script(void) {
    for (int i = 0; i < s_script->n; i++) {
        ScriptEv *e = &s_script->ev[i];
        if (e->frame != s_frame) continue;
        switch (e->type) {
        case 'M': s_cursor = (V2i){e->a, e->b}; break;
        case 'K': key_event((u32)e->a, e->b != 0); break;
        case 'B': if (e->a >= 1 && e->a <= 3) button_event(e->a, e->b != 0); break;
        case 'W': if (s_mouse_cb) s_mouse_cb(0, 0, (f32)(i16)e->a); break;
        case 'Q': g_quit = 1; break;
        }
    }
}

void platform_pump_events(void) {
    if (s_test) {
        pump_script();
        return;
    }
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
        switch (ev.type) {
        case SDL_QUIT:
            g_quit = 1;
            break;
        case SDL_WINDOWEVENT:
            if (ev.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) alloc_backbuffer(ev.window.data1, ev.window.data2);
            else if (ev.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) s_focused = 1;
            else if (ev.window.event == SDL_WINDOWEVENT_FOCUS_LOST) s_focused = 0;
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            key_event(vk_from_sdl(ev.key.keysym.sym), ev.type == SDL_KEYDOWN);
            break;
        case SDL_MOUSEMOTION:
            if (s_focused) {
                g_raw_mouse_delta.x += ev.motion.xrel;
                g_raw_mouse_delta.y += ev.motion.yrel;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP: {
            if (!s_focused) break;
            i32 b = 0;
            switch (ev.button.button) {
            case SDL_BUTTON_LEFT: b = 1; break;
            case SDL_BUTTON_RIGHT: b = 2; break;
            case SDL_BUTTON_MIDDLE: b = 3; break;
            case SDL_BUTTON_X1: b = 4; break;
            case SDL_BUTTON_X2: b = 5; break;
            }
            button_event(b, ev.type == SDL_MOUSEBUTTONDOWN);
            break;
        }
        case SDL_MOUSEWHEEL:
            if (s_focused && ev.wheel.y && s_mouse_cb) {
                i32 dy = ev.wheel.direction == SDL_MOUSEWHEEL_FLIPPED ? -ev.wheel.y : ev.wheel.y;
                s_mouse_cb(0, 0, (f32)(dy * 120));  // WHEEL_DELTA units, like raw input
            }
            break;
        }
    }
}

V2i platform_mouse_pos(void) {
    if (s_test) return s_cursor;
    // GetCursorPos + ScreenToClient: valid even when the cursor is outside the window
    int gx, gy, wx, wy;
    SDL_GetGlobalMouseState(&gx, &gy);
    SDL_GetWindowPosition(s_window, &wx, &wy);
    return (V2i){gx - wx, gy - wy};
}

static void dump_frame(void) {
    char p[512];
    snprintf(p, sizeof p, "%s/frame_%05d.raw", s_out_dir, s_frame);
    FILE *f = fopen(p, "wb");
    if (!f) return;
    i32 hdr[2] = {g_bb_w, g_bb_h};
    fwrite(hdr, 4, 2, f);
    fwrite(g_backbuffer, 4, (size_t)g_bb_w * g_bb_h, f);
    fclose(f);
}

void platform_present(void) {
    if (s_test) {
        if (script_frame_has(s_script, s_frame, 'D')) dump_frame();
        s_frame++;
        s_qpc += TEST_QPC_FREQ / 60;
        return;
    }
    SDL_UpdateTexture(s_texture, NULL, g_backbuffer, g_bb_w * 4);
    SDL_RenderClear(s_renderer);
    SDL_RenderCopy(s_renderer, s_texture, NULL, NULL);
    SDL_RenderPresent(s_renderer);
}

f64 platform_time(void) {
    if (s_test) return (f64)(i64)s_qpc / (f64)(i64)TEST_QPC_FREQ;
    return (f64)(i64)SDL_GetPerformanceCounter() / (f64)(i64)s_perf_freq;
}

b32 platform_has_focus(void) { return s_test ? 1 : s_focused; }

u64 platform_random64(void) {
    if (s_test) return script_rand(&s_rand_state);
    u64 v = 0;
    // RDRAND is what the original used; fall back to the OS generator
    if (getentropy(&v, sizeof v) != 0) v = SDL_GetPerformanceCounter() * 0x9e3779b97f4a7c15ull;
    return v;
}

static void sdl_audio_cb(void *user, Uint8 *stream, int len) {
    (void)user;
    u32 frames = (u32)len / (4 * s_audio_channels);
    if (s_audio_cb) s_audio_cb((f32 *)stream, frames, s_audio_channels, 0.0f);
    else memset(stream, 0, (size_t)len);
}

b32 platform_audio_start(AudioCallback cb, u32 *sample_rate, u32 *channels) {
    if (s_test) return 0;
    SDL_AudioSpec want, have;
    SDL_zero(want);
    want.freq = 48000;
    want.format = AUDIO_F32SYS;
    want.channels = 2;
    want.samples = 512;
    want.callback = sdl_audio_cb;
    s_audio_cb = cb;
    s_audio_dev = SDL_OpenAudioDevice(NULL, 0, &want, &have, SDL_AUDIO_ALLOW_FREQUENCY_CHANGE | SDL_AUDIO_ALLOW_CHANNELS_CHANGE);
    if (!s_audio_dev) {
        fprintf(stderr, "Audio disabled: %s\n", SDL_GetError());
        return 0;
    }
    s_audio_channels = have.channels;
    *sample_rate = (u32)have.freq;
    *channels = have.channels;
    SDL_PauseAudioDevice(s_audio_dev, 0);
    return 1;
}

void platform_audio_stop(void) {
    if (s_audio_dev) SDL_CloseAudioDevice(s_audio_dev);
    s_audio_dev = 0;
}

void platform_audio_lock(void) {
    if (s_audio_dev) SDL_LockAudioDevice(s_audio_dev);
}

void platform_audio_unlock(void) {
    if (s_audio_dev) SDL_UnlockAudioDevice(s_audio_dev);
}

void *platform_read_file(const char *path, u32 *size, Arena *arena) {
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    long n = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (n < 0) {
        fclose(f);
        return NULL;
    }
    u8 *p = arena_push(arena, (u64)n + 1, 8);
    if (fread(p, 1, (size_t)n, f) != (size_t)n) {
        fclose(f);
        return NULL;
    }
    fclose(f);
    p[n] = 0;
    *size = (u32)n;
    return p;
}

void platform_log(const char *msg, u64 len) {
    fwrite(msg, 1, len, stderr);
    fflush(stderr);
}
