// Buildings ("entities") placed on the map: allocation, grid occupancy,
// connections between ports, and removal.
#include "game.h"

EntityPool g_entity_pool;
U32Array g_free_slots;
EntityPtrArray g_entities;
EntityPtrArray g_entity_list;
u64 g_next_serial = 1;

MapSize g_map;
u32 g_layers;
u8 *g_tiles;
u32 *g_ent_grid;
u8 *g_port_grid;

// Connections live at 0x68 in the entity. The original happily writes a 7th
// connection over the direction bytes that follow, so they are addressed by
// offset here to keep that behaviour well-defined.
static inline EntityHandle *conn_slot(Entity *e, u32 i) { return (EntityHandle *)((u8 *)e + 0x68) + i; }
static inline u8 *conn_dir(Entity *e, u32 i) { return (u8 *)e + 0xc8 + i; }
static inline u32 *conn_count(Entity *e) { return (u32 *)((u8 *)e + 0xd0); }

static inline b32 in_map(u32 x, u32 y) { return x < g_map.w && y < g_map.h; }
static inline u32 grid_index(u32 x, u32 y, u32 layer) { return (layer * g_map.h + y) * g_map.w + x; }

// Entity at a cell, NULL when empty (0x140009990)
Entity *entity_at(V2u pos, u32 layer) {
    if (pos.x < g_map.w && pos.y < g_map.h && layer < g_layers && (i32)pos.x >= 0 && (i32)pos.y >= 0 &&
        (i32)layer >= 0) {
        u32 slot = g_ent_grid[grid_index(pos.x, pos.y, layer)];
        if (slot != 0 && slot < g_entities.count) return g_entities.data[slot];
    }
    return NULL;
}

// Same lookup with the signed checks the original inlines in several places
static Entity *entity_at_checked(u32 x, u32 y, u32 layer) {
    if (x < g_map.w && y < g_map.h && layer < g_layers && (i32)x >= 0 && (i32)y >= 0 && (i32)layer >= 0) {
        u32 slot = g_ent_grid[grid_index(x, y, layer)];
        if (slot != 0 && slot < g_entities.count) return g_entities.data[slot];
    }
    return NULL;
}

// 0x140002550: allocate a zeroed entity (w = h = 1)
static Entity *entity_alloc(EntityPool *pool) {
    Entity *e = pool->free_list;
    if (!e) {
        Arena *a = pool->arena ? pool->arena : &g_arena;
        e = arena_push(a, sizeof(Entity), 8);
    } else {
        pool->free_list = *(Entity **)e;
    }
    memset(e, 0, sizeof *e);
    e->w = 1;
    e->h = 1;
    e->f64 = 1;
    return e;
}

typedef struct { i32 x0, y0, x1, y1; } IRect;

// 0x14001ba90: write `value` into the occupancy grid over an inclusive rect
static void grid_fill(IRect *r, u32 layer, u32 value) {
    if ((i32)layer < 0 || layer >= g_layers) return;
    u64 base = (u64)(g_map.h * g_map.w * layer);
    u8 *ports = g_port_grid + base;
    u32 *ents = g_ent_grid + base;
    IRect c;
    c.x0 = r->x0 > 0 ? r->x0 : 0;
    c.y0 = r->y0 > 0 ? r->y0 : 0;
    c.x1 = r->x1 < (i32)g_map.w - 1 ? r->x1 : (i32)g_map.w - 1;
    c.y1 = r->y1 < (i32)g_map.h - 1 ? r->y1 : (i32)g_map.h - 1;
    if (c.x1 < c.x0 || c.y1 < c.y0) memset(&c, 0, sizeof c);  // (original quirk: then touches cell 0,0)
    *r = c;
    for (i32 y = c.y0; y <= c.y1; y++)
        for (i32 x = c.x0; x <= c.x1; x++) {
            u32 i = (u32)(y * (i32)g_map.w + x);
            ents[i] = value;
            ports[i] = 0;
        }
}

// 0x14001f1e0: rebuild the list of neighbours whose output ports feed this entity
void entity_refresh_connections(Entity *e) {
    if (!e) return;
    memset((u8 *)e + 0x68, 0, 0x60);
    u32 layer = e->layer;
    *conn_count(e) = 0;
    u32 count = 0;
    const u8 *pp = (const u8 *)e->ports;
    for (u32 i = 0; i < 8; i++, pp += sizeof(Port)) {
        if (count > 5) break;
        const Port *p = (const Port *)pp;
        u8 dirs = p->dirs;
        if (!dirs) continue;
        i32 px = p->x, py = p->y;
        // input from +y needs the neighbour's bit 0, -y bit 1, -x bit 3, +x bit 2
        static const struct { u8 in; i32 dx, dy; u8 need; } chk[4] = {
            {0x20, 0, 1, 1}, {0x10, 0, -1, 2}, {0x40, -1, 0, 8}, {0x80, 1, 0, 4}};
        for (int k = 0; k < 4; k++) {
            if (k > 0 && count >= 6) break;
            if (!(dirs & chk[k].in)) continue;
            u32 x = e->pos.x + px + chk[k].dx;
            u32 y = e->pos.y + py + chk[k].dy;
            if (x < g_map.w && y < g_map.h && e->layer < g_layers &&
                (g_port_grid[(u64)(e->layer * g_map.h * g_map.w) + (u64)(y * g_map.w + x)] & chk[k].need)) {
                Entity *n = entity_at(v2u_make(x, y), layer);
                *conn_dir(e, *conn_count(e)) = chk[k].in;
                u32 c = *conn_count(e);
                conn_slot(e, c)->e = n;
                conn_slot(e, c)->serial = n->serial;
                *conn_count(e) = c + 1;
                count = *conn_count(e);
            }
        }
    }
    Entity *n = NULL;
    if (e->type == 7) {
        u32 x = e->pos.x, y = e->pos.y, l = e->layer + 1;
        if (x >= g_map.w || y >= g_map.h || l >= g_layers || (i32)x < 0 || (i32)y < 0 || (i32)l < 0) return;
        u32 slot = g_ent_grid[grid_index(x, y, l)];
        if (slot == 0 || slot >= g_entities.count) return;
        n = g_entities.data[slot];
        if (!n || n->type != 9) return;
    } else if (e->type == 8) {
        n = entity_at(e->pos, e->layer - 1);
        if (!n || n->type != 9) return;
    } else {
        return;
    }
    u32 c = *conn_count(e);
    conn_slot(e, c)->e = n;
    conn_slot(e, c)->serial = n->serial;
    *conn_count(e) = c + 1;
}

// Refresh the four orthogonal neighbours of a port cell
static void refresh_around(Entity *e, const Port *p) {
    entity_refresh_connections(entity_at_checked(e->pos.x + 1 + p->x, p->y + e->pos.y, e->layer));
    entity_refresh_connections(entity_at_checked(e->pos.x - 1 + p->x, e->pos.y + p->y, e->layer));
    entity_refresh_connections(entity_at_checked(p->x + e->pos.x, e->pos.y + 1 + p->y, e->layer));
    entity_refresh_connections(entity_at_checked(p->x + e->pos.x, e->pos.y - 1 + p->y, e->layer));
}

// 0x140002dc0: (re)apply a definition to an existing entity
void entity_configure(Entity *e, const EntityDef *def) {
    Port old_ports[8];
    memcpy(old_ports, e->ports, sizeof old_ports);
    (void)old_ports;
    // clear port marks of the old footprint
    for (u32 y = 0; y < e->h; y++)
        for (u32 x = 0; x < e->w; x++) {
            u32 cx = e->pos.x + x, cy = e->pos.y + y;
            if (cx < g_map.w && cy < g_map.h && g_ent_grid[grid_index(cx, cy, e->layer)] != 0)
                g_port_grid[(u64)(e->layer * g_map.h * g_map.w) + (u64)(cx + cy * g_map.w)] = 0;
        }
    e->type = def->type;
    e->w = (u32)def->w;
    e->h = (u32)def->h;
    e->sprite = def->sprite;
    e->sprite2 = def->sprite2;
    *(u32 *)e->inv = 0;
    e->f64 = def->f20;
    e->recipes = def->recipes;
    memcpy(e->ports, def->ports, sizeof e->ports);

    for (int i = 0; i < 8; i++) {
        const Port *p = &e->ports[i];
        if (!p->dirs) continue;
        u32 cx = e->pos.x + p->x, cy = p->y + e->pos.y;
        if (cx < g_map.w && cy < g_map.h && g_ent_grid[grid_index(cx, cy, e->layer)] != 0)
            g_port_grid[(u64)(e->layer * g_map.h * g_map.w) + (u64)(cx + cy * g_map.w)] = p->dirs;
    }
    for (int i = 0; i < 8; i++) {
        const Port *p = &e->ports[i];
        if (!p->dirs) continue;
        entity_refresh_connections(e);
        refresh_around(e, p);
    }
    if (e->type - 7u < 3) {
        entity_refresh_connections(entity_at_checked(e->pos.x, e->pos.y, e->layer + 1));
        entity_refresh_connections(entity_at_checked(e->pos.x, e->pos.y, e->layer - 1));
    }
    if (e->type == 10) {
        // attach up to five nests to the west of the building
        e->bee_count = 0;
        for (u32 y = e->pos.y - 2; y <= e->pos.y + 2; y++) {
            for (i32 x = (i32)e->pos.x - 4; x < (i32)e->pos.x; x++) {
                if (e->bee_count > 4) break;
                for (u32 i = 0; i < g_bee_count; i++) {
                    if ((i32)g_bees[i].pos.x == x && g_bees[i].pos.y == y) {
                        e->bees[e->bee_count++] = &g_bees[i];
                        break;
                    }
                }
            }
        }
    }
    // keep the current recipe if the new list contains it, else take the first
    RecipeList *rl = e->recipes;
    if (rl->count == 0) TRAP();
    u32 idx = 0;
    if (e->recipe) {
        for (u32 i = 0; i < rl->count; i++)
            if (rl->data[i] == e->recipe) { idx = i; break; }
    }
    if (idx >= rl->count) TRAP();
    Recipe *r = rl->data[idx];
    e->recipe = r;
    e->recipe_time = r ? recipe_time(r) : 0;
    e->f134 = 0;
}

// 0x140008800: create an entity from a definition
EntityHandle entity_create(V2u pos, u32 layer, const EntityDef *def) {
    Entity *e = entity_alloc(&g_entity_pool);
    e->serial = g_next_serial++;
    if (g_free_slots.count == 0) {
        e->slot = g_entities.count;
        da_push(&g_entities, e, 8);
    } else {
        u32 slot = g_free_slots.data[--g_free_slots.count];
        e->slot = slot;
        g_entities.data[slot] = e;
    }
    EntityHandle h = {e, e->serial};
    e->pos = pos;
    e->layer = layer;
    IRect r = {(i32)pos.x, (i32)pos.y, def->w - 1 + (i32)pos.x, (i32)pos.y - 1 + def->h};
    grid_fill(&r, layer, e->slot);
    da_push(&g_entity_list, e, 8);
    entity_configure(e, def);
    return h;
}

// 0x140014b90: remove an entity, refunding its contents into the inventory
void entity_destroy(Entity *e) {
    if (!e || !e->serial) return;
    for (u32 i = 0; i < recipe_input_count(e->recipe); i++) {
        u8 item = *ent_in_item(e, i);
        if (item >= g_items.count) TRAP();
        g_items.data[item] += *ent_in_count(e, i);
    }
    if (*ent_out_item(e) >= g_items.count) TRAP();
    g_items.data[*ent_out_item(e)] += *ent_out_count(e);
    if (e->slot >= g_entities.count) TRAP();
    g_entities.data[e->slot] = NULL;
    da_push(&g_free_slots, e->slot, 4);
    IRect r = {(i32)e->pos.x, (i32)e->pos.y, (i32)e->pos.x + (i32)e->w - 1, (i32)e->pos.y - 1 + (i32)e->h};
    grid_fill(&r, e->layer, 0);
    u32 i = 0;
    for (; i < g_entity_list.count; i++)
        if (g_entity_list.data[i] == e) break;
    if (i != g_entity_list.count) g_entity_list.data[i] = g_entity_list.data[--g_entity_list.count];
    e->serial = 0;
    for (int k = 0; k < 8; k++)
        if (e->ports[k].dirs) refresh_around(e, &e->ports[k]);
    *(Entity **)e = g_entity_pool.free_list;
    g_entity_pool.free_list = e;
}

// 0x14001c590: can something be built on this cell of this layer?
b32 cell_buildable(V2u pos, u32 layer) {
    if (pos.x >= g_map.w || pos.y >= g_map.h || layer >= g_layers) return 0;
    u8 t = 0;
    if ((i32)pos.x >= 0 && (i32)pos.y >= 0 && (i32)layer >= 0) {
        t = g_tiles[pos.y * g_map.w + pos.x];
        if (g_ent_grid[grid_index(pos.x, pos.y, layer)] != 0) return 0;
    }
    if (t == TILE_GRASS || t == TILE_5) return 1;
    if (t == TILE_IRON || t == TILE_COPPER || t == TILE_FLOWERS) return layer != 0;
    return 0;
}
