// Reference harness: maps the original CyberSeagull5.exe and runs its x64 code
// natively on Linux with headless Win32 stand-ins. Used only to compare the
// decompiled port's output against the original program.
//
// usage: pe_oracle game.exe script.txt outdir
#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <ucontext.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include "script.h"

#define WINAPI __attribute__((ms_abi))
typedef uint64_t u64; typedef uint32_t u32; typedef int32_t i32; typedef uint16_t u16; typedef uint8_t u8;

static u8 *image;
static const char *outdir;
static Script script;
static int frame;
static u64 qpc_now;
static const u64 QPC_FREQ = 10000000;
static void *wndproc;
static int client_w = 960, client_h = 540;
static u32 *dib_pixels; static int dib_w, dib_h;
static int quit_posted;
static int cursor_x = 480, cursor_y = 270;

typedef struct { u64 hwnd; u32 message; u32 pad; u64 wparam; u64 lparam; u32 time; i32 ptx, pty; u32 priv; } MSG_;
#define QMAX 256
static MSG_ queue[QMAX]; static int qhead, qtail;
static void post(u32 m, u64 w, u64 l) { MSG_ *x = &queue[qtail++ % QMAX]; memset(x, 0, sizeof *x); x->hwnd = 0x1000; x->message = m; x->wparam = w; x->lparam = l; }
// raw mouse events are passed by handle index
typedef struct { u16 flags; u16 data; } RawEv;
static RawEv rawevs[1024]; static int rawn;

typedef u64 (WINAPI *WndProc)(u64, u32, u64, u64);

// ---- rdrand replacement (deterministic, shared with port's test mode) ----
static u64 rng_state = 0x1234567887654321ull;
static u64 next_rand(void) { return script_rand(&rng_state); }
static u64 rdrand_sites[16]; static int rdrand_regs[16]; static int n_rdrand;

static void on_trap(int sig, siginfo_t *si, void *uc_) {
    (void)sig; (void)si;
    ucontext_t *uc = uc_;
    u64 rip = uc->uc_mcontext.gregs[REG_RIP] - 1;
    for (int i = 0; i < n_rdrand; i++) if (rdrand_sites[i] == rip) {
        u64 v = next_rand();
        if (rdrand_regs[i] == 0) uc->uc_mcontext.gregs[REG_RAX] = v;
        else uc->uc_mcontext.gregs[REG_R8] = (u32)v;
        uc->uc_mcontext.gregs[REG_EFL] |= 1; // CF
        uc->uc_mcontext.gregs[REG_RIP] = rip + 4;
        return;
    }
    fprintf(stderr, "unexpected trap at %lx\n", (unsigned long)rip); _exit(3);
}
static void on_segv(int sig, siginfo_t *si, void *uc_) {
    ucontext_t *uc = uc_;
    fprintf(stderr, "signal %d at rip=%llx addr=%p frame=%d\n", sig, (unsigned long long)uc->uc_mcontext.gregs[REG_RIP], si->si_addr, frame);
    _exit(4);
}

// ---------------- KERNEL32 ----------------
static u32 WINAPI k_GetLastError(void) { return 0; }
static u64 WINAPI k_AddVectoredExceptionHandler(u32 a, void *b) { (void)a; (void)b; return 1; }
static i32 WINAPI k_QueryPerformanceCounter(u64 *p) { *p = qpc_now; return 1; }
static i32 WINAPI k_QueryPerformanceFrequency(u64 *p) { *p = QPC_FREQ; return 1; }
static void *WINAPI k_HeapAlloc(u64 h, u32 f, u64 n) { (void)h; (void)f; return calloc(1, n); }
static u64 WINAPI k_GetProcessHeap(void) { return 1; }
static u32 WINAPI k_WaitForSingleObject(u64 h, u32 ms) { (void)h; (void)ms; return 0; }
static i32 WINAPI k_SetWaitableTimer(void) { return 1; }
static void WINAPI k_Sleep(u32 ms) { (void)ms; }
static void WINAPI k_ExitProcess(u32 c) { fprintf(stderr, "ExitProcess(%u)\n", c); exit(c); }
static u64 WINAPI k_CreateThread(void *a, u64 b, void *fn, void *p, u32 f, u32 *id) { (void)a; (void)b; (void)fn; (void)p; (void)f; if (id) *id = 1; return 0x2000; }
static void WINAPI k_GetSystemTimeAsFileTime(u64 *p) { *p = 0; }
static i32 WINAPI k_WriteFile(u64 h, const void *buf, u32 n, u32 *w, void *ov) {
    (void)ov;
    if (h == 0x3000) { fwrite(buf, 1, n, stderr); if (w) *w = n; return 1; }
    ssize_t r = write((int)h - 0x4000, buf, n); if (w) *w = (u32)r; return r >= 0;
}
static u64 WINAPI k_GetModuleHandleA(const char *n) { (void)n; return 0x140000000ull; }
static void *WINAPI k_GetProcAddress(u64 m, const char *n) { (void)m; fprintf(stderr, "GetProcAddress(%s)\n", n); return 0; }
static u64 WINAPI k_LoadLibraryA(const char *n) { fprintf(stderr, "LoadLibraryA(%s)\n", n); return 0; }
static u32 WINAPI k_FormatMessageA(void) { return 0; }
static u64 WINAPI k_CreateWaitableTimerA(void) { return 0x2001; }
static u64 WINAPI k_CreateFileA(const char *name, u32 access, u32 share, void *sa, u32 disp, u32 flags, u64 tmpl) {
    (void)share; (void)sa; (void)flags; (void)tmpl;
    if (!strcmp(name, "CON")) return 0x3000;
    int fd = open(name, (access & 0x40000000) ? (O_WRONLY | (disp == 2 ? O_CREAT | O_TRUNC : 0)) : O_RDONLY, 0644);
    if (fd < 0) { fprintf(stderr, "CreateFileA failed: %s\n", name); return (u64)-1; }
    return 0x4000 + fd;
}
static u32 WINAPI k_GetFileSize(u64 h, u32 *hi) { if (hi) *hi = 0; off_t cur = lseek((int)h - 0x4000, 0, SEEK_CUR); off_t e = lseek((int)h - 0x4000, 0, SEEK_END); lseek((int)h - 0x4000, cur, SEEK_SET); return (u32)e; }
static i32 WINAPI k_ReadFile(u64 h, void *buf, u32 n, u32 *rd, void *ov) { (void)ov; ssize_t r = read((int)h - 0x4000, buf, n); if (rd) *rd = r < 0 ? 0 : (u32)r; return r >= 0; }
static i32 WINAPI k_CloseHandle(u64 h) { if (h >= 0x4000) close((int)h - 0x4000); return 1; }
static void *WINAPI k_VirtualAlloc(void *addr, u64 size, u32 type, u32 prot) {
    (void)addr; (void)type; (void)prot;
    void *p = mmap(0, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE, -1, 0);
    return p == MAP_FAILED ? 0 : p;
}

// ---------------- USER32 ----------------
typedef struct { i32 x, y; } POINT_;
static i32 WINAPI u_GetCursorPos(POINT_ *p) { p->x = cursor_x; p->y = cursor_y; return 1; }
static i32 WINAPI u_ScreenToClient(u64 h, POINT_ *p) { (void)h; (void)p; return 1; }
static u64 WINAPI u_LoadImageA(void) { return 0; }
static i32 WINAPI u_SetProcessDPIAware(void) { return 1; }
static u32 WINAPI u_GetRawInputData(u64 hraw, u32 cmd, void *data, u32 *size, u32 hdr) {
    (void)cmd; (void)hdr;
    if (!data) { *size = 48; return 0; }
    u8 *d = data; memset(d, 0, 48);
    RawEv *e = &rawevs[hraw & 1023];
    *(u32 *)(d + 0) = 0; *(u32 *)(d + 4) = 48;
    *(u16 *)(d + 24) = 0; // MOUSE_MOVE_RELATIVE
    *(u16 *)(d + 28) = e->flags; *(u16 *)(d + 30) = e->data;
    return 48;
}
static i32 WINAPI u_RegisterRawInputDevices(void) { return 1; }
static i32 WINAPI u_InvalidateRect(void) { return 1; }
static i32 WINAPI u_EndPaint(void) { return 1; }
static u64 WINAPI u_BeginPaint(u64 h, void *ps) { (void)h; memset(ps, 0, 72); return 0x5000; }
static i32 WINAPI u_ReleaseDC(void) { return 1; }
static u64 WINAPI u_GetDC(void) { return 0x5000; }
static u64 WINAPI u_GetForegroundWindow(void) { return 0x1000; }
static void dump_frame(void);
static i32 WINAPI u_UpdateWindow(u64 h) {
    (void)h;
    if (script_frame_has(&script, frame, 'D')) dump_frame();
    if (frame == 0 && getenv("ORACLE_MEMDUMP")) {
        FILE *mf = fopen(getenv("ORACLE_MEMDUMP"), "wb");
        if (mf) { fwrite((void *)0x140029000, 1, 0x1c3000 - 0x29000, mf); fclose(mf); }
    }
    frame++;
    qpc_now += QPC_FREQ / 60;
    return 1;
}
static i32 WINAPI u_GetClientRect(u64 h, i32 *r) { (void)h; r[0] = 0; r[1] = 0; r[2] = client_w; r[3] = client_h; return 1; }
static i32 WINAPI u_TranslateMessage(void) { return 1; }
static u64 WINAPI u_DispatchMessageA(MSG_ *m) { return ((WndProc)wndproc)(m->hwnd, m->message, m->wparam, m->lparam); }
static int last_injected_frame = -1;
static void inject(void) {
    if (last_injected_frame == frame) return;
    last_injected_frame = frame;
    for (int i = 0; i < script.n; i++) {
        ScriptEv *e = &script.ev[i];
        if (e->frame != frame) continue;
        switch (e->type) {
        case 'M': cursor_x = e->a; cursor_y = e->b; break;
        case 'K': post(e->b ? 0x100 : 0x101, e->a, 0); break;
        case 'B': { static const u16 dn[] = {0, 1, 4, 16}, up[] = {0, 2, 8, 32};
                    RawEv *r = &rawevs[rawn & 1023]; r->flags = e->b ? dn[e->a] : up[e->a]; r->data = 0; post(0xff, 0, rawn & 1023); rawn++; } break;
        case 'W': { RawEv *r = &rawevs[rawn & 1023]; r->flags = 0x400; r->data = (u16)(int16_t)e->a; post(0xff, 0, rawn & 1023); rawn++; } break;
        case 'Q': post(0x10, 0, 0); break;
        }
    }
}
static i32 WINAPI u_PeekMessageA(MSG_ *m, u64 h, u32 a, u32 b, u32 rm) {
    (void)h; (void)a; (void)b; (void)rm;
    inject();
    if (qhead == qtail) return 0;
    *m = queue[qhead++ % QMAX];
    return 1;
}
static u64 WINAPI u_DefWindowProcA(void) { return 0; }
static void WINAPI u_PostQuitMessage(i32 c) { (void)c; quit_posted = 1; }
static u16 WINAPI u_RegisterClassExA(u8 *wc) { wndproc = *(void **)(wc + 8); return 1; }
static u64 WINAPI u_CreateWindowExA(void) { return 0x1000; }
static i32 WINAPI u_DestroyWindow(void) { return 1; }
static i32 WINAPI u_ShowWindow(u64 h, i32 c) {
    (void)c;
    ((WndProc)wndproc)(h, 5, 0, (u64)((client_h << 16) | client_w));
    return 0;
}
static i32 WINAPI u_GetSystemMetrics(i32 i) { return i == 0 ? 1920 : i == 1 ? 1080 : 0; }

// ---------------- GDI32 ----------------
static i32 WINAPI g_BitBlt(void) { return 1; }
static i32 WINAPI g_DeleteObject(void) { return 1; }
static u64 WINAPI g_SelectObject(void) { return 1; }
static u64 WINAPI g_CreateDIBSection(u64 dc, i32 *bmi, u32 usage, void **bits, u64 sec, u32 off) {
    (void)dc; (void)usage; (void)sec; (void)off;
    dib_w = bmi[1]; dib_h = bmi[2] < 0 ? -bmi[2] : bmi[2];
    free(dib_pixels); dib_pixels = calloc((size_t)dib_w * dib_h, 4);
    *bits = dib_pixels; return 0x6000;
}
static u64 WINAPI g_CreateCompatibleDC(void) { return 0x5001; }
static u32 WINAPI w_timePeriod(void) { return 0; }

static void dump_frame(void) {
    char p[512]; snprintf(p, sizeof p, "%s/frame_%05d.raw", outdir, frame);
    FILE *f = fopen(p, "wb"); if (!f) return;
    i32 hdr[2] = {dib_w, dib_h}; fwrite(hdr, 4, 2, f);
    fwrite(dib_pixels, 4, (size_t)dib_w * dib_h, f); fclose(f);
}

static void WINAPI unknown_import(void) { fprintf(stderr, "unimplemented import called\n"); _exit(5); }

static struct { const char *name; void *fn; } shims[] = {
#define S(n, f) {n, (void *)f}
    S("GetLastError", k_GetLastError), S("AddVectoredExceptionHandler", k_AddVectoredExceptionHandler),
    S("QueryPerformanceCounter", k_QueryPerformanceCounter), S("QueryPerformanceFrequency", k_QueryPerformanceFrequency),
    S("HeapAlloc", k_HeapAlloc), S("GetProcessHeap", k_GetProcessHeap), S("WaitForSingleObject", k_WaitForSingleObject),
    S("SetWaitableTimer", k_SetWaitableTimer), S("Sleep", k_Sleep), S("ExitProcess", k_ExitProcess),
    S("CreateThread", k_CreateThread), S("GetSystemTimeAsFileTime", k_GetSystemTimeAsFileTime), S("WriteFile", k_WriteFile),
    S("GetModuleHandleA", k_GetModuleHandleA), S("GetProcAddress", k_GetProcAddress), S("LoadLibraryA", k_LoadLibraryA),
    S("FormatMessageA", k_FormatMessageA), S("CreateWaitableTimerA", k_CreateWaitableTimerA), S("CreateFileA", k_CreateFileA),
    S("GetFileSize", k_GetFileSize), S("ReadFile", k_ReadFile), S("CloseHandle", k_CloseHandle), S("VirtualAlloc", k_VirtualAlloc),
    S("GetCursorPos", u_GetCursorPos), S("ScreenToClient", u_ScreenToClient), S("LoadImageA", u_LoadImageA),
    S("SetProcessDPIAware", u_SetProcessDPIAware), S("GetRawInputData", u_GetRawInputData), S("RegisterRawInputDevices", u_RegisterRawInputDevices),
    S("InvalidateRect", u_InvalidateRect), S("EndPaint", u_EndPaint), S("BeginPaint", u_BeginPaint), S("ReleaseDC", u_ReleaseDC),
    S("GetDC", u_GetDC), S("GetForegroundWindow", u_GetForegroundWindow), S("UpdateWindow", u_UpdateWindow), S("GetClientRect", u_GetClientRect),
    S("TranslateMessage", u_TranslateMessage), S("DispatchMessageA", u_DispatchMessageA), S("PeekMessageA", u_PeekMessageA),
    S("DefWindowProcA", u_DefWindowProcA), S("PostQuitMessage", u_PostQuitMessage), S("RegisterClassExA", u_RegisterClassExA),
    S("CreateWindowExA", u_CreateWindowExA), S("DestroyWindow", u_DestroyWindow), S("ShowWindow", u_ShowWindow),
    S("GetSystemMetrics", u_GetSystemMetrics), S("BitBlt", g_BitBlt), S("DeleteObject", g_DeleteObject), S("SelectObject", g_SelectObject),
    S("CreateDIBSection", g_CreateDIBSection), S("CreateCompatibleDC", g_CreateCompatibleDC),
    S("timeBeginPeriod", w_timePeriod), S("timeEndPeriod", w_timePeriod),
};

int main(int argc, char **argv) {
    if (argc < 4) { fprintf(stderr, "usage: %s game.exe script outdir\n", argv[0]); return 1; }
    outdir = argv[3];
    script_load(&script, argv[2]);
    FILE *f = fopen(argv[1], "rb"); fseek(f, 0, SEEK_END); long fsz = ftell(f); fseek(f, 0, SEEK_SET);
    u8 *file = malloc(fsz); fread(file, 1, fsz, f); fclose(f);
    u32 pe = *(u32 *)(file + 0x3c);
    u16 nsec = *(u16 *)(file + pe + 6); u16 optsz = *(u16 *)(file + pe + 20);
    u8 *opt = file + pe + 24;
    u64 base = *(u64 *)(opt + 24); u32 imgsz = *(u32 *)(opt + 56); u32 hdrsz = *(u32 *)(opt + 60);
    image = mmap((void *)base, imgsz, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED_NOREPLACE, -1, 0);
    if (image != (u8 *)base) { perror("mmap image"); return 1; }
    memcpy(image, file, hdrsz);
    u8 *sec = opt + optsz;
    for (int i = 0; i < nsec; i++, sec += 40) {
        u32 va = *(u32 *)(sec + 12), rawsz = *(u32 *)(sec + 16), rawoff = *(u32 *)(sec + 20);
        memcpy(image + va, file + rawoff, rawsz);
    }
    u32 imp_rva = *(u32 *)(opt + 112 + 8);
    for (u8 *d = image + imp_rva; *(u32 *)(d + 12); d += 20) {
        u64 *thunk = (u64 *)(image + *(u32 *)(d + 16));
        for (; *thunk; thunk++) {
            const char *name = (char *)image + (u32)*thunk + 2;
            void *fn = (void *)unknown_import;
            for (size_t k = 0; k < sizeof shims / sizeof *shims; k++) if (!strcmp(shims[k].name, name)) fn = shims[k].fn;
            *thunk = (u64)fn;
        }
    }
    // patch rdrand (48|41) 0F C7 F0 -> int3
    for (u8 *p = image + 0x1000; p < image + 0x21000; p++) {
        if ((p[0] == 0x48 || p[0] == 0x41) && p[1] == 0x0f && p[2] == 0xc7 && p[3] == 0xf0) {
            rdrand_sites[n_rdrand] = (u64)p; rdrand_regs[n_rdrand] = p[0] == 0x41; n_rdrand++;
            p[0] = 0xcc; p[1] = p[2] = p[3] = 0x90;
        }
    }
    struct sigaction sa = {0}; sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = on_trap; sigaction(SIGTRAP, &sa, 0);
    sa.sa_sigaction = on_segv; sigaction(SIGSEGV, &sa, 0); sigaction(SIGILL, &sa, 0); sigaction(SIGFPE, &sa, 0);
    if (script.dir[0] && chdir(script.dir)) { perror("chdir"); return 1; }
    typedef u64 (WINAPI *Entry)(void);
    u64 r = ((Entry)(base + 0x1fe50))();
    fprintf(stderr, "game returned %llu after %d frames\n", (unsigned long long)r, frame);
    return 0;
}
