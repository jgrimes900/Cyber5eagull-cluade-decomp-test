// Map generation: coast bands, rivers/lakes, ore and flower deposits.
#include "game.h"

// Scratch state used while generating (0x10004 + 0x10000 bytes on the stack in
// the original): `taken` marks cells that already belong to a feature, `clear`
// marks the safety margin around ore deposits.
typedef struct WorldGen {
    u32 seed;
    u8 taken[0x10000];
    u8 clear[0x10000];
} WorldGen;

typedef HomeArray ZoneList;  // reserved areas around homes, same layout as Home

static inline b32 in_map(u32 x, u32 y) { return x < g_map.w && y < g_map.h; }
static inline void set_tile(u32 x, u32 y, u8 t) { if (in_map(x, y)) g_tiles[y * g_map.w + x] = t; }
static inline u8 get_tile(u32 x, u32 y) { return in_map(x, y) ? g_tiles[y * g_map.w + x] : 0; }

// 0x14001cba0: is the cell inside one of the reserved zones?
static b32 in_zone(V2u c, const ZoneList *z) {
    for (u32 i = 0; i < z->count; i++) {
        const Home *h = &z->data[i];
        u32 sz = h->big ? 2 : 1;
        if (h->pos.x <= c.x && h->pos.y <= c.y && c.x < h->pos.x + sz && c.y < sz + h->pos.y) return 1;
    }
    return 0;
}

// 0x14001c9e0: distance from the cell centre to a zone rectangle <= r
b32 home_in_range(V2u c, const Home *h, u32 r) {
    f32 px = (f32)c.x + 0.5f, py = (f32)c.y + 0.5f;
    u32 sz = h->big ? 2 : 1;
    f32 zx = (f32)h->pos.x, zy = (f32)h->pos.y;
    f32 cx = sse_min((f32)sz + zx, sse_max(zx, px));
    f32 cy = sse_min((f32)sz + zy, sse_max(zy, py));
    f32 dx = px - cx, dy = py - cy;
    return dy * dy + dx * dx <= (f32)r * (f32)r;
}

// 0x14001c960
static b32 near_zone(V2u c, const ZoneList *z) {
    for (u32 i = 0; i < z->count; i++)
        if (home_in_range(c, &z->data[i], 4)) return 1;
    return 0;
}

// 0x14001c8c0: close to any home (bigger homes reach further)
b32 near_any_home(V2u c) {
    for (u32 i = 0; i < g_homes.count; i++)
        if (home_in_range(c, &g_homes.data[i], g_homes.data[i].big ? 0x14 : 9)) return 1;
    return 0;
}

// 0x140005430: plain grass outside the reserved zones
static b32 cell_free(const ZoneList *z, V2u c) {
    if (!in_map(c.x, c.y)) return 0;
    if (in_zone(c, z) || near_zone(c, z)) return 0;
    return get_tile(c.x, c.y) == TILE_GRASS;
}

// 0x1400051f0: free for a new deposit
static b32 cell_ok(WorldGen *g, const ZoneList *z, V2u c, b32 check_near) {
    if (!in_map(c.x, c.y)) return 0;
    u32 i = c.y * g_map.w + c.x;
    if (g->taken[i] || g->clear[i]) return 0;
    if (get_tile(c.x, c.y) != TILE_GRASS) return 0;
    if (in_zone(c, z)) return 0;
    if (check_near && near_zone(c, z)) return 0;
    return 1;
}

// 0x14001b3e0: ocean, nests and beach along the left edge
static void gen_coast(WorldGen *g) {
    for (u32 y = 0; y < g_map.h; y++) {
        u32 h = hash_mix(y >> 1 ^ g->seed ^ 0xa511e9b3);
        u32 w = g_map.w;
        u32 a = MIN((h & 1) + 3, w);
        u32 b = MIN(a + 1, w);
        u32 c = MIN((h >> 5 & 1) + ((h >> 10 & 1) != 0) + 1 + b, w);
        for (u32 x = 0; x < g_map.w; x++) {
            if (x < a) {
                set_tile(x, y, TILE_CLIFF);
            } else if (x < b) {
                set_tile(x, y, TILE_NEST);
                nest_add(v2u_make(x, y));
            } else if (x < c) {
                set_tile(x, y, TILE_5);
            } else {
                set_tile(x, y, TILE_GRASS);
            }
        }
    }
}

// 0x14001c1d0: elliptic blob of water
static void gen_lake(WorldGen *g, const ZoneList *z, V2 c, f32 rx, f32 ry, u32 seed) {
    i32 x0 = (i32)floorf((c.x - rx) - 1.0f);
    if (x0 < 0) x0 = 0;
    i32 x1 = (i32)ceilf((c.x + rx) + 1.0f);
    if (x1 > (i32)g_map.w - 1) x1 = (i32)g_map.w - 1;
    i32 y0 = (i32)floorf((c.y - ry) - 1.0f);
    i32 y1 = (i32)ceilf((c.y + ry) + 1.0f);
    if (y1 > (i32)g_map.h - 1) y1 = (i32)g_map.h - 1;
    if (y0 < 0) y0 = 0;
    u32 hy = (u32)y0 * 0x85ebca6bu;
    for (i32 y = y0; y <= y1; y++, hy += 0x85ebca6bu) {
        if (x0 > x1) continue;
        f32 dy = (((f32)(u32)y + 0.5f) - c.y) / sse_max(ry, 0.5f);
        f32 dy2 = dy * dy;
        f32 xr = sse_max(rx, 0.5f);
        u32 hx = (u32)x0 * 0x9e3779b9u;
        for (i32 x = x0; x <= x1; x++, hx += 0x9e3779b9u) {
            u32 h = hy ^ hx ^ seed;
            h = (h >> 16 ^ h) * 0x45d9f3b;
            u32 jit = ((h >> 16 ^ h) * 0x5d9f3bu) >> 24 & 3;
            f32 dx = (((f32)(u32)x + 0.5f) - c.x) / xr;
            f32 d = dx * dx + dy2;
            if ((f32)jit * 0.0799999982f + 0.959999979f >= d && cell_free(z, v2u_make((u32)x, (u32)y))) {
                u32 i = (u32)y * g_map.w + (u32)x;
                set_tile((u32)x, (u32)y, TILE_WATER);
                g->taken[i] = 1;
                g->clear[i] = 1;
            }
        }
    }
}

// 0x140008ee0: a meandering river made of overlapping lakes
static void gen_river(WorldGen *g, const ZoneList *z, V2u start, u32 len, f32 width, u32 seed) {
    f32 px = (f32)start.x + 0.5f, py = (f32)start.y + 0.5f;
    f32 ang = (f32)(seed & 0xff) * 0.00048828125f + 0.140000001f;
    V2 dir = dir_from_turns(ang);
    for (u32 i = 0; i < len; i++) {
        u32 h = hash_mix(i * 0x9e3779b9u ^ seed);
        f32 t = len > 1 ? (f32)i / (f32)(len - 1) : 0.0f;
        f32 w = (1.0f - fabsf((t + t) - 1.0f) * 0.550000012f) * width + 0.550000012f;
        f32 ry = ((f32)(h >> 20 & 1) * 0.150000006f + 0.800000012f) * w;
        gen_lake(g, z, v2(px, py), w, ry, h);
        if ((h & 3) == 0) {
            f32 sgn = (h & 0x10) == 0 ? -1.0f : 1.0f;
            f32 cx = ((sgn * -dir.y) * w) * 0.550000012f + px;
            f32 cy = ((sgn * dir.x) * w) * 0.550000012f + py;
            gen_lake(g, z, v2(cx, cy), w * 0.550000012f, ry * 0.550000012f, h ^ 0xa57e2d1b);
        }
        ang = ang + ((f32)(h >> 8 & 7) - 3.0f) * 0.00350000011f;
        dir = dir_from_turns(ang);
        f32 step = (f32)(h >> 15 & 1) * 0.349999994f + 0.949999988f;
        py = step * dir.y + py;
        px = dir.x * step + px;
        if (12.0f > px || px > (f32)g_map.w - 4.0f || 2.0f > py || py > (f32)g_map.h - 3.0f) break;
    }
}

// 0x14001bbb0: grow lakes into nearly enclosed grass cells
static void gen_smooth_lakes(WorldGen *g, const ZoneList *z) {
    static V2u list[0x10000];
    u32 n = 0;
    if (g_map.h <= 2) return;
    for (u32 y = 1; y + 1 < g_map.h; y++) {
        for (u32 x = 1; x + 1 < g_map.w; x++) {
            if (!cell_free(z, v2u_make(x, y))) continue;
            u32 cnt = 0;
            for (u32 yy = y - 1; (i32)(yy - y) < 2; yy++) {
                cnt += get_tile(x - 1, yy) == TILE_WATER;
                if (yy != y) cnt += get_tile(x, yy) == TILE_WATER;
                cnt += get_tile(x + 1, yy) == TILE_WATER;
            }
            b32 lr = get_tile(x - 1, y) == TILE_WATER && get_tile(x + 1, y) == TILE_WATER;
            b32 ud = get_tile(x, y - 1) == TILE_WATER && y + 1 < g_map.h && get_tile(x, y + 1) == TILE_WATER;
            if (cnt > 4 || ((lr || ud) && cnt > 2)) list[n++] = v2u_make(x, y);
        }
    }
    for (u32 k = 0; k < n; k++) {
        V2u c = list[k];
        if (!cell_free(z, c)) continue;
        u32 i = c.y * g_map.w + c.x;
        set_tile(c.x, c.y, TILE_WATER);
        g->taken[i] = 1;
        g->clear[i] = 1;
    }
}

// 0x14001d610: grow a deposit of `tile` from `start`
static b32 gen_blob(WorldGen *g, const ZoneList *z, V2u start, u8 tile, u32 size, u32 seed, b32 check_near,
                    i32 margin) {
    static const i32 dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    if (!cell_ok(g, z, start, check_near)) return 0;
    V2u front[128], cells[128];
    memset(front, 0, sizeof front);
    memset(cells, 0, sizeof cells);
    set_tile(start.x, start.y, tile);
    front[0] = start;
    cells[0] = start;
    u32 ncells = 1, nfront = 1;
    g->taken[start.y * g_map.w + start.x] = 1;
    u32 iters = MAX(0x18u, size * 10);
    for (u32 it = 0; it < iters; it++) {
        if (nfront == 0 || size <= ncells) break;
        u32 h = it * 0x9e3779b9u ^ seed;
        h = (h >> 16 ^ h) * 0x45d9f3b;
        h = (h >> 16 ^ h) * 0x45d9f3b;
        u32 hf = h >> 16 ^ h;
        u32 fi = hf % nfront;
        V2u pick = (((h >> 29) & 1) == 0 || ncells == 0) ? front[fi] : cells[(h >> 16) % ncells];
        b32 grown = 0;
        for (u32 d = 0; d < 8; d++) {
            u32 hd = hash_mix(d * 0x85ebca6bu ^ hf);
            i32 nx = dirs[hd & 7][0] + (i32)pick.x;
            i32 ny = (i32)pick.y + dirs[hd & 7][1];
            if (nx < 0 || ny < 0 || nx >= (i32)g_map.w || ny >= (i32)g_map.h) continue;
            V2u nc = v2u_make((u32)nx, (u32)ny);
            if (!cell_ok(g, z, nc, check_near) || !(ncells < 3 || (hd & 0x600) != 0)) continue;
            set_tile(nc.x, nc.y, tile);
            g->taken[nc.y * g_map.w + nc.x] = 1;
            if (ncells < 0x80) cells[ncells++] = nc;
            if (nfront <= 0x7f) front[nfront++] = nc;
            grown = 1;
            break;
        }
        if (!grown) {
            nfront--;
            front[fi] = front[nfront];
        }
    }
    for (u32 k = 0; k < ncells; k++) {
        i32 cy = (i32)cells[k].y, cx = (i32)cells[k].x;
        i32 ya = MAX(cy - margin, 0), yb = MIN(cy + margin, (i32)g_map.h - 1);
        i32 xa = MAX(cx - margin, 0), xb = MIN(cx + margin, (i32)g_map.w - 1);
        for (i32 y = ya; y <= yb; y++)
            for (i32 x = xa; x <= xb; x++) g->clear[(u32)(y * (i32)g_map.w + x)] = 1;
    }
    return ncells != 0;
}

// 0x14001b580: guaranteed iron, copper and flowers next to the start
static void gen_start_resources(WorldGen *g, const ZoneList *z, V2u start) {
    i32 sx = (i32)start.x + 5;
    if (sx < 0) sx = 0;
    i32 sy = (i32)start.y;
    i32 y = sy - 2;
    if (y < 0) y = 0;
    if ((i32)(g_map.h - 1) < y) y = (i32)g_map.h - 1;
    i32 x = sx;
    if ((i32)(g_map.w - 1) < x) x = (i32)g_map.w - 1;
    gen_blob(g, z, v2u_make((u32)x, (u32)y), TILE_IRON, 7, g->seed ^ 0x11111111, 0, 1);
    y = sy + 2;
    if (y < 0) y = 0;
    if ((i32)(g_map.h - 1) < y) y = (i32)g_map.h - 1;
    if ((i32)(g_map.w - 1) < sx) sx = (i32)g_map.w - 1;
    gen_blob(g, z, v2u_make((u32)sx, (u32)y), TILE_COPPER, 7, g->seed ^ 0x22222222, 0, 1);
    for (u32 i = 0; i < 8; i++) {
        u32 h = hash_mix(i * 0x9e3779b9u ^ g->seed ^ 0x33333333);
        u32 o = h >> 7 & 3;
        i32 fx = (i32)(h >> 3 & 3) + 6 + (i32)start.x;
        if (fx < 0) fx = 0;
        i32 dy = (h & 1) ? (i32)o + 2 : -2 - (i32)o;
        i32 fy = dy + sy;
        if (fy < 0) fy = 0;
        if ((i32)g_map.h - 1 < fy) fy = (i32)g_map.h - 1;
        if ((i32)g_map.w - 1 < fx) fx = (i32)g_map.w - 1;
        if (gen_blob(g, z, v2u_make((u32)fx, (u32)fy), TILE_FLOWERS, (h >> 12 & 3) + 10, h, 0, 1)) break;
    }
}

// 0x140009290: scatter `count` deposits across the map
static void gen_deposits(WorldGen *g, const ZoneList *z, u8 tile, u32 count, u32 minsz, u32 maxsz, u32 salt) {
    if (!(g_map.w > 14 && g_map.h > 10 && g_map.w > 13 && g_map.h > 6)) return;
    u32 ry = g_map.h - 6, rx = g_map.w - 13;
    for (u32 i = 0; i < count; i++) {
        for (u32 a = 0; a < 0x60; a++) {
            u32 h = (i * 0x9e3779b9u) ^ g->seed ^ (a * 0x85ebca6bu) ^ salt;
            h = (h >> 16 ^ h) * 0x45d9f3b;
            h = (h >> 16 ^ h) * 0x45d9f3b;
            u32 hf = h >> 16 ^ h;
            V2u c = v2u_make(hf % rx + 10, (hf >> 12) % ry + 3);
            if (gen_blob(g, z, c, tile, (h >> 24) % ((maxsz - minsz) + 1) + minsz, hf ^ salt, 1, 1)) break;
        }
    }
}

// 0x140007e00: make sure there are flowers within reach of the start
static void gen_start_flowers(WorldGen *g, const ZoneList *z, V2u start) {
    i32 y0 = MAX((i32)start.y - 12, 0), y1 = MIN((i32)start.y + 12, (i32)g_map.h - 1);
    i32 x0 = MAX((i32)start.x - 12, 0), x1 = MIN((i32)start.x + 12, (i32)g_map.w - 1);
    for (i32 y = y0; y <= y1; y++)
        for (i32 x = x0; x <= x1; x++)
            if (get_tile((u32)x, (u32)y) == TILE_FLOWERS) return;
    for (u32 a = 0; a < 16; a++) {
        u32 h = hash_mix(a * 0x85ebca6bu ^ g->seed ^ 0xf10a0f55);
        u32 dyo = h >> 9 & 5;
        i32 x = (i32)(h >> 4 & 5) + 6 + (i32)start.x;
        if (x < 0) x = 0;
        i32 dy = (h & 2) ? (i32)dyo - 2 : 2 - (i32)dyo;
        i32 y = dy + (i32)start.y;
        if (y < 0) y = 0;
        if ((i32)g_map.h - 1 < y) y = (i32)g_map.h - 1;
        if ((i32)g_map.w - 1 < x) x = (i32)g_map.w - 1;
        if (gen_blob(g, z, v2u_make((u32)x, (u32)y), TILE_FLOWERS, (h >> 13 & 3) + 0xb, h, 0, 1)) return;
    }
}

// 0x140008ac0: generate the whole map around the starting home
void world_generate(u32 *seed_out, void *zones_v, V2u start) {
    static WorldGen g;
    ZoneList *z = zones_v;
    f64 t = time_now();
    u32 s = (g_map.w * 0x1003) ^ (g_map.h * 0x83) ^ (u32)(i64)(t * 1000000.0) ^ 0xc5e4f123;
    g.seed = hash_mix(s);
    *seed_out = g.seed;
    z->arena = &g_arena;
    z->count = 0;
    if (z->cap == 0) da_grow_(z, sizeof(Home), 4);
    z->data[z->count++] = (Home){start, 1};
    u32 n = MIN(g_map.w * g_map.h, 0x10000u);
    memset(g.taken, 0, n);
    memset(g.clear, 0, n);
    gen_coast(&g);
    if (g_map.w >= 0x18 && g_map.h >= 0x12) {
        u32 rivers = (g.seed & 1) + 7;
        for (u32 r = 0; r < rivers; r++) {
            for (u32 a = 0; a < 0x18; a++) {
                u32 h = hash_mix((r * 0x9e3779b9u) ^ (a * 0x85ebca6bu) ^ g.seed ^ 0x6d2b79f5);
                u32 cx = h % MAX(g_map.w >> 1, 1u) + g_map.w / 3;
                u32 cy = (h >> 11) % MAX(g_map.h - 8, 1u) + 4;
                V2u c = v2u_make(cx, cy);
                if (cell_free(z, c)) {
                    gen_river(&g, z, c, (h >> 22 & 0xd) + 0xb, (f32)(h >> 18 & 7) * 0.159999996f + 1.45000005f, h);
                    break;
                }
            }
        }
        gen_smooth_lakes(&g, z);
    }
    gen_start_resources(&g, z, start);
    gen_deposits(&g, z, TILE_IRON, 3, 7, 0xc, 0x51a91d1d);
    gen_deposits(&g, z, TILE_COPPER, 3, 7, 0xc, 0xc0ffee11);
    gen_deposits(&g, z, TILE_FLOWERS, 4, 8, 0xe, 0xf10a0f55);
    gen_start_flowers(&g, z, start);
}
