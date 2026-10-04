// Bit-exact scalar versions of the original's hand-vectorised math helpers.
// The original evaluates these with AVX/FMA; the polynomial coefficients and
// the evaluation order are reproduced here so results match exactly.
#include "game.h"

static inline u32 f2u(f32 f) { u32 u; memcpy(&u, &f, 4); return u; }
static inline f32 u2f(u32 u) { f32 f; memcpy(&f, &u, 4); return f; }

// cvtps2dq with the default round-to-nearest-even mode
static inline i32 round_even(f32 f) { return (i32)lrintf(f); }

// 0x140012110: number of decimal digits minus one (via a log2 polynomial)
u32 count_digits(u32 n) {
    if (n <= 999) {
        if (n > 99) return 2;
        return n > 9;
    }
    f32 x = (f32)n;
    u32 bits = f2u(x);
    i32 e = (i32)((bits >> 23) & 0xff) - 0x7f;
    f32 m = u2f((bits & 0x7fffff) | 0x3f800000) - 1.0f;
    f32 p = fmaf(m, -0.0344359055f, 0.146032885f);
    p = fmaf(p, m, -0.303036213f);
    p = fmaf(p, m, 0.469174057f);
    p = fmaf(p, m, -0.720426142f);
    p = fmaf(p, m, 1.44268286f);
    f32 l2 = fmaf(p, m, (f32)e);
    // (n is a positive finite value here, so the special-case blends never apply)
    return (u32)(i64)floorf(l2 * 0.30103001f);
}

// 0x140006b90: unit-length direction for an angle given in turns, with the
// x component squashed by 0.75 before normalising. Returns (0,0) if degenerate.
V2 dir_from_turns(f32 turns) {
    static const f32 quarter[4] = {0.25f, 0.5f, 0.75f, 1.0f};
    f32 t = turns - floorf(turns);
    i32 q = round_even(t * 4.0f);
    f32 off = q == 0 ? 0.0f : quarter[(q - 1) & 3];
    f32 r = t - off;
    f32 r2 = r * r;
    f32 s = fmaf(r2, -75.837471f, 81.6046143f);
    s = fmaf(r2, s, -41.3417587f);
    s = fmaf(r2, s, 6.28318548f);
    f32 sn = s * r;
    if ((q & 3) == 1 || (q & 3) == 2) sn = u2f(f2u(sn) ^ 0x80000000u);
    f32 c = fmaf(r2, 58.0762405f, -85.4118652f);
    c = fmaf(r2, c, 64.9390793f);
    c = fmaf(r2, c, -19.7392082f);
    c = fmaf(r2, c, 1.0f);
    if ((q & 3) >= 2) c = u2f(f2u(c) ^ 0x80000000u);
    f32 first = (q & 1) ? sn : c;
    f32 second = (q & 1) ? c : sn;
    f32 fx = first * 0.75f;
    f32 len2 = fx * fx + second * second;
    if (!(9.99999905e-09f < len2)) return v2(0, 0);
    f32 inv = 1.0f / sqrtf(len2);
    return v2(fx * inv, inv * second);
}
