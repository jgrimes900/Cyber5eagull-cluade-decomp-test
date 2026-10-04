// Inventory, build costs and buying seagulls.
#include "game.h"

DARRAY(u32) g_items;
BuildCost g_build_costs[12];
CostList g_seagull_cost = {{{ITEM_HONEY, {0}, 0}, {ITEM_HONEY, {0}, 0}, {ITEM_HONEY, {0}, 0}, {ITEM_HONEY, {0}, 0}}, 0};
static b32 g_costs_ready;  // 0x14004a9e8

static inline u32 inv_get(u8 item) {
    if (item >= g_items.count) return 0;
    return g_items.data[item];
}

static void cost_push(BuildCost *c, u8 item, u32 count) {
    if (c->n < 4) {
        c->in[c->n].item = item;
        c->in[c->n].count = count;
        c->n++;
    }
}

// 0x14000c940: fill in the build cost table (once)
void build_costs_init(void) {
    if (g_costs_ready) return;
    for (int i = 0; i < 12; i++) {
        BuildCost *c = &g_build_costs[i];
        memset(c, 0, sizeof *c);
        for (int k = 0; k < 4; k++) c->in[k].item = ITEM_HONEY;
        c->alt_item = ITEM_NONE;
    }
    g_seagull_cost.n = 0;
    for (int k = 0; k < 4; k++) g_seagull_cost.s[k].item = ITEM_HONEY, g_seagull_cost.s[k].count = 0;
    BuildCost *c = g_build_costs;
    c[0].id = 10;  // conveyor: free
    c[1].id = 11;  cost_push(&c[1], ITEM_IRON_ORE, 4); cost_push(&c[1], ITEM_COPPER_ORE, 2);
    c[2].id = 12;  cost_push(&c[2], ITEM_IRON_PLATE, 2); cost_push(&c[2], ITEM_COPPER_WIRE, 1);
    c[3].id = 14;  cost_push(&c[3], ITEM_IRON_ORE, 3); cost_push(&c[3], ITEM_COPPER_ORE, 1);
    c[4].id = 13;  cost_push(&c[4], ITEM_IRON_PLATE, 2); cost_push(&c[4], ITEM_CIRCUIT, 1); cost_push(&c[4], ITEM_URANIUM, 1);
    c[5].id = 20;  cost_push(&c[5], ITEM_HONEY, 12); cost_push(&c[5], ITEM_COPPER_ORE, 3);
    c[6].id = 21;  cost_push(&c[6], ITEM_HONEY, 24); cost_push(&c[6], ITEM_IRON_PLATE, 2); cost_push(&c[6], ITEM_COPPER_ORE, 6);
    c[7].id = 15;  cost_push(&c[7], ITEM_IRON_ORE, 2); cost_push(&c[7], ITEM_COPPER_WIRE, 1);
    c[8].id = 16;  cost_push(&c[8], ITEM_IRON_ORE, 2);
    c[9].id = 17;  cost_push(&c[9], ITEM_IRON_ORE, 2); cost_push(&c[9], ITEM_COPPER_WIRE, 1);
    c[10].id = 18; cost_push(&c[10], ITEM_IRON_ORE, 2);
    c[11].id = 19; cost_push(&c[11], ITEM_IRON_PLATE, 2); cost_push(&c[11], ITEM_CAM_LENS, 1);
    g_seagull_cost.s[0].item = ITEM_HONEY;
    g_seagull_cost.s[0].count = 4;
    g_seagull_cost.n = 1;
    g_costs_ready = 1;
}

static BuildCost *find_cost(u8 id) {
    for (int i = 0; i < 12; i++)
        if (g_build_costs[i].id == id) return &g_build_costs[i];
    return NULL;
}

// min over a cost list of inventory / required; 1 when there are no requirements
static u32 affordable(const ItemStack *s, u32 n) {
    if (n == 0) return 1;
    u32 m = 0xffffffffu;
    for (u32 i = 0; i < n; i++) {
        if (!s[i].count) continue;
        u32 have = 0;
        if (s[i].item < g_items.count) have = g_items.data[s[i].item];
        u32 k = have / s[i].count;
        if (m < k) k = m;
        m = k;
    }
    return m == 0xffffffffu ? 0 : m;
}

// 0x140004300
u32 seagull_affordable(void) {
    build_costs_init();
    return affordable(g_seagull_cost.s, g_seagull_cost.n);
}

// 0x1400043b0
CostList seagull_cost(void) {
    build_costs_init();
    CostList r;
    memset(&r, 0, sizeof r);
    for (int k = 0; k < 4; k++) r.s[k].item = ITEM_HONEY;
    r.n = g_seagull_cost.n;
    if (r.n) memcpy(r.s, g_seagull_cost.s, (u64)r.n * 8);
    return r;
}

// 0x140004e70
u32 build_affordable(u8 id) {
    build_costs_init();
    BuildCost *c = find_cost(id);
    if (!c) return 0;
    u32 n = affordable(c->in, c->n);
    if (c->alt_item != ITEM_NONE && c->alt_count != 0) n = inv_get(c->alt_item) / c->alt_count + n;
    return n;
}

// 0x140004f90
CostList build_cost(u8 id) {
    CostList r;
    memset(&r, 0, sizeof r);
    for (int k = 0; k < 4; k++) r.s[k].item = ITEM_HONEY;
    build_costs_init();
    BuildCost *c = find_cost(id);
    if (c) {
        r.n = c->n;
        if (r.n) memcpy(r.s, c->in, (u64)r.n * 8);
    }
    return r;
}

static b32 can_pay(const ItemStack *s, u32 n) {
    for (u32 i = 0; i < n; i++)
        if (s[i].count && inv_get(s[i].item) < s[i].count) return 0;
    return 1;
}
static void pay(const ItemStack *s, u32 n) {
    for (u32 i = 0; i < n; i++) {
        u32 cnt = s[i].count;
        u8 it = s[i].item;
        if (cnt && it < g_items.count && cnt <= g_items.data[it]) g_items.data[it] -= cnt;
    }
}

static void spawn_seagull_at_first_home(void) {
    if (g_homes.count && g_homes.data) {
        Home *h = &g_homes.data[0];
        u32 sz = h->big ? 2 : 1;
        f32 ox = (f32)sz * 0.5f, oy = (f32)sz * 0.5f;
        if (!(sz & 1)) ox = ox + -0.0500000007f;
        if (!(sz & 1)) oy = oy + -0.0500000007f;
        flock_spawn_at(&g_flock, h->pos, v2(ox, oy));
    } else {
        flock_spawn_default(&g_flock);
    }
}

// 0x140005040: pay for and hatch a new seagull
b32 buy_seagull(void) {
    build_costs_init();
    if (!can_pay(g_seagull_cost.s, g_seagull_cost.n)) return 0;
    pay(g_seagull_cost.s, g_seagull_cost.n);
    spawn_seagull_at_first_home();
    return 1;
}

// 0x1400148e0: give back what a building cost
void refund_build(u8 id) {
    build_costs_init();
    BuildCost *c = find_cost(id);
    if (!c) return;
    if (c->alt_item != ITEM_NONE && c->alt_count != 0) {
        if (c->alt_item >= g_items.count) return;
        g_items.data[c->alt_item] += c->alt_count;
        return;
    }
    for (u32 i = 0; i < c->n; i++)
        if (c->in[i].count && c->in[i].item < g_items.count) g_items.data[c->in[i].item] += c->in[i].count;
}

// 0x14001be70: take the price of a building out of the inventory
b32 pay_build(u8 id) {
    build_costs_init();
    BuildCost *c = find_cost(id);
    if (!c) return 0;
    if (c->alt_item != ITEM_NONE && c->alt_count != 0 && c->alt_count <= inv_get(c->alt_item)) {
        if (c->alt_item >= g_items.count || c->alt_count == 0) return 0;
        if (c->alt_count <= g_items.data[c->alt_item]) {
            g_items.data[c->alt_item] -= c->alt_count;
            return 1;
        }
        return 0;
    }
    if (!can_pay(c->in, c->n)) return 0;
    pay(c->in, c->n);
    if (c->alt_item == ITEM_NONE || c->alt_count == 0) return 1;
    if (c->alt_item < g_items.count) g_items.data[c->alt_item] += c->alt_count;
    if (c->alt_item < g_items.count && c->alt_count && c->alt_count <= g_items.data[c->alt_item]) {
        g_items.data[c->alt_item] -= c->alt_count;
        return 1;
    }
    return 0;
}
