// Placing and removing things on the map: building definitions, footprint
// checks, the conveyor drag tool, terrain painting (sandbox) tools, and the
// translucent placement preview under the cursor.
#include "game.h"

static inline b32 in_map(u32 x, u32 y) { return x < g_map.w && y < g_map.h; }

// Direction helpers (0 left, 1 right, 2 up, 3 down)
static const i32 k_opposite[4] = {1, 0, 3, 2};   // 0x140029000
static const i32 k_rot_dir[4] = {2, 1, 3, 0};    // 0x140029010 rotation -> direction

// Building kind (entity type) <-> build-menu id
static u8 type_to_id(i32 type) { return (type >= 1 && type <= 10) ? (u8)(type + 9) : 0; }
static u32 id_to_type(u8 id) { return (id >= 10 && id <= 19) ? (u32)(id - 9) : 0; }

// ---------------------------------------------------------------------------
// Homes

// 0x14000a5d0: is the cell covered by a home?
b32 in_home(V2u c) {
    for (u32 i = 0; i < g_homes.count; i++) {
        Home *h = &g_homes.data[i];
        if (c.x == h->pos.x && c.y == h->pos.y) return 1;
        if (h->big) {
            if (c.x == h->pos.x && c.y == h->pos.y + 1) return 1;
            if (c.x == h->pos.x + 1 && (c.y == h->pos.y || c.y == h->pos.y + 1)) return 1;
        }
    }
    return 0;
}

static void home_remove_index(i32 idx) {
    u32 i = (u32)idx;
    if (i < g_home_flags.count) {
        if (i >= g_home_flags.count) TRAP();
        if (g_home_flags.data[i]) {
            if (i >= g_homes.count) TRAP();
            refund_build((g_homes.data[i].big != 0) + 20);
        }
    }
    g_homes.count--;
    for (; i < g_homes.count; i++) g_homes.data[i] = g_homes.data[i + 1];
    i = (u32)idx;
    if (i < g_home_flags.count) {
        g_home_flags.count--;
        for (; i < g_home_flags.count; i++) g_home_flags.data[i] = g_home_flags.data[i + 1];
    }
}

// 0x140014a90: remove the home covering a cell (refunding it if it was paid for)
void home_remove_at(V2u c) {
    i32 idx = home_index_at(c);
    if (idx >= 0) home_remove_index(idx);
}

// 0x140005be0
static void homes_remove_in(V2u at, V2u size) {
    for (u32 y = 0; y < size.y; y++)
        for (u32 x = 0; x < size.x; x++) {
            i32 idx = home_index_at(v2u_make(at.x + x, at.y + y));
            if (idx >= 0) home_remove_index(idx);
        }
}

// 0x1400052a0: can a home of this size go here?
static b32 home_area_free(V2u at, V2u size) {
    if (size.x + at.x > g_map.w) return 0;
    if (at.y + size.y > g_map.h) return 0;
    for (u32 j = 0, y = at.y; j < size.y; j++, y++) {
        for (u32 x = at.x; x - at.x < size.x; x++) {
            if (x >= g_map.w || y >= g_map.h || g_layers == 0) return 0;
            u8 t = 0;
            if ((i32)x >= 0 && (i32)y >= 0) {
                t = g_tiles[y * g_map.w + x];
                if (g_ent_grid[y * g_map.w + x] != 0) return 0;
            }
            if (t != TILE_GRASS && t != TILE_5) return 0;
            if ((u8)(g_tiles[y * g_map.w + x] - 7) < 2) return 0;
            if ((i32)x >= 0 && (i32)y >= 0) {
                u32 slot = g_ent_grid[y * g_map.w + x];
                if (slot != 0 && slot < g_entities.count && g_entities.data[slot]) return 0;
            }
            if (in_home(v2u_make(x, y))) return 0;
        }
    }
    return 1;
}

// 0x140012520: build a home (big = 2x2)
static b32 place_home(V2u at, b32 big, b32 check_near) {
    V2u size = big ? v2u_make(2, 2) : v2u_make(1, 1);
    if (!home_area_free(at, size)) return 0;
    if (check_near && !near_any_home(at)) return 0;
    cancel_orders_in(at, size);
    demolish_area(at, 0, size);
    homes_remove_in(at, size);
    Home h = {at, (u32)big};
    da_push(&g_homes, h, 4);
    da_push(&g_home_flags, (u32)check_near, 4);
    return 1;
}

// ---------------------------------------------------------------------------
// Area helpers

// 0x140005d80: demolish every entity in a rectangle, refunding paid ones
void demolish_area(V2u at, u32 layer, V2u size) {
    for (u32 y = 0; y < size.y; y++)
        for (u32 x = 0; x < size.x; x++) demolish_at(v2u_make(at.x + x, at.y + y), layer);
}

// 0x140014fd0
void demolish_at(V2u c, u32 layer) {
    Entity *e = entity_at(c, layer);
    if (!e) return;
    if (e->serial && e->slot < 0x10000 && g_paid[e->slot]) refund_build(type_to_id(e->type));
    if (e->serial && e->slot < 0x10000) g_paid[e->slot] = 0;
    entity_destroy(e);
}

// 0x140005f00: cancel seagull orders in a rectangle
void cancel_orders_in(V2u at, V2u size) {
    for (u32 y = 0; y < size.y; y++)
        for (u32 x = 0; x < size.x; x++) {
            for (u32 i = 0; i < g_flock.orders.count; i++) {
                Order *o = &g_flock.orders.data[i];
                if (o->active && o->a.x == (i32)(at.x + x) && o->a.y == (i32)(at.y + y)) {
                    if ((i32)i >= 0) cancel_order(&g_flock, i);
                    break;
                }
            }
        }
}

static V2u kind_size(u32 kind) {
    switch (kind) {
    case 3: return v2u_make(2, 2);
    case 4: return v2u_make(3, 2);
    default: return v2u_make(1, 1);
    }
}

// 0x1400054e0: can a building of this kind go here (rotation is ignored)?
static b32 building_area_ok(V2u at, u32 layer, u32 kind, u32 rotation, b32 paid) {
    (void)rotation;
    V2u size = kind_size(kind);
    if (size.x + at.x > g_map.w) return 0;
    if (size.y + at.y > g_map.h) return 0;
    if (layer == 0) {
        if (kind == 8) return 0;
    } else if (!(kind < 10 && ((0x322u >> kind) & 1))) {
        return 0;
    }
    for (u32 j = 0, y = at.y; j < size.y; j++, y++) {
        for (u32 x = at.x; x - at.x < size.x; x++) {
            if (x < g_map.w && y < g_map.h) {
                u8 t = g_tiles[y * g_map.w + x];
                if (t == TILE_CLIFF || t == TILE_WATER) return 0;
            }
            if (!cell_buildable(v2u_make(x, y), layer)) return 0;
            if (layer == 0 && paid && in_home(v2u_make(x, y))) return 0;
        }
    }
    return 1;
}

// ---------------------------------------------------------------------------
// Building definitions

static EntityDef def_blank(i32 type) {
    EntityDef d;
    memset(&d, 0, sizeof d);
    d.type = type;
    d.w = 1;
    d.h = 1;
    d.f20 = 1;
    d.f24 = 1;
    return d;
}

static void set_port(EntityDef *d, u32 i, i32 x, i32 y, u8 dirs) {
    d->ports[i].x = x;
    d->ports[i].y = y;
    d->ports[i].dirs = dirs;
}

// 0x140009470: conveyor with an output direction and an input direction
EntityDef conveyor_def(i32 out, i32 in) {
    EntityDef d = def_blank(1);
    u8 ob = out == 0 ? 4 : out == 1 ? 8 : out == 2 ? 1 : out == 3 ? 2 : 0;
    u8 ib = in == 0 ? 0x40 : in == 1 ? 0x80 : in == 2 ? 0x10 : in == 3 ? 0x20 : 0;
    set_port(&d, 0, 0, 0, ib | ob);
    d.recipes = (RecipeList *)&g_recipes_conveyor;
    static const u64 k_spr[4][4] = {
        {0, 0x1400ead00, 0x1400ead20, 0x1400ead40},
        {0x1400ead60, 0, 0x1400ead80, 0x1400eada0},
        {0x1400eade0, 0x1400eae00, 0, 0x1400eadc0},
        {0x1400eace0, 0x1400eacc0, 0x1400eaca0, 0},
    };
    if (out >= 0 && out < 4 && in >= 0 && in < 4 && k_spr[out][in]) d.sprite = SPR(k_spr[out][in]);
    return d;
}

// 0x14001a610: rotate a port inside a w x h footprint by 90 degree steps
static Port rotate_port(Port p, V2u size, i32 rot) {
    static const u8 k_map[4][8] = {
        {1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80},
        {8, 4, 1, 2, 0x80, 0x40, 0x10, 0x20},
        {2, 1, 8, 4, 0x20, 0x10, 0x80, 0x40},
        {4, 8, 2, 1, 0x40, 0x80, 0x20, 0x10},
    };
    Port r;
    if (rot < 0 || rot > 3) {
        r.x = p.x;
        r.y = p.y;
        r.dirs = 0;
        return r;
    }
    u8 b = 0;
    for (int i = 0; i < 8; i++)
        if (p.dirs & (1u << i)) b |= k_map[rot][i];
    r.dirs = b;
    switch (rot) {
    case 0: r.x = p.x; r.y = p.y; break;
    case 1: r.x = (i32)size.y - p.y - 1; r.y = p.x; break;
    case 2: r.x = (i32)size.x - p.x - 1; r.y = (i32)size.y - p.y - 1; break;
    default: r.x = p.y; r.y = (i32)size.x - p.x - 1; break;
    }
    return r;
}

static Port port(i32 x, i32 y, u8 dirs) {
    Port p;
    p.x = x;
    p.y = y;
    p.dirs = dirs;
    return p;
}

// 0x1400096c0: the 3x2 assembler
static EntityDef assembler_def(i32 rot) {
    EntityDef d = def_blank(4);
    d.w = 3;
    d.h = 2;
    static const u64 k_spr[4][2] = {{0x1400eb580, 0x1400eb5a0},
                                    {0x1400eb600, 0x1400eb620},
                                    {0x1400eb5c0, 0x1400eb5e0},
                                    {0x1400eb640, 0x1400eb660}};
    if (rot < 0 || rot > 3) TRAP();
    d.sprite = SPR(k_spr[rot][0]);
    d.sprite2 = SPR(k_spr[rot][1]);
    d.f20 = 10;
    V2u size = v2u_make(3, 2);
    d.ports[0] = rotate_port(port(0, 1, 2), size, rot);
    d.ports[1] = rotate_port(port(1, 1, 2), size, rot);
    d.ports[2] = rotate_port(port(2, 1, 2), size, rot);
    d.ports[3] = rotate_port(port(1, 0, 0x10), size, rot);
    if (rot == 1 || rot == 3) {
        d.w = 2;
        d.h = 3;
    }
    d.recipes = (RecipeList *)&g_recipes_assembler;
    return d;
}

// 0x140009a60: definition for a building kind (entity type) and rotation
EntityDef building_def(u32 kind, i32 rot) {
    EntityDef d = def_blank((i32)kind);
    switch (kind) {
    case 2: {  // furnace
        u8 dirs = rot == 1 ? 0x84 : rot == 2 ? 0x21 : rot == 3 ? 0x48 : 0x12;
        d.f20 = 6;
        d.sprite = SPR(0x1400eb680);
        d.sprite2 = SPR(0x1400eb6a0);
        set_port(&d, 0, 0, 0, dirs);
        d.recipes = (RecipeList *)&g_recipes_furnace;
        break;
    }
    case 3: {  // 2x2 machine
        d.w = 2;
        d.h = 2;
        static const u64 k_spr[4][2] = {{0x1400eb220, 0x1400eb240},
                                        {0x1400eb2a0, 0x1400eb2c0},
                                        {0x1400eb260, 0x1400eb280},
                                        {0x1400eb2e0, 0x1400eb300}};
        if (rot >= 0 && rot < 4) {
            d.sprite = SPR(k_spr[rot][0]);
            d.sprite2 = SPR(k_spr[rot][1]);
        }
        d.f20 = 8;
        d.ports[0] = rotate_port(port(0, 1, 2), v2u_make(2, 2), rot);
        d.ports[1] = rotate_port(port(1, 1, 0x20), v2u_make(2, 2), rot);
        d.recipes = (RecipeList *)&g_recipes_machine;
        break;
    }
    case 4:
        d = assembler_def(rot);
        break;
    case 5:
    case 6:
        d.sprite = SPR(kind == 5 ? 0x1400eabe0 : 0x1400eac00);
        d.recipes = (RecipeList *)&g_recipes_conveyor;
        set_port(&d, 0, 0, 0, 0xff);
        break;
    case 7:
    case 8:
        d.sprite = SPR(kind == 7 ? 0x1400eae40 : 0x1400eae20);
        d.recipes = (RecipeList *)&g_recipes_conveyor;
        set_port(&d, 0, 0, 0, 0xf);
        break;
    case 9: {
        static const u64 k_spr[4] = {0x1400eae80, 0x1400eae60, 0x1400eaec0, 0x1400eaea0};
        if (rot >= 0 && rot < 4) d.sprite = SPR(k_spr[rot]);
        d.recipes = (RecipeList *)&g_recipes_conveyor;
        d.ports[0] = rotate_port(port(0, 0, 0x20), v2u_make(1, 1), rot);
        break;
    }
    case 10:
        d.recipes = (RecipeList *)&g_recipes_conveyor;
        d.sprite = SPR(0x1400eb6c0);
        break;
    }
    return d;
}

// ---------------------------------------------------------------------------
// Placement

static b32 footprint_buildable(V2u at, u32 layer, const EntityDef *d) {
    for (i32 y = (i32)at.y; y < d->h + (i32)at.y; y++)
        for (i32 x = (i32)at.x; x < d->w + (i32)at.x; x++)
            if (!cell_buildable(v2u_make((u32)x, (u32)y), layer)) return 0;
    return 1;
}

// 0x14001b880: create or reshape a conveyor
b32 set_conveyor(V2u c, u32 layer, i32 out, i32 in) {
    if (out == -1 || in == -1 || out == in) return 0;
    EntityDef d = conveyor_def(out, in);
    if (!d.sprite) return 0;
    Entity *e = entity_at(c, layer);
    if (!e) {
        if (!footprint_buildable(c, layer, &d)) return 0;
        EntityHandle h = entity_create(c, layer, &d);
        return handle_valid(h);
    }
    if (e->serial && e->type == 1) {
        entity_configure(e, &d);
        return 1;
    }
    return 0;
}

// 0x140012490: make sure there is a conveyor here, facing `rotation` if new
static b32 ensure_conveyor(V2u c, u32 layer, u32 rotation) {
    Entity *e = entity_at(c, layer);
    if (!e) {
        i32 d = k_rot_dir[rotation];
        return set_conveyor(c, layer, k_opposite[d], d);
    }
    return e->serial && e->type == 1;
}

// 0x140007b70
static b32 place_conveyor(V2u c, u32 layer, u32 rotation, b32 paid) {
    if (!in_map(c.x, c.y)) return 0;
    u8 t = g_tiles[c.y * g_map.w + c.x];
    if (t == TILE_CLIFF || t == TILE_WATER) return 0;
    Entity *e = entity_at(c, layer);
    if (e && e->serial && e->type == 1) return 1;
    if (entity_at(c, layer)) return 0;
    if (layer == 0) {
        if (paid && in_home(c)) return 0;
        cancel_order_at(&g_flock, (V2i){(i32)c.x, (i32)c.y});
        home_remove_at(c);
    }
    if (!ensure_conveyor(c, layer, rotation)) return 0;
    e = entity_at(c, layer);
    if (e && e->serial && e->slot < 0x10000) g_paid[e->slot] = (u32)paid;
    return 1;
}

// 0x1400127b0
static b32 place_building(V2u c, u32 layer, u32 kind, u32 rotation, b32 paid) {
    V2u size = kind_size(kind);
    if (!building_area_ok(c, layer, kind, rotation, paid)) return 0;
    if (layer == 0) {
        cancel_orders_in(c, size);
        homes_remove_in(c, size);
    }
    demolish_area(c, layer, size);
    if (kind == 1) {
        if (!ensure_conveyor(c, layer, rotation)) return 0;
    } else {
        EntityDef d = building_def(kind, (i32)rotation);
        if (!d.sprite) return 0;
        Entity *e = entity_at(c, layer);
        if (!e) {
            if (!footprint_buildable(c, layer, &d)) return 0;
            EntityHandle h = entity_create(c, layer, &d);
            if (!handle_valid(h)) return 0;
        } else {
            if ((u32)e->type != kind || e->pos.x != c.x || e->pos.y != c.y) return 0;
            entity_configure(e, &d);
        }
    }
    Entity *e = entity_at(c, layer);
    if (e && e->serial && e->slot < 0x10000) g_paid[e->slot] = (u32)paid;
    return 1;
}

// 0x140002700: dragging out a line of conveyors
static void conveyor_drag(void) {
    V2i cell = {0, 0};
    if (!cursor_cell(&cell)) return;
    u32 layer = g_layer;
    i32 prev_dir = g_drag_dir;
    if (g_have_last_cell && cell.x == g_last_cell.x && cell.y == g_last_cell.y) return;
    g_have_last_cell = 1;
    g_last_cell = cell;
    V2u c = v2u_make((u32)cell.x, (u32)cell.y);
    if (g_dragging_conveyor) {
        V2u dc = g_drag_cell;
        i32 dir;
        if ((u32)cell.x == dc.x + 1 && (u32)cell.y == dc.y) dir = 1;
        else if (dc.x != 0 && (u32)cell.x + 1 == dc.x && (u32)cell.y == dc.y) dir = 0;
        else if ((u32)cell.y == dc.y + 1 && (u32)cell.x == dc.x) dir = 3;
        else if (dc.y != 0 && (u32)cell.y + 1 == dc.y && (u32)cell.x == dc.x) dir = 2;
        else return;
        if (g_drag_dir == dir && !set_conveyor(g_drag_cell, layer, k_opposite[dir], dir)) return;
        set_conveyor(g_drag_cell, layer, prev_dir, dir);
        i32 back = k_opposite[dir];
        if (!place_conveyor(c, layer, g_rotation, g_place_paid == 0)) return;
        if (!set_conveyor(c, layer, back, dir)) return;
        g_drag_dir = back;
        g_drag_cell = c;
        return;
    }
    Entity *e = entity_at(c, layer);
    if (e) {
        Entity *e2 = entity_at(c, layer);
        if (!(e2 && e2->serial && e2->type == 1)) {
            g_dragging_conveyor = 0;
            g_drag_dir = -1;
            return;
        }
    }
    i32 dir = 0;
    if (!entity_at(c, layer)) {
        if (!place_conveyor(c, layer, g_rotation, g_place_paid == 0)) {
            g_dragging_conveyor = 0;
            g_drag_dir = -1;
            return;
        }
        dir = k_opposite[k_rot_dir[g_rotation]];
    } else {
        u8 b = entity_at(c, layer)->ports[0].dirs;
        if (b & 2) dir = 3;
        else if (b & 1) dir = 2;
        else if (b & 4) dir = 0;
        else if (b & 8) dir = 1;
        else TRAP();
    }
    g_dragging_conveyor = 1;
    g_drag_cell = c;
    g_drag_dir = dir;
}

// 0x1400029d0: apply a tool (build-menu id) to a cell
void apply_tool(u8 id, V2u c, u32 layer, u32 rotation, b32 paid_mode) {
    if (c.x >= g_map.w || c.y >= g_map.h) return;
    V2i ci = {(i32)c.x, (i32)c.y};
    switch (id) {
    case 0:
        order_harvest(c);
        break;
    case 1: {
        b32 protect = 0;
        if ((i32)c.x >= 0 && (i32)c.y >= 0 && c.y < g_map.h && g_layers != 0) {
            u8 t = g_tiles[c.y * g_map.w + c.x];
            protect = t == TILE_CLIFF || t == TILE_NEST;
        }
        if (protect) break;
        cancel_order_at(&g_flock, ci);
        demolish_at(c, layer);
        if (paid_mode) {
            home_remove_at(c);
            if (in_map(c.x, c.y)) g_tiles[c.y * g_map.w + c.x] = TILE_GRASS;
            nest_sync(c);
            u32 i = c.y * g_map.w + c.x;
            g_ore_iron[i] = 0;
            g_ore_copper[i] = 0;
            g_ore_flowers[i] = 0;
        }
        break;
    }
    case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: {
        cancel_order_at(&g_flock, ci);
        demolish_at(c, 0);
        home_remove_at(c);
        u8 t = (u8)(id - 1);
        if (in_map(c.x, c.y)) g_tiles[c.y * g_map.w + c.x] = t;
        nest_sync(c);
        set_ore_amount(c);
        break;
    }
    case 10:
        place_conveyor(c, 0, rotation, paid_mode == 0);
        break;
    case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
        if (!paid_mode && !pay_build(id)) return;
        if (!place_building(c, layer, id_to_type(id), rotation, paid_mode == 0) && !paid_mode) refund_build(id);
        break;
    case 20:
    case 21:
        if (!paid_mode && !pay_build(id)) return;
        if (!place_home(c, id == 21, paid_mode == 0) && !paid_mode) refund_build(id);
        break;
    }
}

// 0x140002d30: use the selected tool at the cursor (called while the button is held)
void use_tool(u8 id) {
    if (id == 10) {
        conveyor_drag();
        return;
    }
    V2i cell = {0, 0};
    if (!cursor_cell(&cell)) return;
    if (g_have_last_cell && cell.x == g_last_cell.x && cell.y == g_last_cell.y) return;
    g_last_cell = cell;
    g_have_last_cell = 1;
    apply_tool(id, v2u_make((u32)cell.x, (u32)cell.y), g_layer, g_rotation, g_place_paid);
}

// 0x140003fe0: does flying from cell a to cell b through `p` hit a cliff/water edge?
b32 world_blocked(V2 p, V2u a, V2u b, void *user) {
    (void)user;
    if (p.x < 0.0f || p.y < 0.0f || (f32)g_map.w <= p.x || (f32)g_map.h <= p.y) return 1;
    for (u32 i = 0; i < g_homes.count; i++) {
        Home *h = &g_homes.data[i];
        u32 s = h->big ? 2 : 1;
        b32 hit = (h->pos.x <= a.x && h->pos.y <= a.y && a.x < h->pos.x + s && a.y < s + h->pos.y) ||
                  (h->pos.x <= b.x && h->pos.y <= b.y && b.x < h->pos.x + s && b.y < s + h->pos.y);
        if (hit && (f32)h->pos.x - 0.180000007f <= p.x && p.x <= (f32)(h->pos.x + s) + 0.180000007f &&
            (f32)h->pos.y - 0.180000007f <= p.y && p.y <= (f32)(h->pos.y + s) + 0.180000007f)
            return 0;
    }
    i32 fx = (i32)(u32)(i64)floorf(p.x);
    u32 fy = (u32)(i64)floorf(p.y);
    for (i32 dy = -1; dy < 2; dy++) {
        i32 y = (i32)(fy + (u32)dy);
        for (i32 x = fx - 1; x - fx < 2; x++) {
            if (x < 0 || y < 0 || x >= (i32)g_map.w || y >= (i32)g_map.h) continue;
            if ((u32)x == a.x && (u32)y == a.y) continue;
            if ((u32)x == b.x && (u32)y == b.y) continue;
            if ((u8)(g_tiles[(u32)y * g_map.w + (u32)x] - 7) >= 2) continue;
            f32 cx = (f32)x, cy = (f32)y;
            f32 nx = sse_min(cx + 1.0f, sse_max(cx, p.x));
            f32 ddx = p.x - nx;
            f32 ny = sse_min(cy + 1.0f, sse_max(cy, p.y));
            f32 ddy = p.y - ny;
            f32 d2 = ddx * ddx + ddy * ddy;
            if (0.0324000008f > d2) return 1;
        }
    }
    return 0;
}

// ---------------------------------------------------------------------------
// 0x140018dd0: translucent preview of the selected building under the cursor

// Blit with the colour scaled per channel and alpha scaled by 0xaf/255,
// blended over the backbuffer.
static void blit_tinted(const Sprite *s, i32 x, i32 y, i32 scale, i32 frame, u32 gmul, u32 rmul) {
    i32 x0 = x > 0 ? x : 0;
    i32 y0 = y > 0 ? y : 0;
    i32 srcx = (s->w * frame + s->x) * scale + (x < 0 ? -x : 0);
    i32 srcy_off = y < 0 ? -y : 0;
    i32 x1 = s->w * scale + x;
    if (x1 > g_bb_w) x1 = g_bb_w;
    i32 y1 = scale * s->h + y;
    if (y1 > g_bb_h) y1 = g_bb_h;
    i32 wcount = x1 - x0;
    if (wcount <= 0 || y1 - y0 <= 0) return;
    i32 srcy = (scale * s->y + srcy_off) - y0;
    for (i32 row = y0; row < y1; row++) {
        const u32 *src = s->img->pixels;
        i32 iw = s->img->w;
        u8 *dst = (u8 *)(g_backbuffer + ((i64)(row * g_bb_w) + (i64)x0));
        i32 sx = srcx;
        for (i64 i = 0; i < wcount; i++, sx++, dst += 4) {
            u32 p = src[(u32)(((srcy + row) / scale) * iw) + (i64)(sx / scale)];
            u32 r = ((p >> 16 & 0xff) * rmul) / 0xff;
            u32 a = (u32)(((u64)(p >> 24) * 0xaf) / 0xff) & 0xff;
            if (!a) continue;
            u32 d = *(u32 *)dst;
            u32 ia = 0xff - a;
            dst[3] = 0xff;
            dst[0] = (u8)(((((p & 0xff) * 0xaf) / 0xff & 0xff) * a + (d & 0xff) * ia) / 0xff);
            dst[1] = (u8)(((d >> 8 & 0xff) * ia + (((p >> 8 & 0xff) * gmul) / 0xff & 0xff) * a) / 0xff);
            dst[2] = (u8)(((d >> 16 & 0xff) * ia + (r & 0xff) * a) / 0xff);
        }
    }
}

static const Sprite *preview_sprite(u8 id, u32 rot) {
    switch (id) {
    case 0:
    case 1:
        return NULL;
    case 10: {
        static const u64 k[4] = {0x1400eaca0, 0x1400ead00, 0x1400eadc0, 0x1400ead60};
        return SPR(k[rot < 4 ? rot : 0]);
    }
    case 11: return SPR(0x1400eb680);
    case 12: {
        static const u64 k[4] = {0x1400eb220, 0x1400eb2a0, 0x1400eb260, 0x1400eb2e0};
        return SPR(k[rot < 4 ? rot : 0]);
    }
    case 13: {
        static const u64 k[4] = {0x1400eb580, 0x1400eb600, 0x1400eb5c0, 0x1400eb640};
        return SPR(k[rot < 4 ? rot : 0]);
    }
    case 14: return SPR(0x1400eabe0);
    case 15: return SPR(0x1400eac00);
    case 16: return SPR(0x1400eae40);
    case 17: return SPR(0x1400eae20);
    case 18: {
        static const u64 k[4] = {0x1400eae80, 0x1400eae60, 0x1400eaec0, 0x1400eaea0};
        return SPR(k[rot < 4 ? rot : 0]);
    }
    case 19: return SPR(0x1400eb6c0);
    case 20: return SPR(0x1400eaba0);
    case 21: return SPR(0x1400eabc0);
    default: return menu_sprite(id);
    }
}

static inline i32 screen_coord(f32 tile, u32 cell, f32 cam) {
    return (i32)floorf((tile * (f32)cell - cam) + 0.5f);
}

void draw_build_preview(V2 cam, i32 zoom, f64 t) {
    if (g_palette_open || g_picker_open || g_selected_id == 0) return;
    V2i cell = {0, 0};
    if (!cursor_cell(&cell)) return;
    u8 id = g_selected_id;
    i32 cw = 1, ch = 1;
    if (id == 12 || id == 21) {
        cw = 2;
        ch = 2;
    } else if (id == 13) {
        cw = 3;
        ch = 2;
        if (g_rotation == 1 || g_rotation == 3) {
            cw = 2;
            ch = 3;
        }
    }
    i32 tile = zoom * 16;
    i32 pw = cw * tile, ph = ch * tile;
    f32 ft = (f32)tile;
    i32 x = screen_coord(ft, (u32)cell.x, cam.x);
    i32 y = screen_coord(ft, (u32)cell.y, cam.y);
    u32 fill, border;
    if (id == 1) {
        fill = 0x305050dc;
        border = 0xdc7878ff;
    } else if (id == 10 || id == 11 || id == 12 || id == 13 || id == 18) {
        fill = 0x28ffb478;
        border = 0xdcffdca0;
    } else {
        fill = 0x24ffffff;
        border = 0xb4a0ffff;
    }
    blend_rect(x, y, pw, ph, fill);
    for (i32 k = 1, yy = y; k < ch; k++) {
        yy += tile;
        fill_rect(x, yy, pw, 1, 0x78ffffff);
    }
    for (i32 k = 1, xx = x; k < cw; k++) {
        xx += tile;
        fill_rect(xx, y, 1, ph, 0x78ffffff);
    }
    u32 rot = g_rotation;
    const Sprite *sp = preview_sprite(id, rot);
    if (sp) {
        i32 frame = 0;
        if ((u32)sp->frames > 1) frame = (i32)(t * 6.0) % sp->frames;
        i32 sx = (pw - zoom * sp->w) / 2 + x;
        i32 sy = (ph - zoom * sp->h) + y;
        b32 ctrl = g_key_down[VK_CONTROL] != 0;
        b32 ok;
        V2u c = v2u_make((u32)cell.x, (u32)cell.y);
        if (id == 20) ok = home_area_free(c, v2u_make(1, 1));
        else if (id == 21) ok = home_area_free(c, v2u_make(2, 2));
        else ok = building_area_ok(c, (u32)ctrl, id_to_type(id), rot,
                                   g_place_paid);
        if (!build_affordable(id) || !ok) blit_tinted(sp, sx, sy, zoom, frame, 0x32, 0xff);
        else if (ctrl) blit_tinted(sp, sx, sy, zoom, frame, 0x32, 0x32);
        else blit_tinted(sp, sx, sy, zoom, frame, 0xff, 0xff);
        if (id == 19) {
            blend_rect(sx - zoom * 0x40, sy - zoom * 0x20, zoom * 0x40, zoom * 0x50, 0x6400ff00);
            for (u32 i = 0; i < g_entity_list.count; i++) {
                Entity *e = g_entity_list.data[i];
                if (e->type != 10) continue;
                i32 ex = screen_coord(ft, e->pos.x, cam.x);
                i32 ey = screen_coord(ft, e->pos.y, cam.y);
                blend_rect(ex - zoom * 0x40, ey - zoom * 0x20, zoom * 0x40, zoom * 0x50, 0x6400ff00);
            }
        }
    }
    fill_rect(x, y, pw, 1, border);
    fill_rect(x, y - 1 + ph, pw, 1, border);
    fill_rect(x, y, 1, ph, border);
    fill_rect(x - 1 + pw, y, 1, ph, border);
    if (id != 10 && id != 11 && id != 12 && id != 13 && id != 18) return;
    // rotation arrow
    i32 s = (pw < ph ? cw : ch) * tile;
    i32 th = s / 10;
    if (th < 2) th = 2;
    i32 len = s / 3;
    if (len < th + 2) len = th + 2;
    blend_rect(x + th, y + th, pw - 2 * th, ph - 2 * th, 0x0affffff);
    const u32 c = 0xd25aebff;
    switch (rot) {
    case 0:
        blend_rect(x + pw / 2 - th / 2, y + ph - len, th, len - th, c);
        blend_rect(x + pw / 2 - len / 2, y + ph - th, len, th, c);
        break;
    case 1:
        blend_rect(x, y + ph / 2 - len / 2, th, len, c);
        blend_rect(x, y + ph / 2 - th / 2, len, th, c);
        break;
    case 2:
        blend_rect(x + pw / 2 - th / 2, y, th, len, c);
        blend_rect(x + pw / 2 - len / 2, y, len, th, c);
        break;
    case 3:
        blend_rect(x + pw - len, y + ph / 2 - th / 2, len, th, c);
        blend_rect(x + pw - th, y + ph / 2 - len / 2, th, len, c);
        break;
    }
}
