// Seagull jobs: harvesting ore, carrying items between conveyors and homes,
// and the per-frame simulation tick that reacts to flock events.
#include "game.h"

DARRAY(Pickup) g_pickups;   // 0x1400eaa08
u16 g_ore_iron[0x10000];    // 0x14004a9f0
u16 g_ore_copper[0x10000];  // 0x14006a9f0
u16 g_ore_flowers[0x10000]; // 0x14008a9f0
f32 g_honey_timer;          // 0x14004a9e4

static inline b32 in_map(u32 x, u32 y) { return x < g_map.w && y < g_map.h; }

// Conveyor (type 1) at a layer-0 cell, as the original inlines it
static Entity *conveyor_at(V2u c) {
    if (c.x < g_map.w && c.y < g_map.h && g_layers != 0 && (i32)c.x >= 0 && (i32)c.y >= 0) {
        u32 slot = g_ent_grid[c.y * g_map.w + c.x];
        if (slot != 0 && slot < g_entities.count) {
            Entity *e = g_entities.data[slot];
            if (e && e->serial && e->type == 1) return e;
        }
    }
    return NULL;
}

// 0x140014a30
void pickup_remove(u32 i) {
    if (i < g_pickups.count) {
        g_pickups.count--;
        for (; i < g_pickups.count; i++) g_pickups.data[i] = g_pickups.data[i + 1];
    }
}

static i32 pickup_find(V2i pos) {
    for (u32 i = 0; i < g_pickups.count; i++)
        if (g_pickups.data[i].pos.x == pos.x && g_pickups.data[i].pos.y == pos.y) return (i32)i;
    return -1;
}

// 0x14001dd40: cancel an order; its seagull (if any) drops everything and heads home
void cancel_order(Flock *f, u32 idx) {
    if (idx >= f->orders.count) return;
    Order o = f->orders.data[idx];
    i32 si = o.assigned;
    if (si >= 0 && (u32)si < f->gulls.count) {
        Seagull *s = &f->gulls.data[si];
        V2u home = s->home;
        f32 hx = (f32)home.x + s->home_off.x;
        f32 hy = (f32)home.y + s->home_off.y;
        memset(s->order, 0, 0x20);
        *(u32 *)(s->order + 0x1c) = 1;
        s->vel = v2(0, 0);
        f32 dx = s->pos.x - hx, dy = s->pos.y - hy;
        b32 at_home = dy * dy + dx * dx <= 9.99999975e-05f;
        s->busy = 0;
        s->work = 0;
        s->state = at_home ? SG_IDLE : SG_RETURNING;
        s->wobble_time = 0;
        s->path_count = s->path_idx = 0;
        s->path_goal = (V2u){0, 0};
        s->has_path = 0;
    }
    f->orders.count--;
    for (u32 i = idx; i < f->orders.count; i++) f->orders.data[i] = f->orders.data[i + 1];
    for (u32 i = 0; i < g_pickups.count; i++) {
        if (g_pickups.data[i].pos.x == o.a.x && g_pickups.data[i].pos.y == o.a.y) {
            pickup_remove(i);
            return;
        }
    }
}

// 0x14001df40 / 0x14001dfb0: cancel the first active order targeting a cell
void cancel_order_at(Flock *f, V2i cell) {
    for (u32 i = 0; i < f->orders.count; i++) {
        Order *o = &f->orders.data[i];
        if (o->active && o->a.x == cell.x && o->a.y == cell.y) {
            cancel_order(f, i);
            return;
        }
    }
}

// 0x140012080: step one cell in a direction (0 up, 1 right, 2 down, 3 left), clamped at 0
V2u step_dir(V2u p, u8 dir) {
    switch (dir) {
    case 0: p.y = p.y == 0 ? 0 : p.y - 1; break;
    case 1: p.x = p.x + 1; break;
    case 2: p.y = p.y + 1; break;
    case 3: p.x = p.x == 0 ? 0 : p.x - 1; break;
    }
    return p;
}

// 0x14001da50: push one item into a neighbouring conveyor/machine input
b32 insert_into_neighbour(V2u cell, u8 item, b32 enabled) {
    if (!enabled) return 0;
    V2u n[4] = {step_dir(cell, 0), step_dir(cell, 1), step_dir(cell, 2), step_dir(cell, 3)};
    for (int k = 0; k < 4; k++) {
        Entity *e = conveyor_at(n[k]);
        if (!e) continue;
        Recipe *r = e->recipe;
        if (!r) TRAP();
        u32 nin = r->n_in;
        if (nin == 0) {
            if (*ent_out_count(e) != 0 || *ent_in_count(e, 0) != 0) continue;
            *(u32 *)((u8 *)e + 0x3c) = item;
            *ent_in_count(e, 0) = 1;
            return 1;
        }
        u32 i = 0;
        for (; i < nin; i++)
            if (r->in[i].item == item) break;
        if (i == nin) continue;
        u32 need = r->in[i].count, have = *ent_in_count(e, i);
        if (need == have) continue;
        *ent_in_item(e, i) = item;
        *ent_in_count(e, i) = have + 1;
        return 1;
    }
    return 0;
}

// 0x14001dc40: drop `count` items onto the conveyor at a cell
b32 insert_into_conveyor(V2u cell, u8 item, u32 count) {
    Entity *e = conveyor_at(cell);
    if (!e || count == 0) return 0;
    u8 *slot = *ent_out_count(e) != 0 ? (u8 *)e + 0x54 : (u8 *)e + 0x3c;
    u32 have = *(u32 *)(slot + 4);
    if (have == 0 || slot[0] == item) {
        u32 space = 0;
        if (have < (u32)e->f64) space = (u32)e->f64 - have;
        if (count <= space) {
            if (have == 0) slot[0] = item;
            *(u32 *)(slot + 4) = have + count;
            return 1;
        }
    }
    return 0;
}

static Nest *nest_at(V2u c) {
    for (u32 i = 0; i < g_bee_count; i++)
        if (g_bees[i].pos.x == c.x && g_bees[i].pos.y == c.y) return &g_bees[i];
    return NULL;
}

// 0x140006380: take one unit of resource from a map cell
b32 harvest_cell(V2u c, u8 *item_out) {
    if (!in_map(c.x, c.y)) return 0;
    u32 i = c.y * g_map.w + c.x;
    u8 t = g_tiles[i];
    u16 *ore = NULL;
    u8 item = 0;
    if (t == TILE_IRON) ore = g_ore_iron, item = ITEM_IRON_ORE;
    else if (t == TILE_COPPER) ore = g_ore_copper, item = ITEM_COPPER_ORE;
    else if (t == TILE_FLOWERS) ore = g_ore_flowers, item = ITEM_POLLEN;
    else if (t == TILE_NEST) {
        Nest *n = nest_at(c);
        if (!n || n->count == 0) return 0;
        n->count--;
        *item_out = n->p[n->count].item;
        return 1;
    } else {
        return 0;
    }
    if (ore[i] == 0) return 0;
    ore[i]--;
    if (item_out) *item_out = item;
    if (ore[i] == 0 && in_map(c.x, c.y)) g_tiles[c.y * g_map.w + c.x] = TILE_GRASS;
    return 1;
}

// 0x14001c7a0: is there anything left to harvest here?
b32 cell_has_resource(V2u c) {
    if (!in_map(c.x, c.y)) return 0;
    u32 i = c.y * g_map.w + c.x;
    u8 t = g_tiles[i];
    if (t == TILE_IRON) return g_ore_iron[i] != 0;
    if (t == TILE_COPPER) return g_ore_copper[i] != 0;
    if (t == TILE_FLOWERS) return g_ore_flowers[i] != 0;
    if (t == TILE_NEST) {
        Nest *n = nest_at(c);
        return n && n->count != 0;
    }
    return 0;
}

// 0x1400086a0: index of the home covering a cell, or -1
i32 home_index_at(V2u c) {
    for (u32 i = 0; i < g_homes.count; i++) {
        Home *h = &g_homes.data[i];
        u32 sz = h->big ? 2 : 1;
        if (h->pos.x <= c.x && h->pos.y <= c.y && c.x < h->pos.x + sz && c.y < sz + h->pos.y) return (i32)i;
    }
    return -1;
}

// 0x14000a170: a seagull finished its job (flock event 3)
static void on_job_done(FlockEvent *ev) {
    if (ev->seagull >= g_flock.gulls.count) TRAP();
    Seagull *s = &g_flock.gulls.data[ev->seagull];
    Order *so = SG_ORDER(s);
    if (so->kind == 6) {  // ferry an item from a home to a conveyor
        V2u a = {(u32)so->a.x, (u32)so->a.y};
        if (s->carry_count != 0 && insert_into_conveyor(a, s->carry_item, s->carry_count)) {
            s->carry_item = 0xc;
            s->carry_count = 0;
            HomeTarget ht;
            nearest_home(&ht, a);
            so->a.x = (i32)ht.cell.x;
            so->a.y = (i32)ht.cell.y;
            s->vel = v2(0, 0);
            s->state = SG_TO_JOB;
            return;
        }
        if (s->carry_count != 0) return;
        if (home_index_at(a) == -1) return;
        u8 it = so->item;
        if (it >= g_items.count || g_items.data[it] == 0) return;
        g_items.data[it]--;
        s->carry_item = it;
        so->a = so->b;
        s->vel = v2(0, 0);
        s->carry_count = 1;
        s->state = SG_TO_JOB;
        return;
    }
    Order *eo = (Order *)ev->order;
    V2i ea = eo->a;
    V2u eau = {(u32)ea.x, (u32)ea.y};
    i32 pi = pickup_find(ea);
    if (pi >= 0) {
        Pickup p = g_pickups.data[pi];
        HomeTarget ht;
        nearest_home(&ht, eau);
        s->home = ht.cell;
        s->home_off = ht.off;
        s->path_count = s->path_idx = 0;
        s->path_goal = (V2u){0, 0};
        s->has_path = 0;
        if (p.take != 1) {
            if (s->carry_count == 0) {
                s->carry_item = p.item;
                s->carry_count = p.count;
            }
            if (insert_into_conveyor(eau, p.item, p.count)) {
                s->carry_item = 0xc;
                s->carry_count = 0;
                pickup_remove((u32)pi);
                return;
            }
            s->state = SG_RETURNING;
            s->vel = v2(0, 0);
            pickup_remove((u32)pi);
            return;
        }
        u32 taken = 0;
        u8 it = 0xc;
        Entity *e = p.count ? conveyor_at(eau) : NULL;
        if (e) {
            u8 *slot = *ent_out_count(e) == 0 ? (u8 *)e + 0x3c : (u8 *)e + 0x54;
            u32 have = *(u32 *)(slot + 4);
            if (have != 0) {
                taken = have;
                if (p.count < have) taken = p.count;
                *(u32 *)(slot + 4) = have - taken;
                it = slot[0];
            }
        }
        s->carry_item = it;
        s->carry_count = taken;
        pickup_remove((u32)pi);
        cancel_order_at(&g_flock, ea);
        return;
    }
    u8 item = 0;
    if (!harvest_cell(eau, &item)) {
        cancel_order_at(&g_flock, ea);
        s->carry_item = 0xc;
        s->carry_count = 0;
        return;
    }
    b32 more = cell_has_resource(eau);
    HomeTarget ht;
    nearest_home(&ht, eau);
    if ((eo->kind == 2 || eo->kind == 3) && so->f1c == 0) {
        if (insert_into_neighbour(eau, item, 1)) {
            s->carry_item = 0xc;
            s->carry_count = 0;
            goto done;
        }
        s->home = ht.cell;
        s->vel = v2(0, 0);
        s->carry_item = item;
        s->state = SG_RETURNING;
    } else {
        s->home = ht.cell;
        s->carry_item = item;
    }
    s->home_off = ht.off;
    s->path_count = s->path_idx = 0;
    s->path_goal = (V2u){0, 0};
    s->has_path = 0;
    s->carry_count = 1;
done:
    if (!more) cancel_order_at(&g_flock, ea);
}

// 0x140005840: drop pickups whose conveyor vanished or was emptied
static void process_pickups(void) {
    u32 n = g_pickups.count;
    for (u32 i = n; i-- > 0;) {
        if (i >= g_pickups.count) TRAP();
        Pickup *p = &g_pickups.data[i];
        if (p->seagull >= 0) continue;
        V2u c = {(u32)p->pos.x, (u32)p->pos.y};
        Entity *e = conveyor_at(c);
        if (e) {
            if (p->take != 1) continue;
            u32 *cnt = *ent_out_count(e) == 0 ? ent_in_count(e, 0) : ent_out_count(e);
            if (*cnt != 0) continue;
        } else if (p->take == 0) {
            if (p->item < g_items.count && p->count) g_items.data[p->item] += p->count;
        }
        cancel_order_at(&g_flock, p->pos);
        pickup_remove(i);
    }
}

// 0x14001f730: idle seagulls at home slowly turn pollen into honey
static void idle_make_honey(f32 dt) {
    if (!(0.0f < dt)) return;
    u32 idle = 0;
    for (u32 i = 0; i < g_flock.gulls.count; i++) {
        Seagull *s = &g_flock.gulls.data[i];
        if (s->state || s->busy) continue;
        f32 dx = s->pos.x - ((f32)s->home.x + s->home_off.x);
        f32 dy = s->pos.y - ((f32)s->home.y + s->home_off.y);
        if (9.99999975e-05f < dy * dy + dx * dx) continue;
        idle++;
    }
    if (!idle || g_items.count <= 11 || g_items.data[ITEM_POLLEN] <= 2) return;
    g_honey_timer = (f32)idle * dt + g_honey_timer;
    while (10.0f <= g_honey_timer && g_items.count > 11 && g_items.data[ITEM_POLLEN] > 2) {
        g_honey_timer = g_honey_timer + -10.0f;
        g_items.data[ITEM_POLLEN] -= 3;
        if (g_items.count > 12) g_items.data[ITEM_HONEY] += 1;
    }
}

// 0x14001e410: one simulation step for seagulls and their jobs
void jobs_tick(f32 dt) {
    process_pickups();
    flock_update(&g_flock, dt);
    for (u32 k = 0; k < g_flock.events.count; k++) {
        FlockEvent *ev = &g_flock.events.data[k];
        if (ev->seagull >= g_flock.gulls.count) continue;
        Seagull *s = &g_flock.gulls.data[ev->seagull];
        Order *eo = (Order *)ev->order;
        if (ev->type == 1) {
            i32 pi = pickup_find(eo->a);
            if (pi < 0) continue;
            Pickup *p = &g_pickups.data[pi];
            p->seagull = (i32)ev->seagull;
            if (p->take == 0) {
                s->carry_item = p->item;
                s->carry_count = p->count;
            } else {
                s->carry_item = 0xc;
                s->carry_count = 0;
            }
        } else if (ev->type == 3) {
            on_job_done(ev);
        } else if (ev->type == 4) {
            if (s->carry_count != 0) {
                if (s->carry_item < g_items.count) g_items.data[s->carry_item] += s->carry_count;
                s->carry_item = 0xc;
                s->carry_count = 0;
            }
        }
    }
    idle_make_honey(dt);
}
