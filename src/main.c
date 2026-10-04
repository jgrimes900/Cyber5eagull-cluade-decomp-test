// Program entry (0x14001fe50 + the window setup part of 0x14001a8f0).
#include "game.h"
#include <stdio.h>
#include <xmmintrin.h>

static b32 arena_init_any(Arena *a, u64 size) {
    // the original reserves 1 GiB per scratch arena and 64 GiB for the main one;
    // fall back to smaller reservations on systems with strict overcommit
    for (; size >= ((u64)1 << 28); size >>= 1)
        if (arena_init(a, size)) return 1;
    return 0;
}

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    if (!arena_init_any(&g_scratch, (u64)1 << 30) || !arena_init_any(&g_scratch2, (u64)1 << 30) ||
        !arena_init_any(&g_frame_arena, (u64)1 << 30) || !arena_init_any(&g_frame_prev, (u64)1 << 30) ||
        !arena_init_any(&g_arena, (u64)64 << 30)) {
        fprintf(stderr, "Cyber5eagull: could not reserve memory\n");
        return 2;
    }
    // flush-to-zero and denormals-are-zero, as the original sets in MXCSR
    _mm_setcsr(_mm_getcsr() | 0x8000 | 0x40);
    if (!platform_init("Cyber5eagull", 960, 540, on_key, on_mouse)) {
        fprintf(stderr, "Window init failed\n");
        return 1;
    }
    if (!game_init()) {
        platform_shutdown();
        return 1;
    }
    while (!g_quit) game_frame();
    audio_stop();
    platform_shutdown();
    return 0;
}
