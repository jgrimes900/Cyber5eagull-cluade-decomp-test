// Tiny input-script format shared by the reference harness and the port's test mode.
//   C <dir>          chdir before starting (where resources/ lives)
//   <frame> M x y    cursor position (client coords)
//   <frame> K vk d   key down (d=1) / up (d=0), Windows virtual-key code
//   <frame> B b d    mouse button b (1=left 2=right 3=middle) down/up
//   <frame> W delta  mouse wheel
//   <frame> D        dump framebuffer after this frame is drawn
//   <frame> Q        close window
#pragma once
#include <stdio.h>
#include <stdint.h>
#include <string.h>
typedef struct { int frame; char type; int a, b; } ScriptEv;
typedef struct { ScriptEv ev[100000]; int n; char dir[256]; } Script;
static inline void script_load(Script *s, const char *path) {
    FILE *f = fopen(path, "r"); char line[512]; s->n = 0; s->dir[0] = 0;
    if (!f) { perror(path); return; }
    while (fgets(line, sizeof line, f)) {
        if (line[0] == 'C') { sscanf(line + 2, "%255s", s->dir); continue; }
        ScriptEv e = {0}; char t;
        int k = sscanf(line, "%d %c %d %d", &e.frame, &t, &e.a, &e.b);
        if (k >= 2) { e.type = t; s->ev[s->n++] = e; }
    }
    fclose(f);
}
static inline int script_frame_has(Script *s, int frame, char type) {
    for (int i = 0; i < s->n; i++) if (s->ev[i].frame == frame && s->ev[i].type == type) return 1;
    return 0;
}
// splitmix64: stands in for RDRAND so runs are reproducible
static inline uint64_t script_rand(uint64_t *x) {
    uint64_t z = (*x += 0x9e3779b97f4a7c15ull);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ull; z = (z ^ (z >> 27)) * 0x94d049bb133111ebull;
    return z ^ (z >> 31);
}
