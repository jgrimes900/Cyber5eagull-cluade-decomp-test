// Shared declarations for the Cyber5eagull port.
//
// Struct layouts mirror the original program's memory layout (offsets noted
// in comments) because a lot of the original code copies these structures
// around wholesale. Several of the original structures are byte-packed.
#pragma once
#include "base.h"
#include "platform.h"

#define PACKED __attribute__((packed))

// ---------------------------------------------------------------------------
// Images and sprites
typedef struct Image {
    u32 *pixels;  // 0x00  0xAARRGGBB as stored in memory by the PNG decoder
    i32 w, h;     // 0x08
} Image;

typedef struct Sprite {
    Image *img;   // 0x00
    i32 x, y;     // 0x08 position of frame 0 inside the image
    i32 w, h;     // 0x10 size of one frame
    i32 frames;   // 0x18 animation frames laid out horizontally
    i32 unused;   // 0x1c (never meaningfully written by the original)
} Sprite;

typedef DARRAY(u32) U32Array;
typedef DARRAY(u8) U8Array;
typedef DARRAY(const Sprite *) SpritePtrArray;

extern u32 *g_backbuffer;
extern i32 g_bb_w, g_bb_h;

void blit_opaque(const Sprite *s, i32 x, i32 y, i32 scale, i32 frame);
void blit(const Sprite *s, i32 x, i32 y, i32 scale, i32 frame);
void blit_channel0(const Sprite *s, i32 x, i32 y, i32 scale, i32 frame);
void blit_channel2(const Sprite *s, i32 x, i32 y, i32 scale, i32 frame);
void draw_rect_outline(i32 x, i32 y, i32 w, i32 h, i32 thick, u32 color);
void draw_box(i32 x, i32 y, i32 w, i32 h, i32 thick, u32 border, u32 fill);
void fill_rect(i32 x, i32 y, i32 w, i32 h, u32 color);
void blend_rect(i32 x, i32 y, i32 w, i32 h, u32 color);
void draw_number(u32 value, i32 x, i32 y, i32 spacing);

// fmath.c
u32 count_digits(u32 n);
V2 dir_from_turns(f32 turns);

// ---------------------------------------------------------------------------
// Random numbers: xoshiro256++ seeded from RDRAND (0x140029aa8)
typedef struct { u64 s[4]; } Rng;
extern Rng g_rng;
static inline u64 rotl64(u64 x, int k) { return (x << k) | (x >> (64 - k)); }
// The original's xoshiro256++ output step uses (x << 23) | (x >> 31) where the
// reference algorithm has rotl(x, 23); kept so the random sequence matches.
static inline u64 rng_mix23(u64 x) { return x << 23 | x >> 31; }
static inline u64 rng_next(Rng *r) {
    u64 *s = r->s;
    u64 result = rng_mix23(s[0] + s[3]) + s[0];
    u64 t = s[1] << 17;
    s[2] ^= s[0];
    s[3] ^= s[1];
    s[1] ^= s[2];
    s[0] ^= s[3];
    s[2] ^= t;
    s[3] = rotl64(s[3], 45);
    return result;
}
// The 32-bit integer hash the original uses everywhere for deterministic noise
static inline u32 hash_mix(u32 h) {
    h = (h >> 16 ^ h) * 0x45d9f3b;
    h = (h >> 16 ^ h) * 0x45d9f3b;
    return h >> 16 ^ h;
}

// ---------------------------------------------------------------------------
// The map
enum Tile {
    TILE_NONE = 0,
    TILE_GRASS = 1,
    TILE_IRON = 2,      // iron ore deposit (amounts in g_ore_iron)
    TILE_COPPER = 3,    // copper ore deposit (g_ore_copper)
    TILE_FLOWERS = 4,   // pollen (g_ore_flowers)
    TILE_5 = 5,
    TILE_NEST = 6,      // junk pile that slowly spawns random items (see Nest)
    TILE_CLIFF = 7,
    TILE_WATER = 8,
};

typedef struct { u32 w, h; } MapSize;
extern MapSize g_map;          // 0x140029a88
extern u32 g_layers;           // 0x1400299a8
extern u8 *g_tiles;            // 0x140029a90  [h][w]
extern u32 *g_ent_grid;        // 0x140029a98  [layer][h][w] entity slot index
extern u8 *g_port_grid;        // 0x140029aa0  [layer][h][w]

// ---------------------------------------------------------------------------
// Entities
typedef struct PACKED Port {
    i32 x, y;   // offset inside the building footprint
    u8 dirs;    // low nibble: output directions, high nibble: input directions
} Port;

typedef struct Recipe Recipe;
typedef DARRAY(Recipe *) RecipeList;
// A building's selectable recipes plus the icons shown in the recipe picker
typedef struct RecipeBook {
    RecipeList list;                  // 0x00
    SpritePtrArray icons;     // 0x18
} RecipeBook;
extern RecipeBook g_recipes_conveyor;   // 0x1400eba70 (single pass-through recipe)
extern RecipeBook g_recipes_furnace;    // 0x1400ebaa0
extern RecipeBook g_recipes_machine;    // 0x1400ebad0
extern RecipeBook g_recipes_assembler;  // 0x1400ebb00

typedef struct EntityDef {        // 0x78 bytes
    i32 type;                     // 0x00
    i32 w, h;                     // 0x04
    i32 f0c;                      // 0x0c
    const Sprite *sprite;         // 0x10
    const Sprite *sprite2;        // 0x18
    i32 f20;                      // 0x20
    i32 f24;                      // 0x24
    Port ports[8];                // 0x28
    RecipeList *recipes;          // 0x70
} EntityDef;
_Static_assert(sizeof(EntityDef) == 0x78, "EntityDef");

typedef struct Nest Nest;

typedef struct Entity {           // 0x168 bytes
    i32 type;                     // 0x00
    i32 pad04;
    u64 serial;                   // 0x08 (0 when freed)
    const Sprite *sprite;         // 0x10
    const Sprite *sprite2;        // 0x18
    V2u pos;                      // 0x20
    u32 layer;                    // 0x28
    u32 w, h;                     // 0x2c
    u32 slot;                     // 0x34 index into g_entities
    u8 inv[0x2c];                 // 0x38 item slots (see entity.c)
    i32 f64;                      // 0x64
    u8 f68[0x70];                 // 0x68
    Port ports[8];                // 0xd8
    RecipeList *recipes;          // 0x120
    Recipe *recipe;               // 0x128
    f32 recipe_time;              // 0x130
    u32 f134;
    Nest *bees[5];                // 0x138 nests feeding a type-10 building
    u32 bee_count;                // 0x160
    u32 f164;
} Entity;
_Static_assert(sizeof(Entity) == 0x168, "Entity");

typedef struct { Entity *e; u64 serial; } EntityHandle;
typedef DARRAY(Entity *) EntityPtrArray;
static inline b32 handle_valid(EntityHandle h) { return h.e && h.e->serial && h.e->serial == h.serial; }

typedef struct EntityPool { Arena *arena; Entity *free_list; } EntityPool;
extern EntityPool g_entity_pool;                 // 0x14002a838
extern U32Array g_free_slots;                 // 0x14002a848
extern EntityPtrArray g_entities;              // 0x14002a860 (slot 0 is always NULL)
extern EntityPtrArray g_entity_list;           // 0x14002a878
extern u64 g_next_serial;                        // 0x140029140

Entity *entity_at(V2u pos, u32 layer);           // 0x140009990

// ---------------------------------------------------------------------------
// Nests: piles on TILE_NEST cells that periodically produce a random item
typedef struct NestItem { f32 x, y; u8 item; u8 pad[3]; f32 life; } NestItem;
struct Nest {
    V2u pos;               // 0x00
    f32 timer;             // 0x08 seconds until the next item appears
    u32 count;             // 0x0c
    NestItem p[3];         // 0x10
};
_Static_assert(sizeof(Nest) == 0x40, "Nest");
extern Nest *g_bees;       // 0x140029ac8
extern u32 g_bee_count;    // 0x1400299ac

// ---------------------------------------------------------------------------
// Seagulls (the worker units) and the flock that hands out orders
typedef struct PACKED Order {   // 0x28 bytes, packed
    u8 kind;          // 0x00
    V2i a;            // 0x01 where to work
    V2i b;            // 0x09 secondary cell (e.g. drop-off)
    u8 item;          // 0x11
    u8 pad12[2];
    f32 duration;     // 0x14 work time at the job site
    i32 repeat;       // 0x18 non-zero: order stays in the list after completion
    i32 f1c;          // 0x1c
    i32 assigned;     // 0x20 seagull index or -1
    i32 active;       // 0x24
} Order;
_Static_assert(sizeof(Order) == 0x28, "Order");

typedef struct PACKED FlockEvent {  // 0x28 bytes
    u8 type;          // 1 assigned, 3 job done, 4 arrived home, 5 became idle
    u8 pad[3];
    u32 seagull;      // 0x04
    u8 order[0x20];   // 0x08 copy of the first 32 bytes of the Order
} FlockEvent;
_Static_assert(sizeof(FlockEvent) == 0x28, "FlockEvent");

enum { SG_IDLE = 0, SG_TO_JOB = 1, SG_WORKING = 2, SG_RETURNING = 3 };

typedef struct PACKED Seagull {   // 0x2080 bytes
    V2 pos;              // 0x00
    V2 vel;              // 0x08
    V2u home;            // 0x10 cell the seagull returns to
    V2 home_off;         // 0x18 offset inside that cell
    f32 speed;           // 0x20
    f32 work;            // 0x24 time spent at the current job
    f32 sound_timer;     // 0x28
    f32 wobble_time;     // 0x2c
    f32 phase;           // 0x30
    u8 state;            // 0x34
    u8 pad35[3];
    u8 order[0x20];      // 0x38 copy of the current Order (first 32 bytes)
    u32 busy;            // 0x58
    u8 carry_item;       // 0x5c
    u8 pad5d[3];
    u32 carry_count;     // 0x60
    V2u path[0x400];     // 0x64
    u32 path_count;      // 0x2064
    u32 path_idx;        // 0x2068
    V2u path_goal;       // 0x206c
    u32 has_path;        // 0x2074
    f32 rnd1;            // 0x2078
    f32 rnd2;            // 0x207c
} Seagull;
_Static_assert(sizeof(Seagull) == 0x2080, "Seagull");
#define SG_ORDER(s) ((Order *)(s)->order)  // only the first 0x20 bytes are valid

typedef struct HomeTarget { V2u cell; V2 off; } HomeTarget;
typedef HomeTarget *(*HomeTargetFn)(HomeTarget *out, V2u cell, void *user);

typedef struct Flock {             // 0x1400291d0
    u64 f00;
    DARRAY(Seagull) gulls;         // 0x08
    DARRAY(Order) orders;          // 0x20
    DARRAY(FlockEvent) events;     // 0x38
    HomeTarget default_home;       // 0x50
    f32 speed;                     // 0x60
    u32 f64;
    HomeTargetFn home_fn;          // 0x68
    void *home_user;               // 0x70
} Flock;
extern Flock g_flock;

typedef struct SeagullEvents { i32 at_job, at_job2, job_done, at_home, idle; } SeagullEvents;

// world callbacks used by the seagull movement code
typedef b32 (*PathFn)(V2u from, V2u to, V2u *out, u32 *count, u32 max, void *user);
typedef b32 (*BlockedFn)(V2 pos, V2u a, V2u b, void *user);
extern PathFn g_path_fn;           // 0x14002a8f0
extern void *g_path_user;          // 0x14002a8f8
extern BlockedFn g_blocked_fn;     // 0x14002a900
extern void *g_blocked_user;       // 0x14002a908

void flock_spawn_at(Flock *f, V2u cell, V2 off);
void flock_spawn_default(Flock *f);
void flock_assign_orders(Flock *f);
void flock_update(Flock *f, f32 dt);
void flock_emit_event(Flock *f, u8 type, u32 seagull, const void *order32);
HomeTarget *nearest_home(HomeTarget *out, V2u cell);
f32 home_distance_score(V2u c);

// ---------------------------------------------------------------------------
// Items, inventory and build costs
enum Item {
    ITEM_IRON_ORE = 0, ITEM_COPPER_ORE, ITEM_SEAGULL, ITEM_COPPER_WIRE, ITEM_IRON_PLATE, ITEM_CIRCUIT,
    ITEM_CAM_LENS, ITEM_FEATHER, ITEM_GEAR, ITEM_POWER_CORE, ITEM_URANIUM, ITEM_POLLEN, ITEM_HONEY,
    ITEM_CYBER_SEAGULL, ITEM_NONE = 14,
};
typedef struct ItemStack { u8 item; u8 pad[3]; u32 count; } ItemStack;
typedef struct BuildCost {        // 0x30
    u8 id;                        // build-menu id
    u8 pad[3];
    ItemStack in[4];              // 0x04
    u32 n;                        // 0x24
    u8 alt_item;                  // 0x28 alternative single-item price (unused: always ITEM_NONE)
    u8 pad29[3];
    u32 alt_count;                // 0x2c
} BuildCost;
typedef struct CostList { ItemStack s[4]; u32 n; } CostList;

extern U32Array g_items;        // 0x140029a20 inventory counts per item
extern BuildCost g_build_costs[12];// 0x140029290
extern CostList g_seagull_cost;    // 0x1400294d0

void build_costs_init(void);
u32 seagull_affordable(void);
CostList seagull_cost(void);
u32 build_affordable(u8 id);
CostList build_cost(u8 id);
b32 buy_seagull(void);
void refund_build(u8 id);
b32 pay_build(u8 id);

// Recipes used by machines (and the trivial ones used by conveyors etc.)
struct Recipe {
    u32 n_in;               // 0x00
    ItemStack in[3];        // 0x04
    ItemStack out;          // 0x1c
    f32 time;               // 0x24
    const Sprite *icon;     // 0x28
};
_Static_assert(sizeof(struct Recipe) == 0x30, "Recipe");
static inline u32 recipe_input_count(const Recipe *r) { if (!r) TRAP(); return r->n_in; }
static inline f32 recipe_time(const Recipe *r) { return r->time; }

// entity inventory slots: inputs at 0x3c + 8*i, output at 0x54
static inline u8 *ent_in_item(Entity *e, u32 i) { return (u8 *)e + 0x3c + 8 * i; }
static inline u32 *ent_in_count(Entity *e, u32 i) { return (u32 *)((u8 *)e + 0x40 + 8 * i); }
static inline u8 *ent_out_item(Entity *e) { return (u8 *)e + 0x54; }
static inline u32 *ent_out_count(Entity *e) { return (u32 *)((u8 *)e + 0x58); }
static inline V2u v2u_make(u32 x, u32 y) { V2u r = {x, y}; return r; }

// Homes ("hives") where seagulls live
typedef struct Home { V2u pos; u32 big; } Home;
typedef DARRAY(Home) HomeArray;
extern HomeArray g_homes;       // 0x14002a9c8
extern U32Array g_home_flags;   // 0x1400ea9f0

// Sounds: mono float samples (first channel of a 16-bit PCM wav, pre-scaled by volume)
typedef struct Sound {
    f32 *samples;     // 0x00
    u32 count;        // 0x08
    u32 rate;         // 0x0c
    f64 duration;     // 0x10 seconds
} Sound;
extern Sound g_snd_squawk;         // 0x14002a8c0 (bees.wav)
extern Sound g_snd_pickaxe;        // 0x14002a8d8 (pickaxe.wav)
void play_sound(Sound *s, f32 volume);
b32 sound_load(Sound *s, const char *path, f32 volume);
b32 audio_start(void);
void audio_stop(void);
b32 assets_load(void);
f64 time_now(void);
u32 rdrand32(void);
u64 rdrand64(void);

// Items waiting on a conveyor for a seagull (take=1) or to be dropped onto it (take=0)
typedef struct Pickup {          // 0x18
    V2i pos;
    u8 item;
    u8 pad[3];
    u32 count;
    i32 seagull;                 // assigned seagull or -1
    u8 take;
    u8 pad2[3];
} Pickup;
typedef DARRAY(Pickup) PickupArray;
extern PickupArray g_pickups;
extern u16 g_ore_iron[0x10000], g_ore_copper[0x10000], g_ore_flowers[0x10000];

void pickup_remove(u32 i);
void cancel_order(Flock *f, u32 idx);
void cancel_order_at(Flock *f, V2i cell);
V2u step_dir(V2u p, u8 dir);
b32 insert_into_neighbour(V2u cell, u8 item, b32 enabled);
b32 insert_into_conveyor(V2u cell, u8 item, u32 count);
b32 harvest_cell(V2u c, u8 *item_out);
b32 cell_has_resource(V2u c);
i32 home_index_at(V2u c);
void jobs_tick(f32 dt);

// ---------------------------------------------------------------------------
// Sprites in the tileset (0x1400eaa20 ..) and other loaded art
extern Image g_tileset;                  // 0x140029890
extern Sprite g_spr[104];                // 0x1400eaa20, indexed by (address - 0x1400eaa20) / 0x20
#define SPR(addr) (&g_spr[((u64)(addr) - 0x1400eaa20ull) / 0x20])
#define g_spr_digits SPR(0x1400eaee0)
extern const Sprite *g_tile_sprites[9];  // 0x140029a40
extern const Sprite *g_item_sprites[14]; // 0x1400299b0
extern Image g_tooltips[26];             // 0x1400eb720
#define TOOLTIP(addr) (&g_tooltips[((u64)(addr) - 0x1400eb720ull) / 0x10])
// 0x1400298c0: nine tutorial pages followed directly by the controls image
// (0x140029950); the original indexes past the pages, so keep them together.
extern Image g_tutorial[10];
#define g_controls_img (g_tutorial[9])
extern Image g_win_img;                  // 0x140029960

// ---------------------------------------------------------------------------
// Game / UI state (named after their original addresses until understood)
extern V2 g_cam;                // 0x140029630
extern i32 g_zoom;              // 0x140029020 (pixels per tile = 16 * zoom)
extern f32 g_dt;                // 0x140029628
extern f64 g_last_time;         // 0x140029620
extern u32 g_layer;             // 0x140029980 (1 while Ctrl is held)
extern u32 g_anim_tick;         // 0x14002a39c
extern u64 g_frame_count;       // 0x14002a398
extern u32 g_delivered;         // 0x140029984 cyber seagulls shipped from the dock
extern f32 g_win_slide;         // 0x140029988
extern u32 g_won;               // 0x14002998c
extern u32 g_win_dismissed;     // 0x140029970
extern u32 g_tutorial_page;     // 0x1400298bc
extern const Image *g_tooltip;  // 0x140029990
extern V2i g_tooltip_pos;       // 0x140029998
extern V2u g_start;             // 0x140029638
extern u32 g_paid[0x10000];     // 0x1400aa9f0 building was paid for (refund on removal)

void render_frame(void);
void draw_tiles(V2 cam, i32 zoom);
void draw_entities(i32 zoom, u32 layer);

// ---------------------------------------------------------------------------
// UI state (0x140029040.. layout constants live in .data)
typedef struct MenuEntry { u8 is_spawn; u8 id; } MenuEntry;
extern MenuEntry g_menu[12];            // 0x140029058 build menu slots (keys 1..0,-,=)
extern u8 g_palette_ids[22];            // 0x140029028 ids shown in the full palette
extern SpritePtrArray g_palette_sprites;  // 0x140029640
extern u8 g_selected_id;                // 0x14002962c building/tool selected for placing
extern i32 g_palette_index;             // 0x140029658
extern u32 g_palette_open;              // 0x14002965c
extern u32 g_place_paid;                // 0x140029660 1: sandbox placement (free, chosen from the palette)
extern u32 g_rotation;                  // 0x140029664
extern u8 g_selected_item;              // 0x140029024 item chosen for delivery (ITEM_NONE = none)
extern u8 g_inv_next_row;               // 0x140029025
extern U8Array g_inv_rows;           // 0x140029558 display row per item (0xff = not shown yet)
extern u32 g_menu_open;                 // 0x1400298ac
extern u32 g_drag_camera;               // 0x1400296ec
extern u32 g_click_consumed;            // 0x1400296f8
extern u32 g_have_last_cell;            // 0x1400296fc
extern V2i g_last_cell;                 // 0x1400298a0
extern u32 g_dragging_conveyor;         // 0x1400298a8
extern V2u g_drag_cell;                 // 0x1400298b0
extern i32 g_drag_dir;                  // 0x140029054
extern u32 g_right_drag;                // 0x1400298b8
extern V2i g_raw_mouse_delta;           // 0x1400296dc
// recipe picker
extern u32 g_picker_open;               // 0x140029af0
extern u32 g_picker_anchored;           // 0x140029af4
extern V2i g_picker_anchor;             // 0x140029af8
extern i32 g_picker_selected;           // 0x140029128
extern Entity *g_picker_entity;         // 0x14002a890
extern u64 g_picker_serial;             // 0x14002a898
extern SpritePtrArray g_picker_icons; // 0x140029ad0
typedef void (*PickerFn)(u32 index);
extern PickerFn g_picker_fn;            // 0x140029ae8

const Sprite *menu_sprite(u8 id);       // 0x1400065a0
const Image *build_tooltip(u8 id);      // 0x140009f00
b32 cursor_cell(V2i *out);              // 0x140011060
V2 mouse_pos_f(void);                   // 0x140009a10
void camera_clamp(void);                // 0x1400057b0
void camera_center(V2u cell);           // 0x1400056b0

void draw_build_preview(V2 cam, i32 zoom, f64 t);
void draw_home_range(const Home *h, V2 cam, i32 zoom);
void draw_home_hud(V2 cam, i32 zoom);
void draw_seagulls(V2 cam, i32 zoom, f64 t);
void draw_hover_info(i32 zoom);
void draw_inventory(void);
void draw_build_menu(void);
void draw_palette(void);
void draw_recipe_picker(void);
b32 inventory_click(V2 m);
b32 build_menu_click(V2 m);
b32 picker_click(V2 m);
i32 picker_hover(void);
void picker_open_for(Entity *e);
void picker_choose(u32 index);
i32 entity_recipe_index(Entity *e);
void menu_activate(u32 slot);

// ---------------------------------------------------------------------------
// Cross-module functions
// entity.c
void entity_configure(Entity *e, const EntityDef *def);
EntityHandle entity_create(V2u pos, u32 layer, const EntityDef *def);
void entity_destroy(Entity *e);
void entity_refresh_connections(Entity *e);
b32 cell_buildable(V2u pos, u32 layer);
// worldgen.c
void world_generate(u32 *seed_out, void *zones, V2u start);
b32 home_in_range(V2u c, const Home *h, u32 r);
b32 near_any_home(V2u c);
// nests.c
void nest_add(V2u p);
void nest_remove(V2u p);
void nest_sync(V2u p);
void nests_update(f32 dt);
// orders.c
b32 find_path(V2u from, V2u to, V2u *out, u32 *count, u32 max, void *user);
b32 can_harvest(V2u c);
i32 order_add(Flock *f, const Order *src);
void order_harvest(V2u c);
b32 order_take_from_conveyor(V2u c, u32 max);
b32 order_deliver(V2u c, u8 item, u32 count);
// seagull.c
void flock_reset(Flock *f, u32 n, V2u start, f32 speed, Arena *arena);
// place.c
b32 in_home(V2u c);
void home_remove_at(V2u c);
void demolish_area(V2u at, u32 layer, V2u size);
void demolish_at(V2u c, u32 layer);
void cancel_orders_in(V2u at, V2u size);
EntityDef conveyor_def(i32 out, i32 in);
EntityDef building_def(u32 kind, i32 rot);
b32 set_conveyor(V2u c, u32 layer, i32 out, i32 in);
void apply_tool(u8 id, V2u c, u32 layer, u32 rotation, b32 paid_mode);
void use_tool(u8 id);
b32 world_blocked(V2 p, V2u a, V2u b, void *user);
// ui.c
b32 menu_contains(V2 m);
b32 palette_click(V2 m);
// input.c
void on_key(u32 vk, b32 down);
void on_mouse(i32 button, b32 down, f32 wheel);
void frame_input(void);
// game.c
extern u32 g_world_seed;
void set_ore_amount(V2u c);
void new_game(V2u start);
void entities_update(f32 dt);
b32 game_init(void);
void game_frame(void);
extern f32 g_honey_timer;      // 0x14004a9e4
