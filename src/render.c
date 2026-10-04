// Software rendering primitives that draw into the 32-bit backbuffer.
// (original: 0x140004410 .. 0x140004bc0, 0x140006d00, 0x140007ff0, 0x140008090)
#include "game.h"

u32 *g_backbuffer;  // 0x1400296c8
i32 g_bb_w;         // 0x1400296d0
i32 g_bb_h;         // 0x1400296d4

// Shared clipping/stepping for the four sprite blitters. The source position
// is computed exactly as the original does (integer division by the scale).
#define BLIT_BODY(PIXEL_STMT)                                                   \
    i32 x0 = x > 0 ? x : 0;                                                     \
    i32 y0 = y > 0 ? y : 0;                                                     \
    i32 srcx = (s->w * frame + s->x) * scale;                                   \
    if (x < 0) srcx -= x;                                                       \
    i32 srcy = scale * s->y;                                                    \
    if (y < 0) srcy -= y;                                                       \
    i32 x1 = s->w * scale + x;                                                  \
    i32 y1 = scale * s->h + y;                                                  \
    if (y1 > g_bb_h) y1 = g_bb_h;                                               \
    if (x1 > g_bb_w) x1 = g_bb_w;                                               \
    if (y1 - y0 <= 0) return;                                                   \
    srcy -= y0;                                                                 \
    for (i32 row = y0; row < y1; row++) {                                       \
        u32 *dst = g_backbuffer + ((i64)(row * g_bb_w) + (i64)x0);              \
        const u32 *src = s->img->pixels;                                        \
        i32 iw = s->img->w;                                                     \
        i32 sx = srcx;                                                          \
        for (i64 i = 0; i < (i64)(x1 - x0); i++, sx++) {                        \
            u32 p = src[(u32)(((srcy + row) / scale) * iw) + (i64)(sx / scale)]; \
            PIXEL_STMT;                                                         \
        }                                                                       \
    }

// 0x140004410
void blit_opaque(const Sprite *s, i32 x, i32 y, i32 scale, i32 frame) {
    BLIT_BODY(dst[i] = p)
}

// 0x140004550: skips fully transparent texels (alpha byte == 0)
void blit(const Sprite *s, i32 x, i32 y, i32 scale, i32 frame) {
    BLIT_BODY(if (p >> 24) dst[i] = p)
}

// 0x1400046a0: keeps alpha and the lowest colour byte only
void blit_channel0(const Sprite *s, i32 x, i32 y, i32 scale, i32 frame) {
    BLIT_BODY(if (p >> 24) dst[i] = (p & 0xff000000u) | (p & 0xffu))
}

// 0x1400047f0: keeps alpha and the third colour byte only
void blit_channel2(const Sprite *s, i32 x, i32 y, i32 scale, i32 frame) {
    BLIT_BODY(if (p >> 24) dst[i] = p & 0xffff0000u)
}

static inline void fill_span(i32 row, i32 a, i32 b, u32 color) {
    u32 *p = g_backbuffer + (i64)(row * g_bb_w) + a;
    for (i64 n = (i64)(b - a); n > 0; n--) *p++ = color;
}

// 0x140004940: rectangle outline of the given thickness
void draw_rect_outline(i32 x, i32 y, i32 w, i32 h, i32 thick, u32 color) {
    if (!g_backbuffer || w <= 0 || h <= 0 || thick <= 0 || g_bb_w <= 0 || g_bb_h <= 0) return;
    i32 bottom = y + h, right = x + w;
    if (right <= 0 || bottom <= 0 || x >= g_bb_w || y >= g_bb_h) return;
    i32 m = h;
    if (w < h) m = w;
    u32 t = (u32)m >> 1;
    if (thick < (i32)((u32)m >> 1)) t = (u32)thick;
    if (t == 0) return;

    i32 top_end = MIN((i32)(y + t), g_bb_h);
    i32 bot_beg = MAX(bottom - (i32)t, 0);
    i32 bot_end = MIN(bottom, g_bb_h);
    i32 cx0 = MAX(x, 0);
    i32 left_end = MIN((i32)(x + t), g_bb_w);
    i32 right_beg = MAX(right - (i32)t, 0);
    i32 cx1 = MIN(right, g_bb_w);
    i32 mid_beg = MAX((i32)(y + t), 0);
    i32 mid_end = MIN(bottom - (i32)t, g_bb_h);
    i32 cy0 = MAX(y, 0);

    for (i32 r = cy0; r < top_end; r++)
        if (cx0 < cx1) fill_span(r, cx0, cx1, color);
    for (i32 r = bot_beg; r < bot_end; r++)
        if (cx0 < cx1) fill_span(r, cx0, cx1, color);
    for (i32 r = mid_beg; r < mid_end; r++) {
        if (cx0 < left_end) fill_span(r, cx0, left_end, color);
        if (right_beg < cx1) fill_span(r, right_beg, cx1, color);
    }
}

// 0x140004bc0: outlined box with a solid interior
void draw_box(i32 x, i32 y, i32 w, i32 h, i32 thick, u32 border, u32 fill) {
    if (!g_backbuffer || w <= 0 || h <= 0 || g_bb_w <= 0 || g_bb_h <= 0) return;
    if (MAX(x, 0) >= MIN(x + w, g_bb_w)) return;
    if (MAX(y, 0) >= MIN(y + h, g_bb_h)) return;
    draw_rect_outline(x, y, w, h, thick, border);
    i32 ix0 = MAX(x + thick, 0);
    i32 iy0 = MAX(y + thick, 0);
    i32 ix1 = MIN((x - thick) + w, g_bb_w);
    i32 iy1 = MIN((y - thick) + h, g_bb_h);
    if (ix0 < ix1 && iy0 < iy1)
        for (i32 r = iy0; r < iy1; r++) fill_span(r, ix0, ix1, fill);
}

// 0x140007ff0
void fill_rect(i32 x, i32 y, i32 w, i32 h, u32 color) {
    i32 x0 = MAX(x, 0), y0 = MAX(y, 0);
    i32 x1 = MIN(x + w, g_bb_w), y1 = MIN(y + h, g_bb_h);
    if (x0 < x1 && y0 < y1)
        for (i32 r = y0; r < y1; r++) fill_span(r, x0, x1, color);
}

// 0x140008090: blends `color` (alpha in the top byte) over a rectangle
void blend_rect(i32 x, i32 y, i32 w, i32 h, u32 color) {
    i32 x0 = MAX(x, 0), y0 = MAX(y, 0);
    i32 x1 = MIN(x + w, g_bb_w), y1 = MIN(y + h, g_bb_h);
    if (x0 >= x1 || y0 >= y1) return;
    u32 a = color >> 24;
    if (!a) return;
    u32 ia = 0xff - a;
    for (i32 r = y0; r < y1; r++) {
        u8 *p = (u8 *)(g_backbuffer + (i64)(r * g_bb_w) + x0);
        for (i64 n = x1 - x0; n > 0; n--, p += 4) {
            u32 old = *(u32 *)p;
            p[3] = 0xff;
            p[0] = (u8)(((old & 0xff) * ia + (color & 0xff) * a) / 0xff);
            p[1] = (u8)(((old >> 8 & 0xff) * ia + (color >> 8 & 0xff) * a) / 0xff);
            p[2] = (u8)(((old >> 16 & 0xff) * ia + (color >> 16 & 0xff) * a) / 0xff);
        }
    }
}

// 0x140006d00: draws an unsigned number right-aligned to `digits` columns
// (digit sprites live in the tileset, `spacing` is in pixels, scale = spacing/16)
void draw_number(u32 value, i32 x, i32 y, i32 spacing) {
    i32 scale = spacing / 16;
    if (value == 0) {
        blit(&g_spr_digits[0], x, y, scale, 0);
        return;
    }
    i32 px = (i32)count_digits(value) * spacing + x;
    do {
        blit(&g_spr_digits[value % 10], px, y, scale, 0);
        px -= spacing;
        value /= 10;
    } while (value);
}
