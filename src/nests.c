// Junk nests on TILE_NEST cells: every 30-250 seconds one produces a random
// item that seagulls can harvest (up to three waiting at a time).
#include "game.h"

Nest *g_bees;
u32 g_bee_count;
Rng g_rng;

static const u8 k_nest_loot[11] = {ITEM_FEATHER, ITEM_FEATHER, ITEM_FEATHER, ITEM_IRON_ORE, ITEM_IRON_ORE,
                                   ITEM_COPPER_ORE, ITEM_COPPER_ORE, ITEM_SEAGULL, ITEM_SEAGULL, ITEM_GEAR,
                                   ITEM_URANIUM};

static i32 nest_find(V2u p) {
    for (u32 i = 0; i < g_bee_count; i++)
        if (g_bees[i].pos.x == p.x && g_bees[i].pos.y == p.y) return (i32)i;
    return -1;
}

// 0x140012d40
void nest_add(V2u p) {
    if (nest_find(p) >= 0) return;
    Nest *n = &g_bees[g_bee_count];
    memset(n, 0, sizeof *n);
    n->pos = p;
    u64 r = rng_next(&g_rng);
    n->timer = (f32)(r % 0xdd + 0x1e);
    g_bee_count++;
}

// 0x1400149b0
void nest_remove(V2u p) {
    i32 i = nest_find(p);
    if (i < 0) return;
    g_bees[i] = g_bees[g_bee_count - 1];
    g_bee_count--;
}

// 0x14001c540: keep the nest list in sync with the tile at a cell
void nest_sync(V2u p) {
    if (p.x < g_map.w && p.y < g_map.h && g_tiles[p.y * g_map.w + p.x] == TILE_NEST) nest_add(p);
    else nest_remove(p);
}

// 0x140003c20
void nests_update(f32 dt) {
    for (u32 k = 0; k < g_bee_count; k++) {
        Nest *n = &g_bees[k];
        f32 t = n->timer - dt;
        n->timer = t;
        if (0.0f >= t) {
            u64 r1 = rng_next(&g_rng);
            n->timer = (f32)(r1 % 0xdd + 0x1e);
            if (n->count != 3) {
                u64 r2 = rng_next(&g_rng);
                // the original also peeks two values ahead without storing the state
                u64 *s = g_rng.s;
                u64 r3 = rng_mix23(s[0] + s[3]) + s[0];
                u64 tt = s[3] ^ s[1];
                u64 s0b = tt ^ s[0];
                u64 s3b = rotl64(tt, 45);
                u64 r4 = rng_mix23(s3b + s0b) + s0b;
                NestItem *p = &n->p[n->count];
                p->x = ((f32)n->pos.x + (f32)(r3 % 1000) / 1000.0f) - 0.5f;
                p->y = ((f32)n->pos.y + (f32)(r4 % 1000) / 1000.0f) - 0.5f;
                p->item = k_nest_loot[r2 % 11];
                memset(p->pad, 0, sizeof p->pad);
                p->life = 100.0f;
                n->count++;
            }
        }
        for (u32 i = 0; i < n->count;) {
            f32 l = n->p[i].life - dt;
            n->p[i].life = l;
            if (0.0f < l) {
                i++;
            } else {
                n->p[i] = n->p[n->count - 1];
                n->count--;
            }
        }
    }
}
