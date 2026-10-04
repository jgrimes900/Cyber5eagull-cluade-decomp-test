// Creating seagull orders, and the breadth-first path finder they fly along.
#include "game.h"

static inline b32 in_map(u32 x, u32 y) { return x < g_map.w && y < g_map.h; }
static inline u8 tile_at(u32 x, u32 y) { return in_map(x, y) ? g_tiles[y * g_map.w + x] : 0; }

// Path finder scratch buffers (static in the original: 0x14012bb40, 0x1400ebb40, 0x14013bb40, 0x1401bbb40)
static u8 s_visited[0x10000];
static u32 s_parent[0x10000];
static V2u s_queue[0x10000];
static V2u s_path[0x400];

// 0x140008210: BFS over the map (cliffs and water block), returning only the corner points
b32 find_path(V2u from, V2u to, V2u *out, u32 *count, u32 max, void *user) {
    (void)user;
    *count = 0;
    if (!in_map(from.x, from.y) || !in_map(to.x, to.y) || max == 0) return 0;
    if (from.x == to.x && from.y == to.y) {
        out[0] = from;
        *count = 1;
        return 1;
    }
    u32 w = g_map.w, h = g_map.h;
    u32 n = h * w;
    memset(s_visited, 0, n);
    if (n) memset(s_parent, 0xff, (u64)n * 4);
    u32 to_i = to.y * w + to.x;
    s_queue[0] = from;
    s_visited[from.y * w + from.x] = 1;
    u32 qn = 1, qi = 0;
    do {
        V2u cur = s_queue[qi];
        qi++;
        if (cur.x == to.x && cur.y == to.y) break;
        i32 dx = (i32)(to.x - cur.x), dy = (i32)(to.y - cur.y);
        u8 hx = dx >= 0 ? 1 : 3, ohx = dx >= 0 ? 3 : 1;
        u8 vy = dy >= 0 ? 2 : 0, ovy = dy >= 0 ? 0 : 2;
        u8 order[4];
        i32 adx = dx < 0 ? -dx : dx, ady = dy < 0 ? -dy : dy;
        if (adx < ady) {
            order[0] = vy; order[1] = hx; order[2] = ohx; order[3] = ovy;
        } else {
            order[0] = hx; order[1] = vy; order[2] = ovy; order[3] = ohx;
        }
        for (int k = 0; k < 4; k++) {
            V2u nb = step_dir(cur, order[k]);
            if (!in_map(nb.x, nb.y)) continue;
            u32 ni = nb.y * w + nb.x;
            if (s_visited[ni]) continue;
            b32 ok = (nb.x == from.x && nb.y == from.y) || (nb.x == to.x && nb.y == to.y) || nb.y >= h;
            if (!ok) {
                u8 t = g_tiles[ni];
                ok = t != TILE_CLIFF && t != TILE_WATER;
            }
            if (!ok) continue;
            s_visited[ni] = 1;
            s_parent[ni] = cur.y * w + cur.x;
            s_queue[qn++] = nb;
        }
    } while (qi < qn);
    if (!s_visited[to_i]) return 0;
    static V2u tmp[0x400];
    memset(tmp, 0, sizeof tmp);
    u32 k = 0, last = 0;
    u32 idx = to_i;
    if ((i32)to_i < 0) return 0;
    for (;;) {
        last = k;
        if (k > 0x3ff) return 0;
        tmp[k++] = v2u_make(idx % w, idx / w);
        u32 p = s_parent[idx];
        idx = p;
        if ((i32)p < 0) break;
    }
    for (u32 i = 0; i < k; i++) s_path[i] = tmp[k - 1 - i];
    u32 m = 1;
    out[0] = s_path[0];
    if (k > 1) {
        i32 ddx = (i32)(s_path[1].x - s_path[0].x), ddy = (i32)(s_path[1].y - s_path[0].y);
        for (u32 i = 2; i < k; i++) {
            i32 cdx = (i32)(s_path[i].x - s_path[i - 1].x);
            i32 cdy = (i32)(s_path[i].y - s_path[i - 1].y);
            if (cdx != ddx || cdy != ddy) {
                if (max <= m) return 0;
                out[m++] = s_path[i - 1];
                ddx = cdx;
                ddy = cdy;
            }
        }
        if (max <= m) return 0;
        out[m++] = s_path[last];
    }
    *count = m;
    return 1;
}

// 0x14001c630: can any home reach the cell?
static b32 reachable_from_home(V2u c) {
    static V2u buf[0x400];
    if (g_homes.count == 0) return 0;
    memset(buf, 0, sizeof buf);
    for (u32 i = 0; i < g_homes.count; i++) {
        Home *h = &g_homes.data[i];
        u32 r = h->big ? 0x14 : 9;
        if (home_in_range(c, h, r)) {
            u32 n;
            if (find_path(h->pos, c, buf, &n, 0x400, NULL)) return 1;
        }
    }
    return 0;
}

// 0x14001cac0: can seagulls harvest this cell?
b32 can_harvest(V2u c) {
    if (!in_map(c.x, c.y)) return 0;
    if (g_layers != 0 && (i32)c.x >= 0 && (i32)c.y >= 0) {
        u32 slot = g_ent_grid[c.y * g_map.w + c.x];
        if (slot != 0 && slot < g_entities.count && g_entities.data[slot]) return 0;
    }
    if (!near_any_home(c) || home_index_at(c) >= 0) return 0;
    u8 t = tile_at(c.x, c.y);
    if (t != TILE_IRON && t != TILE_COPPER && t != TILE_FLOWERS && t != TILE_NEST) return 0;
    return cell_has_resource(c) && reachable_from_home(c);
}

static i32 active_order_at(Flock *f, V2i c) {
    for (u32 i = 0; i < f->orders.count; i++) {
        Order *o = &f->orders.data[i];
        if (o->active && o->a.x == c.x && o->a.y == c.y) return (i32)i;
    }
    return -1;
}

// 0x140013530: add (or replace) the order for a cell
i32 order_add(Flock *f, const Order *src) {
    if (src->kind == 0) return -1;
    i32 i = active_order_at(f, src->a);
    if (i >= 0) {
        memcpy(&f->orders.data[i], src, 0x20);
        return i;
    }
    da_reserve_one(&f->orders, 4);
    Order *o = &f->orders.data[f->orders.count];
    memset(o, 0, sizeof *o);
    o->f1c = 1;
    o->assigned = -1;
    u32 idx = f->orders.count++;
    o = &f->orders.data[idx];
    memcpy(o, src, 0x20);
    o->assigned = -1;
    o->active = 1;
    flock_assign_orders(f);
    return (i32)(f->orders.count - 1);
}

static Order make_order(u8 kind, V2i a) {
    Order o;
    memset(&o, 0, sizeof o);
    o.kind = kind;
    o.a = a;
    return o;
}

// 0x140013770: send a seagull to harvest a cell
void order_harvest(V2u c) {
    if (!can_harvest(c)) return;
    V2i ci = {(i32)c.x, (i32)c.y};
    if (active_order_at(&g_flock, ci) >= 0) return;
    Order o;
    memset(&o, 0, sizeof o);
    if (can_harvest(c)) {
        u8 t = tile_at(c.x, c.y);
        if (t == TILE_IRON || t == TILE_COPPER) {
            o = make_order(2, ci);
            o.duration = 8.0f;
            o.repeat = 1;
            o.f1c = 0;
        } else if (t == TILE_FLOWERS) {
            o = make_order(3, ci);
            o.duration = 6.0f;
            o.repeat = 1;
            o.f1c = 1;
        } else if (t == TILE_NEST) {
            o = make_order(1, ci);
            o.duration = 1.5f;
            o.repeat = 1;
            o.f1c = 1;
        } else {
            o.f1c = 1;
        }
    } else {
        o.f1c = 1;
    }
    if (o.kind) order_add(&g_flock, &o);
}

// 0x140013030: have a seagull pick up to `max` items from a conveyor
b32 order_take_from_conveyor(V2u c, u32 max) {
    if (!in_map(c.x, c.y) || max == 0) return 0;
    V2i ci = {(i32)c.x, (i32)c.y};
    for (u32 i = 0; i < g_pickups.count; i++)
        if ((u32)g_pickups.data[i].pos.x == c.x && (u32)g_pickups.data[i].pos.y == c.y) return 0;
    if (active_order_at(&g_flock, ci) >= 0) return 0;
    Entity *e = entity_at(c, 0);
    if (!e || !e->serial || e->type != 1) return 0;
    u8 *slot = *ent_out_count(e) == 0 ? (u8 *)e + 0x3c : (u8 *)e + 0x54;
    u32 have = *(u32 *)(slot + 4);
    if (have == 0) return 0;
    u32 n = have < max ? have : max;
    Order o = make_order(5, ci);
    o.duration = 0.150000006f;
    o.repeat = 0;
    o.f1c = 1;
    if (order_add(&g_flock, &o) < 0) return 0;
    Pickup p;
    memset(&p, 0, sizeof p);
    p.pos = ci;
    p.item = slot[0];
    p.count = n;
    p.seagull = -1;
    p.take = 1;
    da_push(&g_pickups, p, 4);
    return 1;
}

// 0x140013380: have seagulls ferry `item` from home onto a conveyor
b32 order_deliver(V2u c, u8 item, u32 count) {
    if (!in_map(c.x, c.y) || count == 0) return 0;
    Entity *e = entity_at(c, 0);
    if (!e || !e->serial || e->type != 1) return 0;
    V2i ci = {(i32)c.x, (i32)c.y};
    if (active_order_at(&g_flock, ci) >= 0) return 0;
    Order o = make_order(6, ci);
    o.b = ci;
    o.item = item;
    o.duration = 0.150000006f;
    o.repeat = 1;
    o.f1c = 0;
    if (order_add(&g_flock, &o) >= 0) return 1;
    if (item < g_items.count) g_items.data[item] += count;
    return 0;
}
