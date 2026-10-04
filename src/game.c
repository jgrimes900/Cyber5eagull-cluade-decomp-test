// Game setup, the per-frame simulation of buildings, and the main loop.
#include "game.h"
#include <stdio.h>

// ---------------------------------------------------------------------------
// Global game / UI state
V2 g_cam;
i32 g_zoom = 4;
f32 g_dt;
f64 g_last_time;
u32 g_layer;
u32 g_anim_tick;
u64 g_frame_count;
u32 g_delivered;
f32 g_win_slide;
u32 g_won;
u32 g_win_dismissed;
u32 g_tutorial_page;
const Image *g_tooltip;
V2i g_tooltip_pos;
V2u g_start;
u32 g_paid[0x10000];
u32 g_world_seed;  // 0x14002a9e0

HomeArray g_homes;
U32Array g_home_flags;
U8Array g_inv_rows;

MenuEntry g_menu[12] = {{0, 10}, {0, 14}, {0, 16}, {0, 17}, {0, 18}, {0, 11},
                        {0, 12}, {0, 13}, {0, 19}, {1, 0},  {0, 20}, {0, 21}};
u8 g_palette_ids[22] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
SpritePtrArray g_palette_sprites;
u8 g_selected_id;
i32 g_palette_index;
u32 g_palette_open;
u32 g_place_paid;
u32 g_rotation;
u8 g_selected_item = ITEM_NONE;
u8 g_inv_next_row = 0xff;
u32 g_menu_open;
u32 g_drag_camera;
u32 g_click_consumed;
u32 g_have_last_cell;
V2i g_last_cell;
u32 g_dragging_conveyor;
V2u g_drag_cell;
i32 g_drag_dir = -1;
u32 g_right_drag;
V2i g_raw_mouse_delta;
u32 g_picker_open;
u32 g_picker_anchored;
V2i g_picker_anchor;
i32 g_picker_selected = -1;
Entity *g_picker_entity;
u64 g_picker_serial;
SpritePtrArray g_picker_icons;
PickerFn g_picker_fn;

const Sprite *g_tile_sprites[9];
const Sprite *g_item_sprites[14];

// ---------------------------------------------------------------------------
// Recipes (0x1400eb8c0..) and the per-building recipe books (0x1400eba70..)
static Recipe s_recipe_pass = {0, {{0}}, {0}, 0.800000012f, NULL};
static Recipe s_recipe_plate, s_recipe_wire, s_recipe_gear, s_recipe_circuit, s_recipe_core, s_recipe_lens,
    s_recipe_cyber;
RecipeBook g_recipes_conveyor, g_recipes_furnace, g_recipes_machine, g_recipes_assembler;

static Recipe make_recipe(u32 n, const u8 *items, const u32 *counts, u8 out, u32 out_n, f32 time, u64 icon) {
    Recipe r;
    memset(&r, 0, sizeof r);
    r.n_in = n;
    for (u32 i = 0; i < n; i++) {
        r.in[i].item = items[i];
        r.in[i].count = counts[i];
    }
    r.out.item = out;
    r.out.count = out_n;
    r.time = time;
    r.icon = SPR(icon);
    return r;
}

static void book_init(RecipeBook *b, Recipe **list, u32 n) {
    memset(b, 0, sizeof *b);
    for (u32 i = 0; i < n; i++) da_push(&b->list, list[i], 8);
    // 0x14001c060: icon list built from the recipes
    for (u32 i = 0; i < b->list.count; i++) da_push(&b->icons, b->list.data[i]->icon, 8);
}

// 0x14000c160
static void recipes_init(void) {
    memset(&s_recipe_pass, 0, sizeof s_recipe_pass);
    s_recipe_pass.time = 0.800000012f;
    s_recipe_plate = make_recipe(1, (u8[]){ITEM_IRON_ORE}, (u32[]){2}, ITEM_IRON_PLATE, 1, 7.0f, 0x1400eb0a0);
    s_recipe_wire = make_recipe(1, (u8[]){ITEM_COPPER_ORE}, (u32[]){3}, ITEM_COPPER_WIRE, 1, 4.0f, 0x1400eb080);
    s_recipe_gear = make_recipe(1, (u8[]){ITEM_IRON_PLATE}, (u32[]){5}, ITEM_GEAR, 3, 2.0f, 0x1400eb120);
    s_recipe_circuit = make_recipe(1, (u8[]){ITEM_COPPER_WIRE}, (u32[]){4}, ITEM_CIRCUIT, 2, 8.0f, 0x1400eb0c0);
    s_recipe_core = make_recipe(3, (u8[]){ITEM_IRON_PLATE, ITEM_URANIUM, ITEM_CIRCUIT}, (u32[]){5, 3, 1},
                                ITEM_POWER_CORE, 1, 20.0f, 0x1400eb140);
    s_recipe_lens = make_recipe(3, (u8[]){ITEM_IRON_PLATE, ITEM_GEAR, ITEM_CIRCUIT}, (u32[]){2, 8, 2},
                                ITEM_CAM_LENS, 1, 15.0f, 0x1400eb0e0);
    s_recipe_cyber = make_recipe(3, (u8[]){ITEM_POWER_CORE, ITEM_CAM_LENS, ITEM_SEAGULL}, (u32[]){1, 2, 1},
                                 ITEM_CYBER_SEAGULL, 1, 15.0f, 0x1400eb200);
    book_init(&g_recipes_conveyor, (Recipe *[]){&s_recipe_pass}, 1);
    book_init(&g_recipes_furnace, (Recipe *[]){&s_recipe_plate, &s_recipe_wire}, 2);
    book_init(&g_recipes_machine, (Recipe *[]){&s_recipe_gear, &s_recipe_circuit}, 2);
    book_init(&g_recipes_assembler, (Recipe *[]){&s_recipe_core, &s_recipe_lens, &s_recipe_cyber}, 3);
}

// 0x14000bcf0
static void inventory_init(void) {
    g_items.count = 0;
    for (u32 i = 0; i < 14; i++) da_push(&g_items, 0u, 4);
    g_inv_rows.count = 0;
    for (u32 i = 0; i < 14; i++) da_push(&g_inv_rows, (u8)0xff, 1);
    g_selected_item = ITEM_NONE;
    static const u64 k_icons[14] = {0x1400eb020, 0x1400eb040, 0x1400eb060, 0x1400eb080, 0x1400eb0a0,
                                    0x1400eb0c0, 0x1400eb0e0, 0x1400eb100, 0x1400eb120, 0x1400eb140,
                                    0x1400eb160, 0x1400eb1a0, 0x1400eb1c0, 0x1400eb200};
    for (u32 i = 0; i < 14; i++) g_item_sprites[i] = SPR(k_icons[i]);
    g_inv_next_row = 0xff;
}

// ---------------------------------------------------------------------------
// Camera

static inline f32 cam_max_x(void) { return sse_max((f32)((i32)g_map.w * g_zoom * 16 - g_bb_w) + 250.0f, -250.0f); }
static inline f32 cam_max_y(void) { return sse_max((f32)((i32)g_map.h * g_zoom * 16 - g_bb_h) + 250.0f, -250.0f); }

// 0x1400056b0
void camera_center(V2u cell) {
    f32 t = (f32)(g_zoom << 4);
    g_cam.x = sse_min(cam_max_x(), sse_max(-250.0f, t * ((f32)cell.x + 0.5f) - (f32)g_bb_w * 0.5f));
    g_cam.y = sse_min(cam_max_y(), sse_max(-250.0f, t * ((f32)cell.y + 0.5f) - (f32)g_bb_h * 0.5f));
}

// 0x1400057b0
void camera_clamp(void) {
    g_cam.x = sse_min(cam_max_x(), sse_max(-250.0f, g_cam.x));
    g_cam.y = sse_min(cam_max_y(), sse_max(-250.0f, g_cam.y));
}

// ---------------------------------------------------------------------------
// New game

// 0x14001a4f0: initial ore amount for a cell, larger further from the first home
void set_ore_amount(V2u c) {
    u32 i = c.y * g_map.w + c.x;
    g_ore_iron[i] = 0;
    g_ore_copper[i] = 0;
    g_ore_flowers[i] = 0;
    u8 t = (c.x < g_map.w && c.y < g_map.h) ? g_tiles[i] : 0;
    if (t == TILE_IRON) g_ore_iron[i] = (u16)((i16)(i32)(home_distance_score(c) * 1.5f) + 10);
    else if (t == TILE_COPPER) g_ore_copper[i] = (u16)((i16)(i32)home_distance_score(c) + 10);
    else if (t == TILE_FLOWERS) g_ore_flowers[i] = (u16)((i16)(i32)(home_distance_score(c) * 0.5f) + 16);
}

static HomeTarget *home_target_fn(HomeTarget *out, V2u cell, void *user) {
    (void)user;
    return nearest_home(out, cell);
}

// 0x14000b290
void new_game(V2u start) {
    // 0x14001a480: clear nests and both grids
    g_bee_count = 0;
    for (u32 i = 0; i < g_layers * g_map.h * g_map.w; i++) {
        g_ent_grid[i] = 0;
        g_port_grid[i] = 0;
    }
    for (u32 i = 0; i < g_entity_list.count; i++) {
        Entity *e = g_entity_list.data[i];
        if (e && e->serial) {
            if (e->slot >= g_entities.count) TRAP();
            g_entities.data[e->slot] = NULL;
            e->serial = 0;
            *(Entity **)e = g_entity_pool.free_list;
            g_entity_pool.free_list = e;
        }
    }
    g_free_slots.count = 0;
    g_entity_list.count = 0;
    for (u32 i = 1; i < g_entities.count; i++) g_entities.data[i] = NULL;
    for (u32 y = 0; y < g_map.h; y++)
        for (u32 x = 0; x < g_map.w; x++) g_ent_grid[y * g_map.w + x] = 0;

    world_generate(&g_world_seed, &g_homes, start);
    g_path_user = NULL;
    g_path_fn = find_path;
    g_blocked_user = NULL;
    g_blocked_fn = world_blocked;
    memset(g_ore_iron, 0, sizeof g_ore_iron);
    memset(g_ore_copper, 0, sizeof g_ore_copper);
    memset(g_ore_flowers, 0, sizeof g_ore_flowers);
    for (u32 y = 0; y < g_map.h; y++)
        for (u32 x = 0; x < g_map.w; x++) set_ore_amount(v2u_make(x, y));
    g_honey_timer = 0;
    build_costs_init();
    g_home_flags.arena = &g_arena;
    g_home_flags.count = 0;
    g_pickups.arena = &g_arena;
    g_pickups.count = 0;
    memset(g_paid, 0, sizeof g_paid);
    da_resize(&g_home_flags, g_homes.count, 4);
    for (u32 i = 0; i < g_home_flags.count; i++) g_home_flags.data[i] = 0;

    flock_reset(&g_flock, 5, start, 6.0f, &g_arena);
    g_flock.home_user = NULL;
    g_flock.home_fn = home_target_fn;
    if (g_homes.count) {
        Home *h = &g_homes.data[0];
        u32 s = h->big ? 2 : 1;
        f32 ox = (f32)s * 0.5f, oy = (f32)s * 0.5f;
        if ((s & 1) == 0) ox += -0.0500000007f;
        if ((s & 1) == 0) oy += -0.0500000007f;
        g_flock.default_home.cell = h->pos;
        g_flock.default_home.off = v2(ox, oy);
        for (u32 i = 0; i < g_flock.gulls.count; i++) {
            Seagull *g = &g_flock.gulls.data[i];
            g->home_off = v2(ox, oy);
            g->home = h->pos;
            g->vel = v2(0, 0);
            g->pos = v2((f32)g->home.x + g->home_off.x, (f32)g->home.y + oy);
            g->path_count = 0;
            g->path_idx = 0;
            g->path_goal = v2u_make(0, 0);
            g->has_path = 0;
        }
    }
    // the dock: a row of conveyors leading off the map edge
    for (u32 x = 1; x < 7; x++) {
        u32 y = (g_map.h >> 1) + 1;
        if ((i32)x < 0 || (i32)y < 0 || x >= g_map.w || y >= g_map.h || g_layers == 0) continue;
        u8 t = g_tiles[y * g_map.w + x];
        if (t != TILE_CLIFF && t != TILE_NEST) continue;
        EntityDef d;
        memset(&d, 0, sizeof d);
        d.type = 1;
        d.w = 1;
        d.h = 1;
        d.sprite = SPR(0x1400ead60);
        d.f20 = 1;
        d.f24 = 1;
        d.ports[0].dirs = 0x48;
        d.recipes = (RecipeList *)&g_recipes_conveyor;
        entity_create(v2u_make(x, y), 0, &d);
    }
}

// ---------------------------------------------------------------------------
// Building simulation

// 0x14001cc50: push items from `src` into a building
static void entity_accept(Entity *t, ItemStack *src, b32 second) {
    u32 n = src->count;
    if (!n) return;
    Recipe *r = t->recipe;
    if (!r) TRAP();
    if (r->n_in == 0) {
        if (!second) {
            if (*ent_out_count(t) == 0 && *ent_in_count(t, 0) == 0) {
                memcpy(ent_in_item(t, 0), src, 8);
                src->count--;
                *ent_in_count(t, 0) = 1;
            }
        } else if (*(u32 *)((u8 *)t + 0x60) == 0 && *ent_in_count(t, 1) == 0) {
            memcpy(ent_in_item(t, 1), src, 8);
            src->count--;
            *ent_in_count(t, 1) = 1;
        }
        return;
    }
    u32 j = 0;
    for (;; j++) {
        if (j >= r->n_in) return;
        if (r->in[j].item == src->item) break;
    }
    u32 have = *ent_in_count(t, j);
    u32 space = r->in[j].count - have;
    if (!space) return;
    *ent_in_item(t, j) = src->item;
    if (space < n) {
        src->count -= space;
        *ent_in_count(t, j) += space;
    } else {
        *ent_in_count(t, j) = src->count + have;
        src->count = 0;
    }
}

static inline EntityHandle *conn_slot(Entity *e, u32 i) { return (EntityHandle *)((u8 *)e + 0x68) + i; }
static inline u8 conn_dir(Entity *e, u32 i) { return *((u8 *)e + 0xc8 + i); }
static inline u32 *conn_count(Entity *e) { return (u32 *)((u8 *)e + 0xd0); }
static inline u32 *conn_rr(Entity *e) { return (u32 *)((u8 *)e + 0xd4); }
static inline u32 *ent_anim(Entity *e) { return (u32 *)e->inv; }

// 0x14001ebb0
void entities_update(f32 dt) {
    f64 now = time_now();
    g_anim_tick = (u32)(i64)((now - trunc(now)) * 100.0);
    u32 t10 = 0;
    if (g_entity_list.count) t10 = (u32)(i64)(now * 10.0);
    for (u32 li = 0; li < g_entity_list.count; li++) {
        Entity *e = g_entity_list.data[li];
        *ent_anim(e) = t10 % (u32)e->sprite->frames;
        Recipe *r = e->recipe;
        if (!r) TRAP();
        b32 ready;
        if (r->n_in == 0) {
            ready = *ent_in_count(e, 0) != 0 || *ent_in_count(e, 1) != 0;
        } else {
            ready = 1;
            for (u32 i = 0; i < r->n_in; i++)
                if (*ent_in_count(e, i) < r->in[i].count) {
                    ready = 0;
                    break;
                }
        }
        if (ready) {
            f32 t = e->recipe_time - dt;
            e->recipe_time = t;
            if (0.0f >= t) {
                e->recipe_time = 0;
                if (r->n_in == 0) {
                    if (e->type == 6) {
                        if (*ent_in_count(e, 0)) {
                            memcpy((u8 *)e + 0x54, (u8 *)e + 0x3c, 8);
                            *ent_in_count(e, 0) = 0;
                        }
                        if (*ent_in_count(e, 1)) {
                            memcpy((u8 *)e + 0x5c, (u8 *)e + 0x44, 8);
                            *ent_in_count(e, 1) = 0;
                        }
                    } else {
                        memcpy((u8 *)e + 0x54, (u8 *)e + 0x3c, 8);
                        *ent_in_count(e, 0) = 0;
                    }
                    e->recipe_time = r->time;
                } else if ((*ent_out_item(e) == r->out.item || *ent_out_count(e) == 0) &&
                           *ent_out_count(e) < (u32)e->f64) {
                    for (u32 i = 0; i < e->recipe->n_in; i++) *ent_in_count(e, i) -= e->recipe->in[i].count;
                    r = e->recipe;
                    *ent_out_item(e) = r->out.item;
                    *ent_out_count(e) += r->out.count;
                    e->recipe_time = r->time;
                }
            }
        }
        // hand finished items to a connected building (round robin)
        u32 *out2 = (u32 *)((u8 *)e + 0x60);
        if (*ent_out_count(e) != 0 || *out2 != 0) {
            if (e->type == 1 && (e->ports[0].dirs & 0x40) && e->pos.x == 1 && g_delivered < 20) {
                (*ent_out_count(e))--;
                if (*ent_out_item(e) == ITEM_CYBER_SEAGULL) g_delivered++;
            }
            u32 n = *conn_count(e);
            b32 sent = 0;
            for (u32 k = 0; k < n; k++) {
                u32 idx = (*conn_rr(e) + k) % n;
                EntityHandle h = *conn_slot(e, idx);
                if (!h.e || !h.e->serial || h.e->serial != h.serial) continue;
                Entity *t = h.e;
                if (*ent_out_count(e) != 0) {
                    Recipe *tr = t->recipe;
                    if (!tr) {
                        TRAP();
                        continue;
                    }
                    if (tr->n_in != 0) {
                        u32 j = 0;
                        while (j < tr->n_in && tr->in[j].item != *ent_out_item(e)) j++;
                        if (j == tr->n_in) continue;
                        if (tr->in[j].count == *ent_in_count(t, j)) continue;
                    }
                }
                *conn_rr(e) = idx + 1;
                b32 flag = 0;
                for (u32 c = 0; c < *conn_count(e); c++)
                    if (conn_slot(e, c)->e == t && ((u8)(conn_dir(e, c) - 0x10) & 0xef) == 0) {
                        flag = 1;
                        break;
                    }
                b32 second = t->type == 6 ? flag : 0;
                if (e->type == 6 && flag) entity_accept(t, (ItemStack *)((u8 *)e + 0x5c), second);
                else entity_accept(t, (ItemStack *)((u8 *)e + 0x54), second);
                sent = 1;
                break;
            }
            if (!sent) (*conn_rr(e))++;
        }
        *ent_anim(e) = (g_anim_tick >> 3) % (u32)e->sprite->frames;
        if (e->type == 10)
            for (u32 i = 0; i < e->bee_count; i++) order_harvest(e->bees[i]->pos);
    }
    g_frame_count++;
}

// ---------------------------------------------------------------------------
// Startup and main loop (0x14001a8f0)

static void world_alloc(void) {
    g_map.w = 0x40;
    g_map.h = 0x40;
    g_layers = 2;
    g_tiles = g_arena.base + g_arena.used;
    u64 off = (g_arena.used + 0x1003) & ~(u64)3;
    g_bees = (Nest *)(g_arena.base + off);
    g_ent_grid = (u32 *)(g_arena.base + off + 0x40000);
    g_port_grid = g_arena.base + off + 0x48000;
    g_arena.used = off + 0x4a000;
    memset(g_tiles, 1, 0x1000);
    g_bee_count = 0;
    for (u32 i = 0; i < g_layers * g_map.h * g_map.w; i++) {
        g_ent_grid[i] = 0;
        g_port_grid[i] = 0;
    }
}

b32 game_init(void) {
    g_last_time = time_now();
    if (!assets_load()) return 0;
    sound_load(&g_snd_squawk, "./resources/sounds/bees.wav", 0.5f);
    sound_load(&g_snd_pickaxe, "./resources/sounds/pickaxe.wav", 1.0f);
    if (!audio_start()) return 0;
    recipes_init();
    inventory_init();
    world_alloc();
    for (int i = 0; i < 4; i++) g_rng.s[i] = rdrand64();
    g_entity_pool.arena = &g_arena;
    static const u64 k_tiles[9] = {0x1400eaa20, 0x1400eaa40, 0x1400eaa60, 0x1400eaa80, 0x1400eaaa0,
                                   0x1400eaac0, 0x1400eaae0, 0x1400eab00, 0x1400eab20};
    for (int i = 0; i < 9; i++) g_tile_sprites[i] = SPR(k_tiles[i]);
    g_free_slots.arena = &g_arena;
    g_entities.arena = &g_arena;
    g_entity_list.arena = &g_arena;
    g_free_slots.count = 0;
    g_entities.count = 0;
    g_entity_list.count = 0;
    da_push(&g_entities, (Entity *)NULL, 8);
    g_next_serial = 1;
    g_frame_count = 0;
    g_palette_sprites.count = 0;
    for (u32 i = 0; i < 22; i++) {
        const Sprite *s = g_palette_ids[i] == 1 ? SPR(0x1400eaa20) : menu_sprite(g_palette_ids[i]);
        da_push(&g_palette_sprites, s, 8);
    }
    g_selected_id = g_palette_ids[0];
    g_palette_index = 0;
    g_place_paid = 0;
    g_rotation = 0;
    g_palette_open = 0;
    g_zoom = 4;
    V2u start;
    start.x = g_map.w < 3 ? 0 : MIN(g_map.w - 2, 8u);
    start.y = g_map.h >> 1;
    g_start = start;
    new_game(start);
    camera_center(g_start);
    return 1;
}

void game_frame(void) {
    // swap the per-frame arenas
    Arena tmp = g_frame_prev;
    g_frame_prev = g_frame_arena;
    g_frame_arena = tmp;
    g_frame_arena.used = 0;
    platform_pump_events();
    f64 now = time_now();
    g_dt = sse_min((f32)(now - g_last_time), 0.100000001f);
    entities_update(g_dt);
    nests_update(g_dt);
    jobs_tick(g_dt);
    frame_input();
    if (g_delivered > 19) {
        g_win_slide = 5.0f * g_dt + g_win_slide;
        g_won = 1;
    }
    V2i m = platform_mouse_pos();
    f32 cx = g_cam.x, cy = g_cam.y;
    if (!g_drag_camera) {
        if ((f32)m.x < 20.0f) g_cam.x = g_cam.x - g_dt * 500.0f;
        if ((f32)g_bb_w - 20.0f < (f32)m.x) g_cam.x = g_cam.x + g_dt * 500.0f;
        cx = g_cam.x;
        if ((f32)m.y < 20.0f) g_cam.y = g_cam.y - g_dt * 500.0f;
        cy = g_cam.y;
        if ((f32)g_bb_h - 20.0f < (f32)m.y) cy = g_cam.y + g_dt * 500.0f;
    }
    if (g_key_down['W']) cy = cy - g_dt * 1000.0f;
    if (g_key_down['A']) cx = cx - g_dt * 1000.0f;
    if (g_key_down['S']) cy = cy + g_dt * 1000.0f;
    if (g_key_down['D']) cx = cx + g_dt * 1000.0f;
    g_cam.x = sse_min(sse_max((f32)(i32)(g_map.w * (u32)g_zoom * 16 - (u32)g_bb_w) + 250.0f, -250.0f),
                      sse_max(-250.0f, cx));
    g_cam.y = sse_min(sse_max((f32)(i32)(g_map.h * (u32)g_zoom * 16 - (u32)g_bb_h) + 250.0f, -250.0f),
                      sse_max(-250.0f, cy));
    render_frame();
    platform_present();
}

// Test mode: text dump of simulation state (same format as tools/oracle)
void game_debug_dump(const char *path) {
    FILE *f = fopen(path, "w");
    if (!f) return;
    fprintf(f, "rng %016llx %016llx %016llx %016llx\n", (unsigned long long)g_rng.s[0], (unsigned long long)g_rng.s[1],
            (unsigned long long)g_rng.s[2], (unsigned long long)g_rng.s[3]);
    for (u32 i = 0; i < g_bee_count; i++) {
        Nest *n = &g_bees[i];
        fprintf(f, "nest %u %u t=%.6f n=%u", n->pos.x, n->pos.y, n->timer, n->count);
        for (u32 k = 0; k < n->count && k < 3; k++)
            fprintf(f, " [%.4f %.4f %u %.3f]", n->p[k].x, n->p[k].y, n->p[k].item, n->p[k].life);
        fprintf(f, "\n");
    }
    for (u32 i = 0; i < g_flock.gulls.count; i++) {
        Seagull *g = &g_flock.gulls.data[i];
        fprintf(f, "gull %.6f %.6f st=%u\n", g->pos.x, g->pos.y, g->state);
    }
    fprintf(f, "orders %u pickups %u\n", g_flock.orders.count, g_pickups.count);
    fclose(f);
}
