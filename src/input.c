// Keyboard and mouse handling (window callbacks and per-frame polling).
#include "game.h"

static const i32 k_tutorial_scale = 3;  // 0x140029070

static void reset_selection(void) {
    g_palette_open = 0;
    g_picker_open = 0;
    g_picker_entity = NULL;
    g_menu_open = 0;
    g_click_consumed = 0;
    g_selected_id = 0;
    g_place_paid = 0;
    g_dragging_conveyor = 0;
    g_selected_item = ITEM_NONE;
    g_rotation = 0;
    for (u32 i = 0; i < 22; i++)
        if (g_palette_ids[i] == 0) {
            g_palette_index = (i32)i;
            break;
        }
}

static void select_id(u8 id) {
    g_selected_id = g_selected_id == id ? 0 : id;
    g_place_paid = 0;
    g_rotation = 0;
    for (u32 i = 0; i < 22; i++)
        if (g_palette_ids[i] == id) {
            g_palette_index = (i32)i;
            return;
        }
}

// 0x14000d950
void on_key(u32 vk, b32 down) {
    if (vk == VK_CONTROL) g_layer = down == 1;
    if (down != 1) return;
    i32 slot = -1;
    if (vk - 0x31u < 9) slot = (i32)(vk - 0x31);
    else if (vk == 0x30) slot = 9;
    else if (vk == 0xbd) slot = 10;  // '-'
    else if (vk == 0xbb) slot = 11;  // '='
    if (slot >= 0) {
        menu_activate((u32)slot);
        return;
    }
    b32 caps = g_key_down[VK_CAPITAL] != 0;
    switch (vk) {
    case 'R':
        if (caps) {
            new_game(g_start);
            camera_center(g_start);
            g_drag_camera = 0;
            g_have_last_cell = 0;
            g_drag_dir = -1;
            g_right_drag = 0;
            reset_selection();
            return;
        }
        if (g_selected_id != 10 && g_selected_id != 11 && g_selected_id != 12 && g_selected_id != 13 &&
            g_selected_id != 18)
            return;
        if (g_key_down[VK_SHIFT]) g_rotation = g_rotation == 0 ? 3 : g_rotation == 1 ? 0 : g_rotation == 2 ? 1 : 2;
        else g_rotation = g_rotation == 0 ? 1 : g_rotation == 1 ? 2 : g_rotation == 2 ? 3 : 0;
        return;
    case VK_TAB:
        g_picker_entity = NULL;
        if (!caps) {
            if (g_menu_open) {
                g_click_consumed = 0;
                g_have_last_cell = 0;
                g_dragging_conveyor = 0;
                g_menu_open = 0;
                return;
            }
            g_menu_open = 1;
            g_picker_open = 0;
        } else {
            g_menu_open = 0;
            if (!g_palette_open) {
                g_palette_open = 1;
                g_click_consumed = 0;
                g_have_last_cell = 0;
                g_dragging_conveyor = 0;
                g_picker_open = 0;
                return;
            }
        }
        g_palette_open = 0;
        g_have_last_cell = 0;
        g_click_consumed = 0;
        g_dragging_conveyor = 0;
        return;
    case 'E':
        if (!caps) return;
        for (u32 i = 0; i < g_items.count; i++) g_items.data[i] = 50;
        return;
    case VK_ESCAPE:
        reset_selection();
        return;
    case 'Q': {
        V2i cell = {0, 0};
        if (!cursor_cell(&cell)) return;
        Entity *e = entity_at(v2u_make((u32)cell.x, (u32)cell.y), g_layer);
        u8 id = 0;
        if (e && e->serial && e->type >= 1 && e->type <= 10) id = (u8)(e->type + 9);
        select_id(id);
        return;
    }
    }
}

// 0x1400107d0
static void on_mouse_button(i32 button, b32 down, f32 wheel) {
    if (button == 0) {
        i32 step;
        if (wheel > 0.0f) step = -1;
        else if (wheel < 0.0f) step = 1;
        else return;
        if (!g_key_down[VK_SHIFT]) {
            V2 m = mouse_pos_f();
            i32 z = g_zoom - step;
            if (z < 1) z = 1;
            if (z > 200) z = 200;
            if (z == g_zoom) return;
            f32 inv = 1.0f / (f32)(g_zoom << 4);
            g_zoom = z;
            f32 fx = (f32)(z << 4) * ((m.x + g_cam.x) * inv) - m.x;
            f32 fy = (f32)(z << 4) * ((m.y + g_cam.y) * inv) - m.y;
            g_cam.x = sse_min(sse_max((f32)(z * (i32)g_map.w * 16 - g_bb_w) + 250.0f, -250.0f), sse_max(-250.0f, fx));
            g_cam.y = sse_min(sse_max((f32)(z * (i32)g_map.h * 16 - g_bb_h) + 250.0f, -250.0f), sse_max(-250.0f, fy));
            return;
        }
        f32 v = ((f32)(g_zoom << 4) * (f32)step) * 2.5f + g_cam.x;
        g_cam.x = sse_min(sse_max((f32)((i32)g_map.w * g_zoom * 16 - g_bb_w) + 250.0f, -250.0f), sse_max(-250.0f, v));
        g_cam.y = sse_min(sse_max((f32)((i32)g_map.h * g_zoom * 16 - g_bb_h) + 250.0f, -250.0f),
                          sse_max(-250.0f, g_cam.y));
        return;
    }
    V2i mi = platform_mouse_pos();
    V2 m = v2((f32)mi.x, (f32)mi.y);
    if (button == 2 && down == 1) {
        if (g_menu_open && !menu_contains(m)) {
            g_picker_entity = NULL;
            g_menu_open = 0;
        }
        if (g_palette_open) return;
        V2i cell = {0, 0};
        if (!cursor_cell(&cell)) return;
        Entity *e = entity_at(v2u_make((u32)cell.x, (u32)cell.y), 0);
        Entity *prev = g_picker_entity;
        if (g_layer || !e || !e->serial || e->type == 1 || !e->recipes || e->recipes->count < 2) return;
        g_picker_entity = NULL;
        g_menu_open = 0;
        g_palette_open = 0;
        g_selected_item = ITEM_NONE;
        if (prev == e) return;
        picker_open_for(e);
        g_click_consumed = 1;
        g_have_last_cell = 0;
        g_dragging_conveyor = 0;
        g_right_drag = 1;
        return;
    }
    if (button == 1 && down == 1) {
        g_click_consumed = inventory_click(m);
        if (g_click_consumed) return;
        if (g_menu_open && build_menu_click(m)) {
            g_click_consumed = 1;
            return;
        }
        g_click_consumed = 0;
        if (g_palette_open) {
            g_click_consumed = palette_click(m);
            return;
        }
        if (g_picker_open) {
            if (picker_click(m)) {
                g_click_consumed = 1;
                return;
            }
            g_click_consumed = 0;
            if (g_picker_entity) {
                g_picker_entity = NULL;
                g_menu_open = 0;
            }
        }
        if (g_selected_item != ITEM_NONE) {
            V2i cell = {0, 0};
            if (!cursor_cell(&cell)) return;
            if (!order_deliver(v2u_make((u32)cell.x, (u32)cell.y), g_selected_item, 1)) return;
            if (!g_key_down[VK_SHIFT]) g_selected_item = ITEM_NONE;
            g_click_consumed = 1;
            return;
        }
        if (g_palette_open || g_picker_open || g_key_down[VK_SHIFT]) return;
        V2i cell = {0, 0};
        if (!cursor_cell(&cell)) return;
        if (!order_take_from_conveyor(v2u_make((u32)cell.x, (u32)cell.y), 1)) return;
        g_have_last_cell = 0;
        g_dragging_conveyor = 0;
        g_right_drag = 1;
        return;
    }
    if (button != 1 && button != 2) return;
    if (down == 0) {
        g_have_last_cell = 0;
        g_dragging_conveyor = 0;
        if (button == 1) {
            g_drag_camera = 0;
            g_click_consumed = 0;
        } else {
            g_right_drag = 0;
        }
    }
}

static b32 mouse_in_image(const Image *img) {
    i32 x = (g_bb_w - img->w * k_tutorial_scale) / 2;
    if (x < 0) x = 0;
    f32 x0 = (f32)x;
    f32 x1 = (f32)(u32)(img->w * k_tutorial_scale) + x0;
    i32 y = g_bb_h - k_tutorial_scale * img->h;
    if (y < 0) y = 0;
    f32 y0 = (f32)y;
    f32 y1 = (f32)(u32)(k_tutorial_scale * img->h) + y0;
    V2 m = mouse_pos_f();
    return x0 <= m.x && m.x <= x1 && y0 <= m.y && m.y <= y1;
}

// 0x1400105e0: clicking a tutorial page (or the victory screen) advances it on release
void on_mouse(i32 button, b32 down, f32 wheel) {
    if (button != 0 && down == 0) {
        if (g_tutorial_page < 9 && mouse_in_image(&g_tutorial[g_tutorial_page])) g_tutorial_page++;
        // the original measures the current tutorial slot here too (index 9 is the controls image)
        if (g_won && !g_win_dismissed && g_tutorial_page <= 9 && mouse_in_image(&g_tutorial[g_tutorial_page]))
            g_win_dismissed++;
    }
    on_mouse_button(button, down, wheel);
}

// 0x14001efa0: held buttons -> camera drag, building, demolishing
void frame_input(void) {
    b32 left = g_mouse_down[1] != 0;
    f32 dx = (f32)g_raw_mouse_delta.x;
    f32 dy = (f32)g_raw_mouse_delta.y;
    g_raw_mouse_delta = (V2i){0, 0};
    b32 right = g_mouse_down[2] != 0;
    if (!left) g_click_consumed = 0;
    if (g_right_drag) {
        if (!right) {
            g_right_drag = 0;
            g_dragging_conveyor = 0;
            g_have_last_cell = 0;
        }
        return;
    }
    if (((g_key_down[VK_SHIFT] && left) || g_mouse_down[3]) && !g_click_consumed && !g_palette_open && !g_picker_open) {
        g_cam.x -= dx;
        g_cam.y -= dy;
        g_drag_camera = 1;
        g_have_last_cell = 0;
        g_dragging_conveyor = 0;
        camera_clamp();
        return;
    }
    g_drag_camera = 0;
    if (g_key_down[VK_SHIFT] || g_palette_open || g_picker_open || g_click_consumed) {
        if (left || right) {
            g_raw_mouse_delta = (V2i){0, 0};
            g_drag_camera = 0;
            return;
        }
    } else {
        if (left) {
            use_tool(g_selected_id);
            return;
        }
        g_dragging_conveyor = 0;
        if (right) {
            V2i cell = {0, 0};
            if (!cursor_cell(&cell)) return;
            if (g_have_last_cell && cell.x == g_last_cell.x && cell.y == g_last_cell.y) return;
            g_last_cell = cell;
            g_have_last_cell = 1;
            if (g_selected_id != 0) apply_tool(1, v2u_make((u32)cell.x, (u32)cell.y), g_layer, g_rotation, g_place_paid);
            else cancel_order_at(&g_flock, cell);
            return;
        }
    }
    g_dragging_conveyor = 0;
    g_have_last_cell = 0;
}
