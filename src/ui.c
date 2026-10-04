// Screen-space UI: inventory, build menu, palette, recipe picker, tooltips,
// the hive status panel, seagull sprites and the placement preview.
#include "game.h"

// layout constants from .data
static const i32 k_menu_icon = 0x10;     // 0x140029040
static const i32 k_menu_scale = 4;       // 0x140029044
static const i32 k_menu_margin = 0x32;   // 0x140029048
static const i32 k_menu_border = 3;      // 0x14002904c
static const i32 k_sel_thick = 2;        // 0x140029050
static const i32 k_big_scale = 3;        // 0x140029070
static const i32 k_inv_slot = 0x30;      // 0x140029074
static const i32 k_inv_x = 10;           // 0x140029078
static const i32 k_inv_y = 0x14;         // 0x14002907c
static const i32 k_pick_icon = 0x10;     // 0x140029120
static const i32 k_pick_scale = 4;       // 0x140029124
static const i32 k_pick_margin = 0x32;   // 0x14002912c
static const i32 k_pick_border = 3;      // 0x140029130
static const i32 k_pick_sel = 2;         // 0x140029134
static const i32 k_pick_lift = 10;       // 0x140029138
static const u32 k_col_highlight = 0xff32fa32;  // 0x1400294f4
static const u32 k_col_frame = 0xff000000;      // 0x140029570
static const u32 k_col_frame_fill = 0xff64a064; // 0x140029574
static const u32 k_col_select = 0xff50ffff;     // 0x140029578
static const u32 k_col_panel = 0xff000000;      // 0x14002957c
static const u32 k_col_panel_fill = 0xffaa8264; // 0x140029580

static inline i32 cam_x(void) { return (i32)floorf(g_cam.x); }
static inline i32 cam_y(void) { return (i32)floorf(g_cam.y); }

// 0x140009a10
V2 mouse_pos_f(void) {
    V2i m = platform_mouse_pos();
    return v2((f32)m.x, (f32)m.y);
}

// 0x140011060
b32 cursor_cell(V2i *out) {
    V2i m = platform_mouse_pos();
    f32 k = 1.0f / (f32)(g_zoom << 4);
    V2i c = {(i32)floorf(k * ((f32)m.x + g_cam.x)), (i32)floorf(k * ((f32)m.y + g_cam.y))};
    if (c.x >= 0 && c.y >= 0 && c.x < (i32)g_map.w && c.y < (i32)g_map.h) {
        *out = c;
        return 1;
    }
    return 0;
}

// 0x1400065a0
const Sprite *menu_sprite(u8 id) {
    switch (id) {
    case 0: return SPR(0x1400eb3c0);
    case 2: return SPR(0x1400eaa40);
    case 3: return SPR(0x1400eaa60);
    case 4: return SPR(0x1400eaa80);
    case 5: return SPR(0x1400eaaa0);
    case 6: return SPR(0x1400eaac0);
    case 7: return SPR(0x1400eaae0);
    case 8: return SPR(0x1400eab00);
    case 9: return SPR(0x1400eab20);
    case 10: return SPR(0x1400eb320);
    case 11: return SPR(0x1400eb380);
    case 12: return SPR(0x1400eb340);
    case 13: return SPR(0x1400eb3a0);
    case 14: return SPR(0x1400eb400);
    case 15: return SPR(0x1400eb420);
    case 16: return SPR(0x1400eb460);
    case 17: return SPR(0x1400eb440);
    case 18: return SPR(0x1400eb480);
    case 19: return SPR(0x1400eb4a0);
    case 20: return SPR(0x1400eb360);
    case 21: return SPR(0x1400eb3e0);
    default: return NULL;
    }
}

// 0x140009f00
const Image *build_tooltip(u8 id) {
    switch (id) {
    case 10: return TOOLTIP(0x1400eb790);
    case 11: return TOOLTIP(0x1400eb7f0);
    case 12: return TOOLTIP(0x1400eb720);
    case 13: return TOOLTIP(0x1400eb730);
    case 14: return TOOLTIP(0x1400eb8a0);
    case 16: return TOOLTIP(0x1400eb770);
    case 17: return TOOLTIP(0x1400eb7d0);
    case 18: return TOOLTIP(0x1400eb860);
    case 19: return TOOLTIP(0x1400eb760);
    case 20: return TOOLTIP(0x1400eb810);
    case 21: return TOOLTIP(0x1400eb820);
    default: return NULL;
    }
}

static const Image *item_tooltip(u32 item) {
    static const u32 tab[14] = {0x1400eb840, 0x1400eb7a0, 0x1400eb890, 0x1400eb7b0, 0x1400eb850,
                                0x1400eb780, 0x1400eb750, 0x1400eb7e0, 0x1400eb800, 0x1400eb880,
                                0x1400eb8b0, 0x1400eb870, 0x1400eb830, 0x1400eb7c0};
    return item < 14 ? TOOLTIP(tab[item]) : NULL;
}

// --- inventory (0x140007150) ------------------------------------------------
void draw_inventory(void) {
    V2i mi = platform_mouse_pos();
    f32 mx = (f32)mi.x, my = (f32)mi.y;
    for (u32 i = 0; i < g_items.count; i++) {
        if (i >= g_inv_rows.count) TRAP();
        if (g_inv_rows.data[i] == 0xff) {
            if (g_items.data[i] == 0) continue;
            g_inv_next_row++;
            g_inv_rows.data[i] = g_inv_next_row;
        }
        i32 row = g_inv_rows.data[i];
        i32 y = row * (k_inv_slot + 0xc) + k_inv_y;
        u32 have = g_items.data[i];
        u32 fill = have ? 0xff927296u : 0xff4e4664u;
        u32 border = have ? 0xff1c1c1cu : 0xff2c2c2cu;
        if (g_selected_item == (u8)i) {
            fill = 0xff52a896u;
            border = 0xff60ebebu;
        }
        u32 nd = count_digits(have);
        i32 x0 = k_inv_x + 2, y0 = y + 6;
        i32 x1 = k_inv_slot + 0x4e + (i32)nd * k_inv_slot + x0;
        i32 y1 = k_inv_slot + 0x12 + y0;
        if (x0 <= (i32)mx && (i32)mx <= x1 && y0 <= (i32)my && (i32)my <= y1) {
            g_tooltip = item_tooltip(i & 0xff);
            if (g_tooltip) {
                g_tooltip_pos.x = x1 + 4;
                g_tooltip_pos.y = (i32)(my - (f32)((u32)g_tooltip->h & 0x7fffffff));
            }
        }
        draw_box(x0, y0, x1 - x0, y1 - y0, 3, 0xff181818, 0xff624e46);
        draw_box(k_inv_x + 7, y + 0xb, k_inv_slot + 0x44 + (i32)nd * k_inv_slot, k_inv_slot + 8, 2, border, fill);
        blit(g_item_sprites[i], k_inv_x + 0xb, y + 0xf, k_inv_slot >> 4, 0);
        if (i >= g_items.count) TRAP();
        draw_number(g_items.data[i], k_inv_slot + 6 + k_inv_x + 0xb, y + 0xf, k_inv_slot);
    }
}

// 0x140005fe0: click on an inventory slot selects the item for delivery
b32 inventory_click(V2 m) {
    i32 mx = (i32)m.x, my = (i32)m.y;
    if (!(k_inv_x <= mx && mx < k_inv_slot + 0x52 + k_inv_x && k_inv_y <= my)) return 0;
    i32 nrows = (i32)g_items.count - 1;
    if (nrows < 0) nrows = 0;
    if (my >= nrows * 4 + 0x16 + (k_inv_slot + 8) * (i32)g_items.count + k_inv_y) return 0;
    i32 ry = (my - k_inv_y) - 0xb;
    i32 pitch = k_inv_slot + 0xc;
    if ((mx - k_inv_x) - 3 < 0 || ry < 0 || pitch < 1) return 1;
    if (k_inv_slot + 8 <= ry - (i32)((i64)ry / (i64)pitch) * pitch || g_items.count == 0) return 1;
    i32 row = (i32)((i64)ry / (i64)pitch);
    for (u32 i = 0; i < g_items.count; i++) {
        if (g_items.data[i] == 0) continue;
        if (i >= g_inv_rows.count) TRAP();
        if ((i8)g_inv_rows.data[i] != (i8)row) continue;
        if ((i32)i < 0 || i >= g_items.count) return 1;
        if (g_items.data[i & 0xff] == 0) return 1;
        g_selected_item = g_selected_item != (u8)i ? (u8)i : ITEM_NONE;
        return 1;
    }
    return 1;
}

// --- build menu (0x140016dd0, click 0x140009fe0) -----------------------------
typedef struct { i32 cell, cols, rows, x, w; } MenuLayout;
static MenuLayout menu_layout(void) {
    MenuLayout L;
    i32 icon = MAX(k_menu_scale * k_menu_icon, 1);
    L.cell = MAX(0x60, icon + 0x18);
    i32 c = (g_bb_w + (k_menu_margin + k_menu_border) * -2) / L.cell;
    c = MAX(c, 1);
    c = MIN(c, 12);
    L.cols = c;
    u32 r = (u32)((12 % (u32)c) != 0) + 12 / (u32)c;
    L.rows = (i32)MAX(r, 1u);
    L.w = c * L.cell + k_menu_border * 2;
    L.x = MAX((g_bb_w - L.w) - k_menu_margin, 0);
    return L;
}

static i32 menu_hover(void) {
    V2i m = platform_mouse_pos();
    MenuLayout L = menu_layout();
    i32 mx = (i32)(f32)m.x, my = (i32)(f32)m.y;
    if (L.x <= mx && mx < L.x + L.w && k_menu_margin <= my && my < L.rows * L.cell + k_menu_border * 2 + k_menu_margin) {
        i32 ry = (my - k_menu_margin) - k_menu_border, rx = (mx - L.x) - k_menu_border;
        if (rx >= 0 && ry >= 0) {
            rx /= L.cell;
            ry /= L.cell;
            if (rx >= 0 && rx < L.cols && ry >= 0 && ry < L.rows) {
                i32 i = L.cols * ry + rx;
                if (i >= 0 && i < 12) return i;
            }
        }
    }
    return -1;
}

static void darken_rect(i32 x, i32 y, i32 w, i32 h) { blend_rect(x, y, w, h, 0xb4181818); }

static void draw_number_red(u32 n, i32 x, i32 y) {
    if (n == 0) {
        blit_channel2(&g_spr_digits[0], x, y, 2, 0);
        return;
    }
    i32 px = (i32)count_digits(n) * 0x20 + x;
    do {
        blit_channel2(&g_spr_digits[n % 10], px, y, 2, 0);
        px -= 0x20;
        n /= 10;
    } while (n);
}

void draw_build_menu(void) {
    if (!g_menu_open) return;
    MenuLayout L = menu_layout();
    i32 ox = L.x + k_menu_border, oy = k_menu_margin + k_menu_border;
    draw_box(L.x, k_menu_margin, L.w, L.rows * L.cell + k_menu_border * 2, k_menu_border, k_col_panel, k_col_panel_fill);
    i32 hover = menu_hover();
    i32 badge_w = MAX(0x18, L.cell / 3);
    i32 badge_x = L.cell - badge_w;
    i32 badge_h = MAX(0x12, L.cell / 4);
    for (u32 k = 0; k < 12; k++) {
        MenuEntry *me = &g_menu[k];
        i32 cx = (i32)(k % (u32)L.cols) * L.cell + ox;
        i32 cy = (i32)(k / (u32)L.cols) * L.cell + oy;
        u32 afford = me->is_spawn == 1 ? seagull_affordable() : build_affordable(me->id);
        u32 shown = me->is_spawn == 1 ? g_flock.gulls.count : build_affordable(me->id);
        u32 col = afford ? 0x3caa8264u : 0x5a505082u;
        if ((i32)k == hover) col = afford ? 0x5adcbea0u : 0x6e6464aau;
        blend_rect(cx + 1, cy + 1, L.cell - 2, L.cell - 2, col);
        const Sprite *sp;
        if (me->is_spawn == 1) sp = SPR(0x1400eb3c0);
        else sp = me->id == 1 ? SPR(0x1400eaa20) : menu_sprite(me->id);
        if (sp) {
            i32 avail = L.cell - 8;
            i32 sx = MAX(1, avail / MAX(sp->w, 1)), sy = MAX(1, avail / MAX(sp->h, 1));
            i32 sc = MAX(1, MIN(sx, sy));
            i32 dy = avail - sp->h * sc;
            if (dy < 0) dy++;
            i32 dx = avail - sp->w * sc;
            if (dx < 0) dx++;
            blit(sp, (dx >> 1) + 4 + cx, cy + 4 + (dy >> 1), sc, 0);
        }
        darken_rect(cx + badge_x - 4, cy + 4, badge_w, badge_h);
        draw_number(shown, cx + badge_x, cy + 5, 0x10);
        i32 ky = cy + (L.cell - 0x16);
        darken_rect(cx + 4, ky, ((i32)count_digits(k + 1) + 1) * 0x12, 0x12);
        draw_number(k + 1, cx + 5, ky + 1, 0x10);
        if (me->is_spawn == 0 && g_selected_id == me->id) draw_rect_outline(cx, cy, L.cell, L.cell, k_sel_thick, k_col_select);
        else if (!afford) draw_rect_outline(cx, cy, L.cell, L.cell, 2, 0xff5a5ab4);
    }
    if (hover < 0 || hover >= 12) return;
    CostList cost = g_menu[hover].is_spawn == 1 ? seagull_cost() : build_cost(g_menu[hover].id);
    u32 n = cost.n;
    i32 widest = 0;
    for (u32 i = 0; i < n; i++) {
        i32 d = 1;
        for (u32 v = cost.s[i].count; v > 9; v /= 10) d++;
        i32 w = d * 0x20 + 0x28;
        if (w < widest) w = widest;
        widest = w;
    }
    i32 tw = MAX(0x40, widest) + 0x10;
    i32 th = n ? (i32)n * 0x28 + 0x10 : 0;
    i32 rowy = (hover / L.cols) * L.cell + k_menu_margin + k_menu_border;
    i32 ty = L.cell + 8 + rowy;
    i32 tx = (hover % L.cols) * L.cell + L.x + k_menu_border + (L.cell - tw) / 2;
    if (g_bb_h < ty + th) ty = (rowy - th) - 8;
    tx = MIN(MAX(tx, 0), MAX(g_bb_w - tw, 0));
    ty = MIN(MAX(ty, 0), MAX(g_bb_h - th, 0));
    draw_box(tx, ty, tw, th, 2, k_col_panel, 0xeb6c4c3a);
    i32 iy = ty + 0xc;
    for (u32 i = 0; i < n; i++, iy += 0x28) {
        u8 it = cost.s[i].item;
        blit(g_item_sprites[it], tx + 8, iy, 2, 0);
        u32 have = 0;
        if (it < g_items.count) have = g_items.data[it];
        u32 need = cost.s[i].count;
        if (have < need) draw_number_red(need, tx + 0x30, iy);
        else draw_number(need, tx + 0x30, iy, 0x20);
    }
    g_tooltip = build_tooltip(g_menu[hover].id);
    if (g_menu[hover].is_spawn == 1) g_tooltip = TOOLTIP(0x1400eb740);
    else if (!g_tooltip) return;
    V2i m = platform_mouse_pos();
    g_tooltip_pos.y = (n ? 8 : 0) + ty + th;
    g_tooltip_pos.x = (i32)((f32)m.x - (f32)((u32)g_tooltip->w & 0x7fffffff));
}

b32 build_menu_click(V2 m) {
    if (!g_menu_open) return 0;
    MenuLayout L = menu_layout();
    i32 mx = (i32)m.x, my = (i32)m.y;
    if (!(L.x <= mx && mx < L.x + L.w && k_menu_margin <= my &&
          my < (i32)(k_menu_margin + L.rows * L.cell + k_menu_border * 2)))
        return 0;
    my = (my - k_menu_margin) - k_menu_border;
    mx = (mx - L.x) - k_menu_border;
    if (mx >= 0 && my >= 0) {
        mx /= L.cell;
        my /= L.cell;
        if (mx >= 0 && mx < L.cols && my >= 0 && my < L.rows) {
            i32 slot = L.cols * my + mx;
            if (slot < 0 || slot > 11) slot = -1;
            if (slot >= 0) menu_activate((u32)slot);
        }
    }
    g_have_last_cell = 0;
    g_dragging_conveyor = 0;
    return 1;
}

// 0x14001b770: activate a build-menu slot (buy a seagull or pick a building)
void menu_activate(u32 slot) {
    if ((i32)slot < 0 || slot >= 12) return;
    if (g_menu[slot].is_spawn == 1) {
        buy_seagull();
        return;
    }
    u8 id = g_menu[slot].id;
    g_selected_item = ITEM_NONE;
    b32 same = g_selected_id == id;
    g_place_paid = 0;
    g_selected_id = same ? 0 : id;
    for (u32 i = 0; i < 22; i++) {
        if (g_palette_ids[i] == id) {
            g_rotation = 0;
            g_palette_index = (i32)i;
            return;
        }
    }
    g_rotation = 0;
}

// --- full palette (0x1400187b0) ----------------------------------------------
void draw_palette(void) {
    if (!g_palette_open) return;
    i32 cell = MAX(k_menu_scale * k_menu_icon, 1);
    i32 c = (g_bb_w + (k_menu_margin + k_menu_border) * -2) / cell;
    u32 cols = (u32)MAX(c, 1);
    u32 r = (u32)((22 % cols) != 0) + 22 / cols;
    i32 pw = (i32)cols * cell + k_menu_border * 2;
    i32 px = MAX((g_bb_w - k_menu_margin) - pw, 0);
    i32 ox = k_menu_border + px, oy = k_menu_border + k_menu_margin;
    V2i m = platform_mouse_pos();
    f32 mx = (f32)m.x, my = (f32)m.y;
    draw_box(px, k_menu_margin, pw, (i32)MAX(r, 1u) * cell + k_menu_border * 2, k_menu_border, k_col_panel, k_col_panel_fill);
    for (u32 k = 0; k < 22; k++) {
        if (k >= g_palette_sprites.count) TRAP();
        const Sprite *sp = g_palette_sprites.data[k];
        if (!sp) continue;
        i32 cx = (i32)(k % cols) * cell + ox;
        i32 cy = (i32)(k / cols) * cell + oy;
        i32 sx = MAX(1, cell / MAX(sp->w, 1)), sy = MAX(1, cell / MAX(sp->h, 1));
        i32 sc = MAX(1, MIN(sx, sy));
        blit(sp, cx + (cell - sp->w * sc) / 2, cy + (cell - sp->h * sc) / 2, sc, 0);
        if (cx <= (i32)mx && (i32)mx <= cx + cell && cy <= (i32)my && (i32)my <= cy + cell)
            g_tooltip = build_tooltip(g_palette_ids[k]);
        if (g_palette_ids[k] == 1) draw_rect_outline(cx, cy, cell, cell, 2, 0xff5050b4);
    }
    draw_rect_outline((g_palette_index % (i32)cols) * cell + ox, (g_palette_index / (i32)cols) * cell + oy, cell, cell,
                      k_sel_thick, k_col_select);
    u8 s = g_selected_id;
    if (s == 10 || s == 11 || s == 12 || s == 13 || s == 18) {
        u32 col = 0xff50dcdcu;
        if (g_rotation == 1) col = 0xffdcdc50u;
        else if (g_rotation == 2) col = 0xff5078dcu;
        else if (g_rotation == 3) col = 0xffdc50b4u;
        draw_box(px + (pw - 0xe), k_menu_margin + 4, 10, 10, 1, 0xff000000, col);
    }
}

// --- recipe picker (0x140006dd0 draw, 0x140006170 click, 0x14000a650 hover) --
typedef struct { i32 cell, cols, rows, x, y, w, h; } PickLayout;
static PickLayout picker_layout(void) {
    PickLayout L;
    L.cell = MAX(k_pick_scale * k_pick_icon, 1);
    i32 cols, cols2;
    if (!g_picker_anchored) {
        i32 c = (g_bb_w + (k_pick_margin + k_pick_border) * -2) / L.cell;
        cols = MAX(c, 1);
        i64 c2 = (i64)(g_bb_w + (k_pick_margin + k_pick_border) * -2) / (i64)L.cell;
        cols2 = (i32)MAX(c2, 1);
    } else {
        cols = MIN(MAX((i32)g_picker_icons.count, 1), 4);
        cols2 = cols;
    }
    i32 rows = (i32)((g_picker_icons.count % (u32)cols2) != 0) + (i32)(g_picker_icons.count / (u32)cols2);
    L.rows = MAX(rows, 1);
    L.cols = cols;
    L.w = L.cell * cols + k_pick_border * 2;
    L.h = L.rows * L.cell + k_pick_border * 2;
    L.x = k_pick_margin;
    L.y = k_pick_margin;
    if (g_picker_anchored) {
        i32 x = g_picker_anchor.x - L.w / 2;
        i32 maxx = MAX(g_bb_w - L.w, 0);
        x = MAX(x, 0);
        L.x = MIN(x, maxx);
        i32 maxy = MAX(g_bb_h - L.h, 0);
        i32 y = (g_picker_anchor.y - L.h) - k_pick_lift;
        y = MAX(y, 0);
        L.y = MIN(y, maxy);
    }
    return L;
}

void draw_recipe_picker(void) {
    if (!g_picker_open) return;
    PickLayout L = picker_layout();
    i32 ox = L.x + k_pick_border, oy = L.y + k_pick_border;
    draw_box(L.x, L.y, L.w, L.h, k_pick_border, k_col_frame, k_col_frame_fill);
    for (u32 i = 0; i < g_picker_icons.count; i++) {
        const Sprite *sp = g_picker_icons.data[i];
        if (!sp) continue;
        i32 sx = MAX(1, L.cell / MAX(sp->w, 1)), sy = MAX(1, L.cell / MAX(sp->h, 1));
        i32 sc = MAX(1, MIN(sx, sy));
        i32 dy = L.cell - sp->h * sc;
        if (dy < 0) dy++;
        i32 dx = L.cell - sp->w * sc;
        if (dx < 0) dx++;
        blit(sp, (i32)(i % (u32)L.cols) * L.cell + ox + (dx >> 1), (i32)(i / (u32)L.cols) * L.cell + oy + (dy >> 1), sc, 0);
    }
    if (g_picker_selected != -1)
        draw_rect_outline((g_picker_selected % L.cols) * L.cell + ox, (g_picker_selected / L.cols) * L.cell + oy, L.cell,
                          L.cell, k_pick_sel, k_col_highlight);
}

i32 picker_hover(void) {
    if (!g_picker_open) return -1;
    PickLayout L = picker_layout();
    V2i m = platform_mouse_pos();
    i32 rx = (i32)(f32)m.x - (L.x + k_pick_border);
    i32 ry = (i32)(f32)m.y - (L.y + k_pick_border);
    if (rx >= 0 && ry >= 0 && rx < L.cell * L.cols && ry < L.rows * L.cell) {
        i32 i = (ry / L.cell) * L.cols + rx / L.cell;
        if (i < 0 || (u32)i >= g_picker_icons.count) i = -1;
        return i;
    }
    return -1;
}

b32 picker_click(V2 m) {
    if (!g_picker_open) return 0;
    PickLayout L = picker_layout();
    i32 rx = ((i32)m.x - k_pick_border) - L.x;
    i32 ry = ((i32)m.y - L.y) - k_pick_border;
    if (rx >= 0 && rx < L.cell * L.cols && ry >= 0 && ry < L.rows * L.cell) {
        i32 i = (ry / L.cell) * L.cols + rx / L.cell;
        if (i >= 0 && (u32)i < g_picker_icons.count) {
            b32 same = i == g_picker_selected;
            g_picker_selected = same ? -1 : i;
            if (g_picker_fn) g_picker_fn((u32)i);
            g_picker_open = 0;
            g_picker_anchored = 0;
        }
        return 1;
    }
    return 0;
}

// 0x14001b810
i32 entity_recipe_index(Entity *e) {
    if (!e->recipe) TRAP();
    if (e->serial && e->type != 1 && e->recipes && e->recipes->count > 1) {
        for (u32 i = 0; i < e->recipes->count; i++)
            if (e->recipes->data[i] == e->recipe) return (i32)i;
    }
    return -1;
}

// 0x140012280
void picker_open_for(Entity *e) {
    g_picker_entity = NULL;
    if (e && e->serial && e->type != 1 && e->recipes && e->recipes->count > 1) {
        RecipeBook *rb = (RecipeBook *)e->recipes;
        memcpy(&g_picker_icons, &rb->icons, sizeof g_picker_icons);
        g_picker_selected = -1;
        g_picker_fn = picker_choose;
        g_picker_open = 1;
        g_picker_entity = e;
        g_picker_serial = e->serial;
        g_picker_selected = entity_recipe_index(e);
        if (g_picker_selected < 0 || (u32)g_picker_selected >= g_picker_icons.count) g_picker_selected = -1;
        V2i m = platform_mouse_pos();
        g_picker_anchor = v2i((i32)(f32)m.x, (i32)(f32)m.y);
        g_picker_open = 1;
        g_picker_anchored = 1;
        return;
    }
    g_picker_open = 0;
    g_picker_anchored = 0;
}

// 0x140014750: the player chose a recipe for the picker's building
void picker_choose(u32 index) {
    Entity *e = g_picker_entity;
    if (e && e->serial && e->serial == g_picker_serial) {
        g_picker_entity = NULL;
        RecipeList *rl = e->recipes;
        if (rl && index < rl->count) {
            Recipe *r = rl->data[index];
            if (r != e->recipe) {
                for (u32 k = 0; k < 3; k++) {
                    if (*ent_in_count(e, k)) {
                        u8 it = *ent_in_item(e, k);
                        if (it >= g_items.count) TRAP();
                        g_items.data[it] += *ent_in_count(e, k);
                    }
                    // (original quirk: every slot gets the first input's item)
                    u8 *s = (u8 *)e + 0x3c + 8 * k;
                    memset(s, 0, 8);
                    s[0] = r->in[0].item;
                }
                e->recipe = r;
                e->recipe_time = r->time;
                e->f134 = 0;
            }
            if ((i32)index < 0 || index >= g_picker_icons.count) index = (u32)-1;
            g_picker_selected = (i32)index;
            g_picker_open = 0;
            g_picker_anchored = 0;
            return;
        }
    }
    g_picker_entity = NULL;
    g_picker_open = 0;
    g_picker_anchored = 0;
}

// --- hover info over buildings (0x140018be0 and helpers) ---------------------
// 0x140010ef0
static b32 entity_hovered(Entity *e, i32 zoom) {
    if (!e || !e->serial) return 0;
    V2 m = mouse_pos_f();
    i32 x = (i32)e->pos.x * g_zoom * 16 - cam_x();
    i32 y = (i32)e->pos.y * g_zoom * 16 - cam_y();
    if ((f32)x <= m.x && m.x < (f32)(zoom * (i32)e->w * 16 + x) && (f32)y <= m.y && m.y < (f32)(zoom * (i32)e->h * 16 + y))
        return 1;
    const Sprite *s = e->sprite;
    if (s) {
        i32 sx = (((i32)e->w * 16 - s->w) * zoom) / 2 + x;
        i32 sy = ((i32)e->h * 16 - s->h) * zoom + y;
        if ((f32)sx <= m.x && m.x < (f32)(s->w * zoom + sx) && (f32)sy <= m.y && m.y < (f32)(s->h * zoom + sy)) return 1;
    }
    return 0;
}

static b32 picker_target_valid(void) {
    return g_picker_entity && g_picker_entity->serial && g_picker_entity->serial == g_picker_serial;
}

// 0x140017d70: recipe icon above a building
static void draw_recipe_icon(Entity *e, i32 zoom) {
    if (!e || !e->recipe || !e->recipe->icon || e->type == 1) return;
    if (!entity_hovered(e, zoom) && !(g_picker_open && picker_target_valid() && g_picker_entity == e)) return;
    i32 s = MAX(1, zoom);
    i32 pad = MAX(2, zoom / 2);
    i32 b = pad + s * 8;
    i32 x = ((i32)e->pos.x * g_zoom * 16 + (zoom * (i32)e->w * 16 + b * -2) / 2) - cam_x();
    i32 y = ((i32)e->pos.y * g_zoom * 16 - cam_y()) + b * -2 - 6;
    draw_box(x, y, b * 2, b * 2, 2, 0xff000000, 0xff485c48);
    blit(e->recipe->icon, x + pad, pad + y, s, 0);
}

// 0x140007b10: are all inputs present?
static b32 inputs_ready(Entity *e) {
    Recipe *r = e->recipe;
    if (!r) TRAP();
    if (r->n_in == 0) return *ent_in_count(e, 0) != 0 || *ent_in_count(e, 2) != 0;
    for (u32 i = 0; i < r->n_in; i++)
        if (*ent_in_count(e, i) < r->in[i].count) return 0;
    return 1;
}

// 0x140017b20: crafting progress bar
static void draw_progress(Entity *e, i32 zoom) {
    if (!e || !e->recipe || e->type == 1 || (u32)(e->type - 5) <= 4) return;
    f32 time = e->recipe->time;
    if (0.0f >= time || !inputs_ready(e)) return;
    f32 timer = e->recipe ? e->recipe_time : 0.0f;
    if (timer >= time) return;
    i32 W = MAX(0x14, zoom * (i32)e->w * 16);
    i32 H = MAX(6, zoom + 4);
    i32 x = (i32)e->pos.x * g_zoom * 16 + (zoom * (i32)e->w * 16 - W) / 2 - cam_x();
    i32 y = (((i32)e->pos.y * g_zoom - MAX(1, zoom)) * 8 - MAX(2, zoom / 2)) * 2 - 10 - cam_y() - H;
    draw_box(x, y, W, H, 1, 0xff000000, 0xff282828);
    f32 p = sse_min(1.0f, sse_max(0.0f, timer / time));
    i32 fw = (i32)floorf((1.0f - p) * (f32)MAX(0, W - 2) + 0.5f);
    if (fw > 0) draw_box(x + 1, y + 1, fw, MAX(1, H - 2), 0, 0xff5ad2ff, 0xff5ad2ff);
}

// 0x140018440: ingredient list of a recipe
static void draw_recipe_tooltip(const Recipe *r) {
    i32 h = r->n_in == 0 ? 0x38 : (i32)r->n_in * 0x28 + 0x10;
    i32 x, y;
    if (!g_picker_open) {
        V2i m = platform_mouse_pos();
        x = (i32)(f32)m.x + 0x10;
        y = (i32)(f32)m.y + 0x10;
    } else {
        PickLayout L = picker_layout();
        y = L.y + 8 + L.h;
        x = L.x + (L.w - 0x50) / 2;
    }
    if (g_bb_h < y + h) {
        y = 0;
        if (g_bb_h - h > 0) y = g_bb_h - h;
    }
    x = MIN(MAX(x, 0), MAX(g_bb_w - 0x50, 0));
    y = MIN(MAX(y, 0), MAX(g_bb_h - h, 0));
    draw_box(x, y, 0x50, h, 2, 0xff000000, 0xeb6c4c3a);
    if (r->n_in == 0) {
        if (r->out.item < 14 && g_item_sprites[r->out.item]) {
            blit(g_item_sprites[r->out.item], x + 8, y + 0xc, 2, 0);
            draw_number(r->out.count, x + 0x30, y + 0xc, 0x20);
        }
        return;
    }
    y += 0xc;
    for (u32 i = 0; i < r->n_in; i++, y += 0x28) {
        u8 it = r->in[i].item;
        if (it < 14 && g_item_sprites[it]) {
            blit(g_item_sprites[it], x + 8, y, 2, 0);
            draw_number(r->in[i].count, x + 0x30, y, 0x20);
        }
    }
}

void draw_hover_info(i32 zoom) {
    i32 hovered = -1;
    if (g_picker_open) {
        if (!picker_target_valid()) {
            g_picker_open = 0;
            g_picker_anchored = 0;
        } else {
            Entity *e = g_picker_entity;
            g_picker_anchored = 1;
            g_picker_anchor.x = (zoom * (i32)e->w + (i32)e->pos.x * g_zoom * 2) * 8 - cam_x();
            g_picker_anchor.y = ((i32)e->pos.y * g_zoom * 16 - cam_y()) - 6;
            g_picker_selected = entity_recipe_index(e);
            if (g_picker_selected < 0 || (u32)g_picker_selected >= g_picker_icons.count) g_picker_selected = -1;
            hovered = picker_hover();
        }
    }
    for (u32 k = 0; k < g_entity_list.count; k++) {
        Entity *e = g_entity_list.data[k];
        if (e && e->sprite) {
            draw_recipe_icon(e, zoom);
            draw_progress(e, zoom);
        }
    }
    if (g_picker_open && picker_target_valid() && hovered >= 0) {
        RecipeList *rl = g_picker_entity->recipes;
        if (rl && (u32)hovered < rl->count) draw_recipe_tooltip(rl->data[hovered]);
    }
}

// --- hive status panel (0x140017ef0) -----------------------------------------
void draw_home_hud(V2 cam, i32 zoom) {
    if (g_homes.count == 0 || !g_homes.data) return;
    Home *h = &g_homes.data[0];
    i32 sz = h->big ? 2 : 1;
    i32 W = MAX(0x78, zoom * 0x20);
    i32 rh = MAX(0x14, zoom * 8);
    i32 H = rh * 3 + 0x26;
    f32 z16 = (f32)(zoom << 4);
    i32 x = (sz * zoom * 8 - W / 2) + (i32)floorf((z16 * (f32)h->pos.x - cam.x) + 0.5f);
    i32 yb = (i32)floorf((z16 * (f32)h->pos.y - cam.y) + 0.5f) - H;
    i32 y = yb - 8;
    blend_rect(x, y, W, H, 0xd2121212);
    fill_rect(x, y, W, 1, 0xff46b4d2);
    fill_rect(x, y + H - 1, W, 1, 0xff46b4d2);
    fill_rect(x, y, 1, H, 0xff46b4d2);
    fill_rect(W - 1 + x, y, 1, H, 0xff46b4d2);
    i32 iy = yb - 2, ix = x + 4;
    i32 s = MAX(1, (zoom * 3) / 4);
    i32 row3 = iy + rh * 2;
    i32 tx = s * 16 + 4 + ix;
    blend_rect(x + 2, yb - 3, W - 4, rh, 0x465aa05a);
    blend_rect(x + 2, yb - 3 + rh, W - 4, rh, 0x463c96be);
    blend_rect(x + 2, row3 - 1, W - 4, rh, 0x46be785a);
    blit(g_item_sprites[ITEM_POLLEN], ix, iy, s, 0);
    draw_number(g_items.count > 11 ? g_items.data[ITEM_POLLEN] : 0, tx, iy, 0x10);
    blit(g_item_sprites[ITEM_HONEY], ix, iy + rh, s, 0);
    draw_number(g_items.count > 12 ? g_items.data[ITEM_HONEY] : 0, tx, iy + rh, 0x10);
    blit(SPR(0x1400eac40), ix, row3, s, 0);
    draw_number(g_flock.gulls.count, tx, row3, 0x10);
    i32 bh = MAX(0x10, zoom * 4);
    f32 p = sse_min(1.0f, sse_max(0.0f, g_honey_timer / 10.0f));
    fill_rect(x + 6, y + H - 0x16, W - 0xc, bh, 0xff0f0f0f);
    fill_rect(x + 7, y + H - 0x15, W - 0xe, bh - 2, 0xff1e2d37);
    fill_rect(x + 7, y + H - 0x15, (i32)floorf((f32)(W - 0xe) * p + 0.5f), bh - 2, 0xff46c8ff);
}

// --- seagulls (0x140016830, progress 0x140016690, idle test 0x14000d8e0) -----
static b32 seagull_resting(Seagull *s) {
    if (s->state || s->busy) return 0;
    f32 dx = s->pos.x - ((f32)s->home.x + s->home_off.x);
    f32 dy = s->pos.y - ((f32)s->home.y + s->home_off.y);
    return dy * dy + dx * dx <= 9.99999975e-05f;
}

static void draw_work_bar(Seagull *s, V2 cam, i32 zoom) {
    if (s->state != SG_WORKING || !s->busy) return;
    Order *o = SG_ORDER(s);
    if (!(0.0f < o->duration)) return;
    f32 p = sse_min(1.0f, sse_max(0.0f, s->work / o->duration));
    i32 bw = MAX(0xc, (zoom * 0x12) / 4);
    i32 bh = MAX(3, zoom);
    f32 z16 = (f32)(zoom << 4);
    i32 x = (i32)floorf((s->pos.x * z16 - cam.x) + 0.5f) - bw / 2;
    i32 lift = MAX(10, zoom * 3);
    i32 y = (i32)floorf((s->pos.y * z16 - cam.y) + 0.5f) - lift;
    fill_rect(x - 1, y - 1, bw + 2, bh + 2, 0xff000000);
    fill_rect(x, y, bw, bh, 0xff3c3c3c);
    fill_rect(x, y, (i32)floorf((f32)bw * p + 0.5f), bh, 0xff50dc28);
}

void draw_seagulls(V2 cam, i32 zoom, f64 t) {
    for (u32 i = 0; i < g_flock.gulls.count; i++) {
        Seagull *s = &g_flock.gulls.data[i];
        if (seagull_resting(s)) continue;
        const Sprite *sp;
        if (s->state == SG_WORKING) sp = SPR(0x1400eac60);
        else sp = s->carry_count == 0 ? SPR(0x1400eac40) : SPR(0x1400eac80);
        f64 ph = (f64)s->phase + t * 6.0;
        f32 frac = (f32)(ph - trunc(ph));
        u32 frames = (u32)sp->frames;
        u32 frame = (u32)((u64)(i64)(frac * (f32)frames) & 0xffffffffu) % frames;
        f32 z16 = (f32)(zoom << 4);
        i32 x = (i32)floorf(((z16 * s->pos.x - cam.x) - (f32)(u32)(zoom * sp->w) * 0.5f) + 0.5f);
        i32 y = (i32)floorf(((z16 * s->pos.y - cam.y) - (f32)(u32)(zoom * sp->h) * 0.5f) + 0.5f);
        blit(sp, x, y, zoom, (i32)frame);
        draw_work_bar(s, cam, zoom);
    }
}

// --- range ring while Space is held (0x140016a50) ----------------------------
void draw_home_range(const Home *h, V2 cam, i32 zoom) {
    i32 z16 = zoom << 4;
    f32 fz = (f32)z16;
    i32 x0 = MAX((i32)floorf(cam.x / fz) - 1, 0);
    i32 y0 = MAX((i32)floorf(cam.y / fz) - 1, 0);
    i32 x1 = MIN((i32)floorf((((f32)g_bb_w + cam.x) - 1.0f) / fz) + 1, (i32)g_map.w - 1);
    i32 y1 = MIN((i32)floorf((((f32)g_bb_h + cam.y) - 1.0f) / fz) + 1, (i32)g_map.h - 1);
    u32 sz = h->big ? 2 : 1;
    i32 r = h->big ? 0x14 : 9;
    x0 = MAX(x0, ((i32)h->pos.x - r) - 1);
    y0 = MAX(y0, ((i32)h->pos.y - r) - 1);
    x1 = MIN(x1, (i32)h->pos.x + (i32)sz + r);
    y1 = MIN(y1, (i32)sz + (i32)h->pos.y + r);
    if (x0 > x1 || y0 > y1) return;
    f32 hx = (f32)h->pos.x, hy = (f32)h->pos.y;
    f32 hx1 = (f32)sz + hx, hy1 = (f32)sz + hy;
    f32 inner = sse_max((f32)r - (h->big ? 1.10000002f : 0.899999976f), 0.0f);
    f32 in2 = inner * inner, out2 = (f32)r * (f32)r;
    for (i32 y = y0; y <= y1; y++) {
        f32 fy = (f32)(u32)y;
        f32 cy = (fy + 0.5f) - sse_min(hy1, sse_max(hy, fy + 0.5f));
        f32 dy2 = cy * cy;
        for (i32 x = x0; x <= x1; x++) {
            f32 fx = (f32)(u32)x + 0.5f;
            f32 cx = fx - sse_min(hx1, sse_max(hx, fx));
            f32 d = cx * cx + dy2;
            if (d <= out2 && in2 <= d) {
                i32 py = (i32)floorf((fy * fz - cam.y) + 0.5f);
                i32 px = (i32)floorf(((f32)(u32)x * fz - cam.x) + 0.5f);
                blend_rect(px, py, z16, z16, 0x685aff28);
            }
        }
    }
}
