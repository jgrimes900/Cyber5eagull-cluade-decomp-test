// Arena allocator and growable arrays (see base.h).
#include "base.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

Arena g_arena;
Arena g_scratch;
Arena g_scratch2;
Arena g_frame_arena;
Arena g_frame_prev;

// The original reserves the address space up front with VirtualAlloc and
// lets pages commit on first touch; an anonymous no-reserve mapping does the same.
b32 arena_init(Arena *a, u64 size) {
    void *p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE, -1, 0);
    if (p == MAP_FAILED) return 0;
    a->base = p;
    a->size = size;
    a->used = 0;
    return 1;
}

void fatal_trap(const char *where) {
    fprintf(stderr, "Cyber5eagull: internal check failed in %s\n", where);
    fflush(stderr);
    abort();
}

typedef DARRAY(u8) AnyArray;

static void da_set_cap(AnyArray *a, u32 new_cap, u64 elem, u64 align) {
    Arena *ar = a->arena ? a->arena : &g_arena;
    u64 old_bytes = (u64)a->cap * elem;
    if (a->data && a->data + old_bytes == ar->base + ar->used) {
        ar->used += (u64)(new_cap - a->cap) * elem;
    } else {
        ar->used = (ar->used + align - 1) & ~(align - 1);
        u8 *p = ar->base + ar->used;
        if (a->data) memcpy(p, a->data, old_bytes);
        ar->used += (u64)new_cap * elem;
        a->data = p;
    }
    a->cap = new_cap;
}

void da_grow_(void *arr, u64 elem, u64 align) {
    AnyArray *a = arr;
    u32 n = a->cap * 2;
    if (n < 8) n = 8;
    if (a->cap < n) da_set_cap(a, n, elem, align);
}

void da_resize_(void *arr, u32 count, u64 elem, u64 align) {
    AnyArray *a = arr;
    if (a->cap < count) da_set_cap(a, count, elem, align);
    if (count > a->count) memset(a->data + (u64)a->count * elem, 0, (u64)(count - a->count) * elem);
    a->count = count;
}
