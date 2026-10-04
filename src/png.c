// PNG decoder. The original ships its own decoder (0x140013b30 and helpers);
// this is a from-scratch reimplementation that reproduces its output format
// and its quirks for unusual pixel formats:
//   * 8-bit grey (non-interlaced) decodes to bytes (g, 0, 0, 0xff), and grey+alpha
//     to (g, 0, 0, a) - i.e. they come out red after the BGR swap in the loader.
//   * other bit depths / interlaced images go through a generic path that
//     replicates grey into all channels, and whose tRNS handling yields alpha
//     0xff for the transparent colour and 0 for everything else.
// Output is RGBA bytes; images.c swaps R and B afterwards as the original does.
#include "png.h"
#include <stdlib.h>

// ---------------------------------------------------------------------------
// inflate (RFC 1951)
typedef struct {
    const u8 *src;
    u64 len, pos;
    u32 bitbuf, bitcnt;
    u8 *out;
    u64 out_len, out_cap;
    b32 err;
} Inflate;

static u32 bits(Inflate *s, u32 n) {
    while (s->bitcnt < n) {
        if (s->pos >= s->len) {
            s->err = 1;
            return 0;
        }
        s->bitbuf |= (u32)s->src[s->pos++] << s->bitcnt;
        s->bitcnt += 8;
    }
    u32 v = s->bitbuf & ((1u << n) - 1);
    if (n == 32) v = s->bitbuf;
    s->bitbuf >>= n;
    s->bitcnt -= n;
    return v;
}

typedef struct { u16 count[16]; u16 symbol[288]; } Huff;

static b32 huff_build(Huff *h, const u8 *lengths, u32 n) {
    memset(h->count, 0, sizeof h->count);
    for (u32 i = 0; i < n; i++) h->count[lengths[i]]++;
    h->count[0] = 0;
    u16 offs[16];
    offs[1] = 0;
    for (int i = 1; i < 15; i++) offs[i + 1] = offs[i] + h->count[i];
    for (u32 i = 0; i < n; i++)
        if (lengths[i]) h->symbol[offs[lengths[i]]++] = (u16)i;
    return 1;
}

static i32 huff_decode(Inflate *s, const Huff *h) {
    i32 code = 0, first = 0, index = 0;
    for (int len = 1; len < 16; len++) {
        code |= (i32)bits(s, 1);
        if (s->err) return -1;
        i32 count = h->count[len];
        if (code - count < first) return h->symbol[index + (code - first)];
        index += count;
        first += count;
        first <<= 1;
        code <<= 1;
    }
    s->err = 1;
    return -1;
}

static void out_byte(Inflate *s, u8 b) {
    if (s->out_len >= s->out_cap) {
        s->out_cap = s->out_cap ? s->out_cap * 2 : 65536;
        s->out = realloc(s->out, s->out_cap);
    }
    s->out[s->out_len++] = b;
}

static const u16 k_len_base[29] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31,
                                   35, 43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258};
static const u8 k_len_extra[29] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 0};
static const u16 k_dist_base[30] = {1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193,
                                    257, 385, 513, 769, 1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577};
static const u8 k_dist_extra[30] = {0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6,
                                    7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13};

static b32 inflate_codes(Inflate *s, const Huff *lit, const Huff *dist) {
    for (;;) {
        i32 sym = huff_decode(s, lit);
        if (sym < 0) return 0;
        if (sym < 256) {
            out_byte(s, (u8)sym);
        } else if (sym == 256) {
            return 1;
        } else {
            sym -= 257;
            if (sym >= 29) return 0;
            u32 len = k_len_base[sym] + bits(s, k_len_extra[sym]);
            i32 ds = huff_decode(s, dist);
            if (ds < 0 || ds >= 30) return 0;
            u32 d = k_dist_base[ds] + bits(s, k_dist_extra[ds]);
            if (s->err || d > s->out_len) return 0;
            for (u32 i = 0; i < len; i++) out_byte(s, s->out[s->out_len - d]);
        }
    }
}

static b32 inflate_raw(Inflate *s) {
    u32 final;
    do {
        final = bits(s, 1);
        u32 type = bits(s, 2);
        if (s->err) return 0;
        if (type == 0) {
            s->bitbuf = 0;
            s->bitcnt = 0;
            if (s->pos + 4 > s->len) return 0;
            u32 len = s->src[s->pos] | (u32)s->src[s->pos + 1] << 8;
            s->pos += 4;
            if (s->pos + len > s->len) return 0;
            for (u32 i = 0; i < len; i++) out_byte(s, s->src[s->pos++]);
        } else if (type == 1) {
            static Huff lit, dist;
            static b32 ready;
            if (!ready) {
                u8 l[288];
                for (int i = 0; i < 144; i++) l[i] = 8;
                for (int i = 144; i < 256; i++) l[i] = 9;
                for (int i = 256; i < 280; i++) l[i] = 7;
                for (int i = 280; i < 288; i++) l[i] = 8;
                huff_build(&lit, l, 288);
                for (int i = 0; i < 30; i++) l[i] = 5;
                huff_build(&dist, l, 30);
                ready = 1;
            }
            if (!inflate_codes(s, &lit, &dist)) return 0;
        } else if (type == 2) {
            u32 hlit = bits(s, 5) + 257, hdist = bits(s, 5) + 1, hclen = bits(s, 4) + 4;
            static const u8 order[19] = {16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};
            u8 lens[320];
            memset(lens, 0, sizeof lens);
            for (u32 i = 0; i < hclen; i++) lens[order[i]] = (u8)bits(s, 3);
            Huff lh;
            huff_build(&lh, lens, 19);
            u32 n = 0;
            memset(lens, 0, sizeof lens);
            while (n < hlit + hdist) {
                i32 sym = huff_decode(s, &lh);
                if (sym < 0) return 0;
                if (sym < 16) {
                    lens[n++] = (u8)sym;
                } else {
                    u32 rep;
                    u8 v = 0;
                    if (sym == 16) {
                        if (n == 0) return 0;
                        v = lens[n - 1];
                        rep = 3 + bits(s, 2);
                    } else if (sym == 17) {
                        rep = 3 + bits(s, 3);
                    } else {
                        rep = 11 + bits(s, 7);
                    }
                    if (n + rep > hlit + hdist) return 0;
                    while (rep--) lens[n++] = v;
                }
            }
            Huff lit, dist;
            huff_build(&lit, lens, hlit);
            huff_build(&dist, lens + hlit, hdist);
            if (!inflate_codes(s, &lit, &dist)) return 0;
        } else {
            return 0;
        }
        if (s->err) return 0;
    } while (!final);
    return 1;
}

// ---------------------------------------------------------------------------
static u32 be32(const u8 *p) { return (u32)p[0] << 24 | (u32)p[1] << 16 | (u32)p[2] << 8 | p[3]; }

static u8 paeth(u8 a, u8 b, u8 c) {
    i32 p = (i32)a + b - c;
    i32 pa = abs(p - a), pb = abs(p - b), pc = abs(p - c);
    if (pa <= pb && pa <= pc) return a;
    if (pb <= pc) return b;
    return c;
}

// Undo the scanline filters of one (sub)image; returns bytes consumed.
static u64 unfilter(const u8 *src, u64 avail, u8 *dst, u32 w, u32 h, u32 bpp_bits, u32 bpp) {
    u32 stride = (w * bpp_bits + 7) >> 3;
    u64 used = 0;
    const u8 *prev = NULL;
    for (u32 y = 0; y < h; y++) {
        if (used + 1 + stride > avail) return 0;
        u8 f = src[used++];
        const u8 *in = src + used;
        u8 *out = dst + (u64)y * stride;
        for (u32 i = 0; i < stride; i++) {
            u8 a = i >= bpp ? out[i - bpp] : 0;
            u8 b = prev ? prev[i] : 0;
            u8 c = (prev && i >= bpp) ? prev[i - bpp] : 0;
            u8 v = in[i];
            switch (f) {
            case 0: break;
            case 1: v += a; break;
            case 2: v += b; break;
            case 3: v += (u8)(((u32)a + b) >> 1); break;
            case 4: v += paeth(a, b, c); break;
            default: return 0;
            }
            out[i] = v;
        }
        used += stride;
        prev = out;
    }
    return used;
}

static u32 sample(const u8 *row, u32 idx, u32 depth) {
    switch (depth) {
    case 1: return row[idx >> 3] >> (7 - (idx & 7)) & 1;
    case 2: return row[idx >> 2] >> ((3 - (idx & 3)) * 2) & 3;
    case 4: return row[idx >> 1] >> ((1 - (idx & 1)) * 4) & 0xf;
    case 8: return row[idx];
    default: return row[idx * 2];  // 16 bit: high byte (compared as two bytes below)
    }
}

// Generic conversion used by the original for non-8-bit or interlaced images (0x140019fe0)
static void convert_generic(const u8 *buf, u32 sw, u32 sh, u32 x0, u32 y0, u32 dx, u32 dy, u8 *out, u32 out_w,
                            u32 depth, u32 chans, b32 palette, const u8 *plte, u32 plte_n, const u8 *trns,
                            u32 trns_n) {
    u32 stride = (sw * depth * chans + 7) >> 3;
    u8 zero[8] = {0};
    const u8 *tr = trns ? trns : zero;
    for (u32 y = 0; y < sh; y++) {
        const u8 *row = buf + (u64)y * stride;
        for (u32 x = 0; x < sw; x++) {
            u8 v[4] = {0, 0, 0, 0};
            b32 match = 1;
            for (u32 c = 0; c < chans; c++) {
                u32 idx = x * chans + c;
                u32 s = sample(row, idx, depth);
                u8 b;
                if (depth == 1) {
                    b = palette ? (u8)s : (u8)(0u - s);
                    match &= (b != 0) == (tr[c] != 0);
                } else if (depth == 2) {
                    match &= s == tr[c];
                    b = palette ? (u8)s : (u8)(s << 4 | s);
                } else if (depth == 4) {
                    match &= s == tr[c];
                    b = palette ? (u8)s : (u8)((s & 0xf) ^ (s << 4));
                } else if (depth == 8) {
                    match &= (u8)s == tr[c];
                    b = (u8)s;
                } else {
                    b = row[idx * 2];
                    match &= b == tr[c * 2] && row[idx * 2 + 1] == tr[c * 2 + 1];
                }
                v[c] = b;
            }
            u8 *o = out + ((u64)(dy * y + y0) * out_w + (dx * x + x0)) * 4;
            if (!palette) {
                u32 n = chans + (trns != NULL);
                if (trns) v[n - 1] = (u8)(0u - (u32)match);
                if (n == 1) {
                    o[0] = o[1] = o[2] = v[0];
                    o[3] = 0xff;
                } else if (n == 2) {
                    o[0] = o[1] = o[2] = v[0];
                    o[3] = v[1];
                } else if (n == 3) {
                    o[0] = v[0];
                    o[1] = v[1];
                    o[2] = v[2];
                    o[3] = 0xff;
                } else {
                    memcpy(o, v, 4);
                }
            } else {
                u32 i = v[0];
                if (i >= plte_n) {
                    memset(o, 0, 4);
                    continue;
                }
                o[0] = plte[i * 3];
                o[1] = plte[i * 3 + 1];
                o[2] = plte[i * 3 + 2];
                o[3] = i < trns_n ? trns[i] : 0xff;
            }
        }
    }
}

u8 *png_decode(const u8 *data, u64 size, u32 *w_out, u32 *h_out) {
    static const u8 sig[8] = {0x89, 'P', 'N', 'G', '\r', '\n', 0x1a, '\n'};
    if (size <= 8 || memcmp(data, sig, 8) != 0) return NULL;
    u32 w = 0, h = 0, depth = 0, ctype = 0, interlace = 0;
    b32 have_hdr = 0;
    const u8 *plte = NULL, *trns = NULL;
    u32 plte_n = 0, trns_n = 0;
    u8 *idat = NULL;
    u64 idat_len = 0;
    u64 pos = 8;
    while (pos + 8 <= size) {
        u32 len = be32(data + pos);
        const u8 *type = data + pos + 4;
        const u8 *body = data + pos + 8;
        if (pos + 12 + (u64)len > size) break;
        if (!memcmp(type, "IHDR", 4) && len >= 13) {
            w = be32(body);
            h = be32(body + 4);
            depth = body[8];
            ctype = body[9];
            interlace = body[12];
            have_hdr = 1;
        } else if (!memcmp(type, "PLTE", 4)) {
            plte = body;
            plte_n = len / 3;
        } else if (!memcmp(type, "tRNS", 4)) {
            trns = body;
            trns_n = len;
        } else if (!memcmp(type, "IDAT", 4)) {
            idat = realloc(idat, idat_len + len);
            memcpy(idat + idat_len, body, len);
            idat_len += len;
        } else if (!memcmp(type, "IEND", 4)) {
            break;
        }
        pos += 12 + (u64)len;
    }
    if (!have_hdr || !idat || idat_len < 2 || (idat[0] & 0xf) != 8 || !w || !h) {
        free(idat);
        return NULL;
    }
    b32 palette = (ctype & 1) != 0;
    u32 chans = palette ? 1 : (ctype == 0 ? 1 : ctype == 2 ? 3 : ctype == 4 ? 2 : 4);
    Inflate s = {idat, idat_len, 2, 0, 0, NULL, 0, 0, 0};
    b32 ok = inflate_raw(&s);
    free(idat);
    if (!ok) {
        free(s.out);
        return NULL;
    }
    u32 bpp_bits = depth * chans;
    u32 bpp = (bpp_bits + 7) >> 3;
    u8 *rgba = calloc((u64)w * h, 4);
    u8 *tmp = malloc((u64)((w * bpp_bits + 7) >> 3) * h + 16);
    if (!interlace) {
        if (!unfilter(s.out, s.out_len, tmp, w, h, bpp_bits, bpp)) goto fail;
        u64 n = (u64)w * h;
        if (depth == 8 && chans == 4) {
            memcpy(rgba, tmp, n * 4);
        } else if (depth == 8 && !palette && chans == 3) {  // 0x140001af0
            for (u64 i = 0; i < n; i++) {
                const u8 *p = tmp + i * 3;
                u8 *o = rgba + i * 4;
                o[0] = p[0];
                o[1] = p[1];
                o[2] = p[2];
                o[3] = 0xff;
                if (trns && trns_n >= 3 && p[0] == trns[0] && p[1] == trns[1] && p[2] == trns[2]) o[3] = 0;
            }
        } else if (depth == 8 && !palette && chans == 2) {  // 0x140001980
            for (u64 i = 0; i < n; i++) {
                const u8 *p = tmp + i * 2;
                u8 *o = rgba + i * 4;
                o[0] = p[0];
                o[1] = 0;
                o[2] = 0;
                o[3] = p[1];
                if (trns && trns_n >= 2 && p[0] == trns[0] && p[1] == trns[1]) o[3] = 0;
            }
        } else if (depth == 8 && chans == 1) {  // 0x140001800
            for (u64 i = 0; i < n; i++) {
                u8 v = tmp[i];
                u8 *o = rgba + i * 4;
                if (palette) {
                    if (plte && v < plte_n) {
                        o[0] = plte[v * 3];
                        o[1] = plte[v * 3 + 1];
                        o[2] = plte[v * 3 + 2];
                    }
                    o[3] = 0xff;
                    if (trns && v < trns_n) o[3] = trns[v];
                } else {
                    o[0] = v;
                    o[1] = 0;
                    o[2] = 0;
                    o[3] = 0xff;
                    if (trns && v == trns[0]) o[3] = 0;
                }
            }
        } else {
            convert_generic(tmp, w, h, 0, 0, 1, 1, rgba, w, depth, chans, palette, plte, plte_n, trns, trns_n);
        }
    } else {
        static const u32 sx[7] = {0, 4, 0, 2, 0, 1, 0}, sy[7] = {0, 0, 4, 0, 2, 0, 1};
        static const u32 dx[7] = {8, 8, 4, 4, 2, 2, 1}, dy[7] = {8, 8, 8, 4, 4, 2, 2};
        u64 off = 0;
        for (int p = 0; p < 7; p++) {
            u32 pw = (w + dx[p] - 1 - sx[p]) / dx[p];
            u32 ph = (h + dy[p] - 1 - sy[p]) / dy[p];
            if (w <= sx[p]) pw = 0;
            if (h <= sy[p]) ph = 0;
            if (!pw || !ph) continue;
            u64 used = unfilter(s.out + off, s.out_len - off, tmp, pw, ph, bpp_bits, bpp);
            if (!used) goto fail;
            off += used;
            convert_generic(tmp, pw, ph, sx[p], sy[p], dx[p], dy[p], rgba, w, depth, chans, palette, plte, plte_n,
                            trns, trns_n);
        }
    }
    free(tmp);
    free(s.out);
    *w_out = w;
    *h_out = h;
    return rgba;
fail:
    free(tmp);
    free(s.out);
    free(rgba);
    return NULL;
}
