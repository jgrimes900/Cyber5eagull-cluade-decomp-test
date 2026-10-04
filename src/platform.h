// Platform layer interface. The original talked to Win32/GDI/WASAPI directly;
// this port routes the same operations through platform_sdl.c.
#pragma once
#include "base.h"

typedef void (*KeyCallback)(u32 vk, b32 down);
typedef void (*MouseCallback)(i32 button, b32 down, f32 wheel);  // button 0 = wheel
typedef void (*AudioCallback)(f32 *out, u32 frames, u32 channels, f32 dt);

// Windows virtual-key codes used by the game
enum {
    VK_BACK = 0x08, VK_TAB = 0x09, VK_RETURN = 0x0d, VK_SHIFT = 0x10, VK_CONTROL = 0x11, VK_MENU = 0x12,
    VK_CAPITAL = 0x14, VK_ESCAPE = 0x1b,
    VK_SPACE = 0x20, VK_LEFT = 0x25, VK_UP = 0x26, VK_RIGHT = 0x27, VK_DOWN = 0x28, VK_DELETE = 0x2e,
};

extern u32 *g_backbuffer;        // 0x1400296c8 (0xAARRGGBB, top-down)
extern i32 g_bb_w, g_bb_h;        // 0x1400296d0
extern u8 g_key_down[256];        // 0x140029700, indexed by virtual-key code
extern u8 g_mouse_down[6];        // 0x140029800 (index 1..5)
extern b32 g_quit;                // 0x1400296d8

b32 platform_init(const char *title, i32 w, i32 h, KeyCallback key, MouseCallback mouse);
void platform_shutdown(void);
void platform_pump_events(void);  // dispatches key/mouse callbacks
V2i platform_mouse_pos(void);     // client coordinates
void platform_present(void);      // shows g_backbuffer
f64 platform_time(void);          // seconds (QueryPerformanceCounter / frequency)
b32 platform_has_focus(void);
u64 platform_random64(void);      // stands in for RDRAND

b32 platform_audio_start(AudioCallback cb, u32 *sample_rate, u32 *channels);
void platform_audio_stop(void);
void platform_audio_lock(void);
void platform_audio_unlock(void);

void *platform_read_file(const char *path, u32 *size, Arena *arena);
void platform_log(const char *msg, u64 len);
