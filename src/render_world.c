// Drawing the map, buildings and items (0x1400150c0, 0x1400156c0, 0x1400161b0).
#include "game.h"

static inline i32 cam_x(void) { return (i32)floorf(g_cam.x); }
static inline i32 cam_y(void) { return (i32)floorf(g_cam.y); }

// 0x1400161b0
void draw_tiles(V2 cam, i32 zoom) {
    i32 z16 = zoom * 16;
    i32 cx = (i32)floorf(cam.x), cy = (i32)floorf(cam.y);
    i32 xe = (i32)(((i64)(z16 - 1 + (i32)ceilf((f32)g_bb_w + cam.x))) / z16);
    i32 ye = (z16 - 1 + (i32)ceilf((f32)g_bb_h + cam.y)) / z16;
    i32 y0 = (i32)((i64)cy / z16);
    if (y0 < 0) y0 = 0;
    i32 x0 = (i32)((i64)cx / z16);
    if (x0 < 0) x0 = 0;
    i32 w = (i32)g_map.w, h = (i32)g_map.h;
    i32 y1 = ye < h ? ye : h;
    i32 x1 = xe < w ? xe : w;
    for (i32 y = y0; y < y1; y++) {
        for (i32 x = x0; x < x1; x++) {
            u32 i = (u32)(y * w + x);
            u8 t = g_tiles[i];
            const Sprite *sp;
            if (t == TILE_WATER) {
                b32 up = !(x < 0 || y - 1 < 0 || x >= w || y - 1 >= h) && g_tiles[(u32)((y - 1) * w + x)] == TILE_WATER;
                b32 left = !(x - 1 < 0 || x - 1 >= w || y >= h) && g_tiles[(u32)(y * w + x - 1)] == TILE_WATER;
                b32 right = !(x + 1 < 0 || x + 1 >= w || y >= h) && g_tiles[(u32)(x + 1 + y * w)] == TILE_WATER;
                if (up) {
                    if (left) sp = right ? SPR(0x1400eb4c0) : SPR(0x1400eb520);
                    else sp = right ? SPR(0x1400eb500) : SPR(0x1400eb4c0);
                } else if (left) {
                    sp = right ? SPR(0x1400eb4e0) : SPR(0x1400eb560);
                } else {
                    sp = right ? SPR(0x1400eb540) : SPR(0x1400eb4e0);
                }
            } else {
                sp = g_tile_sprites[t];
            }
            u32 tt = ((u32)x >= g_map.w || (u32)y >= g_map.h) ? 0 : t;
            i32 frame = 0;
            u16 amt = 0;
            b32 ore = 1;
            if (tt == TILE_IRON) amt = g_ore_iron[i];
            else if (tt == TILE_COPPER) amt = g_ore_copper[i];
            else if (tt == TILE_FLOWERS) amt = g_ore_flowers[i];
            else ore = 0;
            if (ore && amt >= 0x14) frame = amt < 0x5a ? 1 : 3 - (amt < 200);
            blit_opaque(sp, x * z16 - cx, y * z16 - cy, zoom, frame);
        }
    }
    // items waiting on nests
    i32 s = (i32)((f32)zoom * 16.0f);
    f32 fs = (f32)s;
    for (u32 k = 0; k < g_bee_count; k++) {
        for (u32 i = 0; i < g_bees[k].count; i++) {
            NestItem *p = &g_bees[k].p[i];
            blit(g_item_sprites[p->item], (i32)(fs * p->x) - cx, (i32)(fs * p->y) - cy, zoom, 0);
        }
    }
    // the dock to the left of the start
    i32 dx = -cx;
    for (int k = 0; k < 6; k++) {
        dx = z16 + dx;
        blit(SPR(0x1400eb6e0), dx, (i32)(g_map.h >> 1) * z16 - cy, zoom, 0);
    }
}

// The building sprite is centred horizontally and bottom-aligned in its footprint
static inline void entity_sprite_pos(const Entity *e, const Sprite *sp, i32 zoom, i32 *x, i32 *y) {
    *y = ((i32)e->h * 16 - sp->h) * zoom + (i32)e->pos.y * g_zoom * 16 - cam_y();
    *x = (((i32)e->w * 16 - sp->w) * zoom) / 2 + (i32)e->pos.x * g_zoom * 16 - cam_x();
}

static b32 entity_working(Entity *e) {
    Recipe *r = e->recipe;
    if (!r) TRAP();
    if (r->n_in == 0) return *ent_in_count(e, 0) != 0 || *ent_in_count(e, 1) != 0;
    for (u32 i = 0; i < r->n_in; i++)
        if (*ent_in_count(e, i) < r->in[i].count) return 0;
    return 1;
}

static const f32 k_dir_vec[5][2] = {{0.0f, 1.40129846e-45f}, {-1.0f, 0.0f}, {1.0f, 0.0f}, {0.0f, -1.0f}, {0.0f, 1.0f}};

// Item travelling along a conveyor
static void draw_conveyor_item(Entity *e, i32 zoom, b32 layer1) {
    u8 *slot;
    u32 outc = *ent_out_count(e);
    if (*ent_in_count(e, 0) > 0) slot = outc ? (u8 *)e + 0x54 : (u8 *)e + 0x3c;
    else if (outc > 0) slot = (u8 *)e + 0x54;
    else return;
    f32 t;
    if (e->recipe) t = e->recipe_time / e->recipe->time;
    else t = 0.0f / 0.0f;
    t = sse_min(1.0f, sse_max(0.0f, t));
    if (outc > 0) t = 0.0f;
    u8 d = e->ports[0].dirs;
    int o = (d & 2) ? 4 : (d & 1) ? 3 : (d & 8) ? 2 : (d & 4) ? 1 : 0;
    int n = (d & 0x20) ? 4 : (d & 0x10) ? 3 : (d & 0x80) ? 2 : (d & 0x40) ? 1 : 0;
    f32 ox = 0.5f * k_dir_vec[o][0] + 0.5f, oy = 0.5f * k_dir_vec[o][1] + 0.5f;
    f32 ix = 0.5f * k_dir_vec[n][0] + 0.5f, iy = 0.5f * k_dir_vec[n][1] + 0.5f;
    f32 px = ((ox - ix) * t + ix) * 16.0f;
    f32 py = ((oy - iy) * t + iy) * 16.0f;
    f32 z = (f32)zoom, h = (f32)(zoom * 8);
    f32 fx = z * px - h, fy = z * py - h;
    i32 sy = (i32)e->pos.y * g_zoom * 16 - cam_y() + (i32)fy;
    i32 sx = (i32)e->pos.x * g_zoom * 16 - cam_x() + (i32)fx;
    if (layer1) blit_channel0(g_item_sprites[slot[0]], sx, sy, zoom, 0);
    else blit(g_item_sprites[slot[0]], sx, sy, zoom, 0);
}

// 0x1400156c0
void draw_entities(i32 zoom, u32 layer) {
    for (u32 k = 0; k < g_entity_list.count; k++) {
        Entity *e = g_entity_list.data[k];
        if (!e || !e->sprite || e->layer != 0) continue;
        i32 x = (i32)e->pos.x * g_zoom * 16 - cam_x();
        i32 y = (i32)e->pos.y * g_zoom * 16 - cam_y();
        i32 z16 = zoom * 16;
        if (e->type == 3) {  // assembler: arrows showing the rotation
            u32 f = (g_anim_tick >> 3) % (u32)SPR(0x1400eaca0)->frames;
            const Sprite *s = e->sprite;
            if (s == SPR(0x1400eb220)) {
                blit(SPR(0x1400eaca0), x, y + z16, zoom, f);
                blit(SPR(0x1400eadc0), z16 + x, y + z16, zoom, f);
            } else if (s == SPR(0x1400eb2a0)) {
                blit(SPR(0x1400ead00), x, y, zoom, f);
                blit(SPR(0x1400ead60), x, z16 + y, zoom, f);
            } else if (s == SPR(0x1400eb2e0)) {
                blit(SPR(0x1400ead00), x + zoom * 16, y, zoom, f);
                blit(SPR(0x1400ead60), x + zoom * 16, y + zoom * 16, zoom, f);
            } else if (s == SPR(0x1400eb260)) {
                blit(SPR(0x1400eadc0), z16 + x, y, zoom, f);
                blit(SPR(0x1400eaca0), x, y, zoom, f);
            }
        } else if (e->type == 2) {  // furnace: output arrow
            u32 f = (g_anim_tick >> 3) % (u32)SPR(0x1400eaca0)->frames;
            u8 d = e->ports[0].dirs;
            if (d & 2) blit(SPR(0x1400eaca0), x, y, zoom, f);
            else if (d & 4) blit(SPR(0x1400ead00), x, y, zoom, f);
            else if (d & 1) blit(SPR(0x1400eadc0), x, y, zoom, f);
            else if (d & 8) blit(SPR(0x1400ead60), x, y, zoom, f);
        }
        const Sprite *sp = e->sprite2;
        if (!sp || !entity_working(e)) sp = e->sprite;
        if (sp) entity_sprite_pos(e, sp, zoom, &x, &y);
        else x = y = 0;
        blit(sp, x, y, zoom, *(i32 *)e->inv);
    }
    for (u32 k = 0; k < g_entity_list.count; k++) {
        Entity *e = g_entity_list.data[k];
        if (e && e->layer == 0 && e->type == 1) draw_conveyor_item(e, zoom, 0);
    }
    if (layer != 0) {
        for (u32 k = 0; k < g_entity_list.count; k++) {
            Entity *e = g_entity_list.data[k];
            if (!e || e->layer != layer) continue;
            i32 x = 0, y = 0;
            if (e->sprite) entity_sprite_pos(e, e->sprite, zoom, &x, &y);
            blit_channel0(e->sprite, x, y, zoom, *(i32 *)e->inv);
        }
        for (u32 k = 0; k < g_entity_list.count; k++) {
            Entity *e = g_entity_list.data[k];
            if (e && e->layer == layer && e->type == 1) draw_conveyor_item(e, zoom, 1);
        }
    }
    // shipment counter next to the dock
    const Sprite *dock = SPR(0x1400eb700);
    i32 y = (i32)((g_map.h >> 1) - 1) * g_zoom * 16 - cam_y();
    i32 bx = -cam_x();
    f32 slide = sse_min(g_win_slide, (f32)(u32)dock->w);
    blit(dock, bx - (i32)(slide * (f32)zoom), y, zoom, 0);
    if (g_won) {
        draw_box(bx - dock->w * zoom, y, dock->w * zoom, dock->h * zoom, 0, 0, 0xff000000);
        return;
    }
    draw_number(g_delivered, bx, y + zoom * 24, zoom << 4);
}

// 0x1400150c0
void render_frame(void) {
    f64 now = time_now();
    memset(g_backbuffer, 0, (u64)(g_bb_h * g_bb_w) * 4);
    g_tooltip = NULL;
    g_tooltip_pos = v2i(-1, -1);
    draw_tiles(g_cam, g_zoom);
    draw_entities(g_zoom, g_layer);
    draw_build_preview(g_cam, g_zoom, now);
    i32 zoom = g_zoom;
    if (g_key_down[VK_SPACE])
        for (u32 i = 0; i < g_homes.count; i++) draw_home_range(&g_homes.data[i], g_cam, zoom);
    f32 cx = g_cam.x, cy = g_cam.y;
    for (u32 i = 0; i < g_flock.orders.count; i++) {
        Order *o = &g_flock.orders.data[i];
        if (!o->active) continue;
        i32 z16 = zoom << 4;
        i32 y = (i32)floorf(((f32)(u32)o->a.y * (f32)z16 - cy) + 0.5f);
        i32 x = (i32)floorf(((f32)(u32)o->a.x * (f32)z16 - cx) + 0.5f);
        blend_rect(x, y, z16, z16, 0x48d7d7d7);
    }
    f32 fz = (f32)(zoom << 4);
    for (u32 i = 0; i < g_homes.count; i++) {
        Home *h = &g_homes.data[i];
        const Sprite *sp = h->big ? SPR(0x1400eabc0) : SPR(0x1400eaba0);
        i32 sz = h->big ? 2 : 1;
        i32 sc = (sz * zoom * 16) / sp->w;
        i32 y = (i32)floorf(((f32)h->pos.y * fz - cy) + 0.5f);
        i32 x = (i32)floorf(((f32)h->pos.x * fz - cx) + 0.5f);
        blit(sp, x, y, sc > 1 ? sc : 1, 0);
    }
    draw_home_hud(g_cam, zoom);
    draw_seagulls(g_cam, g_zoom, now);
    draw_hover_info(g_zoom);
    draw_inventory();
    draw_build_menu();
    draw_palette();
    draw_recipe_picker();
    if (g_tooltip) {
        V2i m = platform_mouse_pos();
        i32 px, py;
        if (g_tooltip_pos.x == -1 && g_tooltip_pos.y == -1) {
            g_tooltip_pos = v2i((i32)(f32)m.x + 0x10, (i32)(f32)m.y + 0x10);
        }
        px = g_tooltip_pos.x;
        py = g_tooltip_pos.y;
        Sprite s = {(Image *)g_tooltip, 0, 0, g_tooltip->w, g_tooltip->h, 1, 0};
        i32 ox = MAX((s.w * 2 - g_bb_w) + px, 0);
        i32 oy = MAX((s.h * 2 - g_bb_h) + py, 0);
        i32 dy = MAX(py - oy, 0), dx = MAX(px - ox, 0);
        blit(&s, dx, dy, 2, 0);
    }
    if (g_tutorial_page < 9) {
        Image *img = &g_tutorial[g_tutorial_page];
        Sprite s = {img, 0, 0, img->w, img->h, 1, 0};
        i32 y = MAX(g_bb_h - s.h * 3, 0);
        i32 x = MAX((g_bb_w - s.w * 3) / 2, 0);
        blit(&s, x, y, 3, 0);
    }
    if (g_won && !g_win_dismissed) {
        Sprite s = {&g_win_img, 0, 0, g_win_img.w, g_win_img.h, 1, 0};
        i32 y = MAX(g_bb_h - s.h * 3, 0);
        i32 x = MAX((g_bb_w - s.w * 3) / 2, 0);
        blit(&s, x, y, 3, 0);
    }
    if (g_key_down['C']) {
        Sprite s = {&g_controls_img, 0, 0, g_controls_img.w, g_controls_img.h, 1, 0};
        i32 x = MAX((g_bb_w - s.w * 3) / 2, 0);
        blit(&s, x, 0, 3, 0);
    }
    g_last_time = now;
}
