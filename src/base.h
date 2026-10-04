// Basic types, arena allocator and growable arrays.
//
// The original program does all allocation out of large linear arenas and
// keeps "dynamic arrays" that grow inside those arenas (extending in place
// when the array is the most recent allocation, otherwise copying to a new
// block and leaving the old one behind). This port keeps exactly that model
// so pointer lifetimes behave the same way as in the original.
#pragma once
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef float f32;
typedef double f64;
typedef i32 b32;

#define ARRAY_COUNT(a) (sizeof(a) / sizeof((a)[0]))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// The original traps (int3) on failed bounds checks.
void fatal_trap(const char *where);
#define TRAP() fatal_trap(__func__)

typedef struct { i32 x, y; } V2i;
typedef struct { u32 x, y; } V2u;
typedef struct { f32 x, y; } V2;

static inline V2i v2i(i32 x, i32 y) { V2i r = {x, y}; return r; }
static inline V2 v2(f32 x, f32 y) { V2 r = {x, y}; return r; }

// minss/maxss semantics (operand order matters for NaN; kept identical)
static inline f32 sse_min(f32 a, f32 b) { return a < b ? a : b; }
static inline f32 sse_max(f32 a, f32 b) { return a > b ? a : b; }

// ---------------------------------------------------------------------------
// Strings are (pointer, length) pairs, not NUL terminated.
typedef struct { const char *data; u64 len; } Str;
#define S(lit) ((Str){(lit), sizeof(lit) - 1})

// ---------------------------------------------------------------------------
typedef struct Arena {
    u8 *base;
    u64 size;
    u64 used;
} Arena;

b32 arena_init(Arena *a, u64 size);
static inline void *arena_push(Arena *a, u64 size, u64 align) {
    a->used = (a->used + align - 1) & ~(align - 1);
    void *p = a->base + a->used;
    a->used += size;
    return p;
}

extern Arena g_arena;        // 0x140029878: main, never reset
extern Arena g_scratch;      // 0x140029818: temp, used with save/restore
extern Arena g_scratch2;     // 0x140029830
extern Arena g_frame_arena;  // 0x140029848: swapped with the previous frame's each frame
extern Arena g_frame_prev;   // 0x140029860

// Growable array header: {Arena*, data, count, cap}. A NULL arena means g_arena.
#define DARRAY(T) struct { Arena *arena; T *data; u32 count; u32 cap; }

void da_grow_(void *arr, u64 elem_size, u64 align);
// Make room for one more element (same growth policy as the original:
// cap = max(8, cap*2), grown in place when the block is the arena's last).
#define da_reserve_one(arr, align) \
    do { if ((arr)->count == (arr)->cap) da_grow_((arr), sizeof(*(arr)->data), (align)); } while (0)
#define da_push(arr, value, align) \
    do { da_reserve_one(arr, align); (arr)->data[(arr)->count++] = (value); } while (0)
// Set the element count, growing the block to exactly `count` if needed (new elements zeroed)
void da_resize_(void *arr, u32 count, u64 elem_size, u64 align);
#define da_resize(arr, n, align) da_resize_((arr), (n), sizeof(*(arr)->data), (align))
