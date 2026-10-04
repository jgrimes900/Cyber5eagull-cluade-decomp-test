// Seagull workers: spawning, order assignment, path following and steering.
#include "game.h"

Flock g_flock = {
    .default_home = {{0, 0}, {0.5f, 0.5f}},
    .speed = 10.0f,
};
PathFn g_path_fn;
void *g_path_user;
BlockedFn g_blocked_fn;
void *g_blocked_user;
f64 g_last_pick_sound;  // 0x1400ebb30

static inline f32 u2f(u32 v) { return (f32)v; }
// float -> cell coordinate exactly as the original (floor, 64-bit truncate, keep low 32 bits)
static inline u32 floor_cell(f32 v) { return (u32)(i64)floorf(v); }

// Inline sine approximation the original uses for wobble (x is already shifted by -0.25)
static f32 wave(f32 x) {
    f32 f = x - floorf(x);
    b32 m = 0.5f <= f;
    if (m) f = f - 0.5f;
    f32 p = fmaf(f, -74.4522781f, 93.0653305f);
    p = fmaf(f, p, -5.36622238f);
    p = fmaf(f, p, -19.241663f);
    p = fmaf(f, p, -0.0179444365f);
    p = fmaf(f, p, 1.00010812f);
    return m ? 0.0f - p : p;
}

// 0x140001e60
static Seagull *seagull_init(Seagull *s, V2u home, V2 off, f32 speed) {
    s->vel = v2(0, 0);
    s->home = home;
    s->home_off = off;
    s->speed = speed;
    s->work = 0;
    s->sound_timer = 0;
    s->wobble_time = 0;
    s->state = 0;
    memset(s->order, 0, sizeof s->order);
    *(u32 *)(s->order + 0x1c) = 1;
    s->busy = 0;
    s->carry_item = 0;
    s->carry_count = 0;
    memset(s->path, 0, sizeof s->path);
    s->path_count = s->path_idx = 0;
    s->path_goal = (V2u){0, 0};
    s->pos = v2(u2f(s->home.x) + s->home_off.x, u2f(s->home.y) + s->home_off.y);
    s->has_path = 0;
    u32 x = home.x, y = home.y;
    u32 h = x * 0x2c9277b5u - y * 0x53a9b4fbu + 0x108ef2d9u;
    h = (h >> 16 ^ h) * 0x85ebca77u;
    s->phase = (f32)((h >> 13 ^ h) & 0x3ff) * 0.0009765625f;
    s->rnd1 = (f32)(hash_mix(x * 0x9e3779b9u ^ y * 0x85ebca6bu ^ 0x1234abcd) & 0xffff) * 1.5259022e-05f;
    s->rnd2 = (f32)(hash_mix(x * 0xc2b2ae35u ^ y * 0x27d4eb2fu ^ 0xb5297a4du) & 0xffff) * 1.5259022e-05f;
    return s;
}

static void seagull_push_(Flock *f, V2u home, V2 off, f32 speed, b32 assign) {
    Seagull tmp;
    seagull_init(&tmp, home, off, speed);
    da_reserve_one(&f->gulls, 4);
    memcpy(&f->gulls.data[f->gulls.count++], &tmp, sizeof tmp);
    u32 n = f->gulls.count;
    Seagull *s = &f->gulls.data[n - 1];
    s->phase = (f32)((n * 0xad - 0xad) & 0x3ff) * 0.0009765625f + s->phase;
    s->rnd1 = (f32)(hash_mix(home.x * 0x85ebca6bu ^ home.y * 0xc2b2ae35u ^ n * 0x9e3779b9u) & 0xffff) * 1.5259022e-05f;
    s->rnd2 = (f32)(hash_mix(n * 0x27d4eb2fu ^ home.y * 0xd3a2646cu ^ home.x * 0x165667b1u) & 0xffff) * 1.5259022e-05f;
    if (assign) flock_assign_orders(f);
}

static void seagull_push(Flock *f, V2u home, V2 off) { seagull_push_(f, home, off, f->speed, 1); }

// 0x14000b8c0: reset the flock to `n` seagulls at `start`
void flock_reset(Flock *f, u32 n, V2u start, f32 speed, Arena *arena) {
    if (!arena) arena = &g_arena;
    f->f00 = (u64)(uintptr_t)arena;
    f->gulls.arena = arena;
    f->orders.arena = arena;
    f->events.arena = arena;
    f->gulls.count = 0;
    f->orders.count = 0;
    f->events.count = 0;
    f->default_home.cell = start;
    f->default_home.off = v2(0.5f, 0.5f);
    f->speed = speed;
    for (u32 i = 0; i < n; i++) seagull_push_(f, start, f->default_home.off, f->speed, 0);
}

// 0x140002060
void flock_spawn_at(Flock *f, V2u cell, V2 off) { seagull_push(f, cell, off); }
// 0x1400021c0
void flock_spawn_default(Flock *f) { seagull_push(f, f->default_home.cell, f->default_home.off); }

// 0x140002310: distance from a cell to the first home, times three
f32 home_distance_score(V2u c) {
    if (g_homes.count == 0) TRAP();
    V2u h = g_homes.data[0].pos;
    f32 dy = u2f(c.y) - u2f(h.y);
    f32 dx = u2f(c.x) - u2f(h.x);
    return sqrtf(dx * dx + dy * dy) * 3.0f;
}

// 0x140002380: skip waypoints the seagull has already reached or passed
static void path_advance(Seagull *s, V2 final) {
    u32 n = s->path_count;
    if (n <= 1) return;
    for (;;) {
        u32 idx = s->path_idx, next = idx + 1;
        if (next >= n) return;
        f32 wx, wy;
        if (next + 1 < n) {
            wx = u2f(s->path[next].x) + 0.5f;
            wy = u2f(s->path[next].y) + 0.5f;
        } else {
            wx = final.x;
            wy = final.y;
        }
        f32 px = s->pos.x, py = s->pos.y;
        f32 dx = px - wx, dy = py - wy;
        if (!(0.0063999998f >= dy * dy + dx * dx)) {
            f32 qx, qy;
            if (idx == 0) {
                qx = px;
                qy = py;
            } else {
                qx = u2f(s->path[idx].x) + 0.5f;
                qy = u2f(s->path[idx].y) + 0.5f;
            }
            f32 sy = wy - qy, sx = wx - qx;
            f32 seg2 = sy * sy + sx * sx;
            if (seg2 <= 9.99999975e-05f) return;
            f32 t = ((py - qy) * sy + (px - qx) * sx) / seg2;
            if (t < 0.980000019f) return;
        }
        s->path_idx = next;
    }
}

// 0x140007c90: make sure there is a path to `cell`
static b32 ensure_path(Seagull *s, V2u cell) {
    V2u pc = {floor_cell(s->pos.x), floor_cell(s->pos.y)};
    if (pc.x == cell.x && pc.y == cell.y) {
        s->path[0] = pc;
        s->path_count = 1;
        s->path_idx = 0;
        s->path_goal = cell;
        s->has_path = 1;
        return 1;
    }
    b32 same_goal = s->has_path && s->path_goal.x == cell.x && s->path_goal.y == cell.y;
    b32 on_path = s->path_count != 0 && s->path_idx < s->path_count && s->path[s->path_idx].x == pc.x &&
                  s->path[s->path_idx].y == pc.y;
    if (same_goal && on_path) return 1;
    s->path_count = s->path_idx = 0;
    s->path_goal = (V2u){0, 0};
    s->has_path = 0;
    if (!g_path_fn) return 0;
    u32 n = 0;
    if (!g_path_fn(pc, cell, s->path, &n, 0x400, g_path_user) || n == 0) return 0;
    s->path_count = n;
    s->path_idx = 0;
    s->path_goal = cell;
    s->has_path = 1;
    return 1;
}

// 0x140012bb0: would moving to `p` collide with the world?
static b32 seagull_blocked(Seagull *s, V2 p, V2u cell) {
    (void)cell;
    if (!g_blocked_fn) return 0;
    if (s->state == SG_TO_JOB) return g_blocked_fn(p, s->home, cell, g_blocked_user);
    if (s->state == SG_RETURNING) {
        V2u a;
        if (s->busy) memcpy(&a, s->order + 1, sizeof a);
        else a = s->home;
        return g_blocked_fn(p, a, cell, g_blocked_user);
    }
    V2u here = {floor_cell(s->pos.x), floor_cell(s->pos.y)};
    return g_blocked_fn(p, here, cell, g_blocked_user);
}

static inline void normalize_or_zero(f32 *x, f32 *y) {
    f32 l2 = *y * *y + *x * *x;
    if (9.99999905e-09f >= l2) {
        *x = 0;
        *y = 0;
    } else {
        f32 inv = 1.0f / sqrtf(l2);
        *x = *x * inv;
        *y = *y * inv;
    }
}

// 0x140011140: steer toward `target`, with wobble, speed limits and obstacle avoidance
static void seagull_steer(Seagull *s, V2 target, f32 dt, b32 final_leg) {
    f32 px = s->pos.x, py = s->pos.y;
    f32 dx = target.x - px, dy = target.y - py;
    f32 d2 = dy * dy + dx * dx;
    if (9.99999975e-05f >= d2) {
        s->pos = target;
        s->vel = v2(0, 0);
        return;
    }
    if (0.0f >= dt) {
        s->vel = v2(0, 0);
        return;
    }
    f32 dist = sqrtf(d2);
    f32 inv = 1.0f / dist;
    f32 nx = inv * dx, ny = inv * dy;
    s->wobble_time = dt + s->wobble_time;
    f32 T = s->rnd1 + s->wobble_time;
    f32 a = T * 0.239999995f + s->phase;
    f32 w1 = wave((s->rnd1 * 0.709999979f + a) - 0.25f);
    f32 w2 = wave((a * 1.61000001f + s->rnd2 * 1.37f) - 0.25f);
    f32 w3 = wave((s->rnd2 * 3.1099999f + T * 0.50999999f) - 0.25f);
    f32 w4 = wave((T * 0.930000007f + s->rnd1 * 1.28999996f) - 0.25f);
    f32 mix34 = w3 * 0.699999988f + w4 * 0.300000012f;
    f32 pnx = -ny;  // perpendicular
    f32 c1 = sse_min(1.0f, sse_max(0.0f, dist / 1.20000005f)) * 0.850000024f + 0.150000006f;
    f32 mn = sse_min(0.0500000007f, dist * 0.180000007f);
    f32 amp = (c1 * mn) * (w1 * 0.720000029f + w2 * 0.280000001f);
    f32 dirx = amp * pnx + nx;
    f32 diry = amp * nx + ny;
    normalize_or_zero(&dirx, &diry);
    f32 spd = mix34 * 0.0799999982f + 1.0f;
    if (final_leg && 0.600000024f > dist)
        spd = spd * (sse_min(1.0f, sse_max(0.0f, dist / 0.600000024f)) * 0.300000012f + 0.699999988f);
    f32 vmax = spd * s->speed;
    f32 k = sse_min(1.0f, sse_max(0.0f, dt * 7.0f));
    f32 vx = k * (vmax * dirx - s->vel.x) + s->vel.x;
    f32 vy = k * (vmax * diry - s->vel.y) + s->vel.y;
    s->vel.y = vy;
    s->vel.x = vx;
    f32 lim = s->speed * 1.08000004f;
    if (vy * vy + vx * vx > lim * lim) {
        normalize_or_zero(&vx, &vy);
        vy = vy * lim;
        vx = vx * lim;
        s->vel.y = vy;
        s->vel.x = vx;
    }
    f32 stx = dt * vx, sty = dt * vy;
    px = s->pos.x;
    py = s->pos.y;
    f32 rx = target.x - px, ry = target.y - py;
    f32 dot = ry * sty + rx * stx;
    f32 rem2 = ry * ry + rx * rx;
    if (rem2 < dot) {  // would overshoot: go exactly to the target
        stx = rx;
        sty = ry;
    }
    V2u cell;
    if (s->has_path) cell = s->path_goal;
    else if (s->busy) memcpy(&cell, s->order + 1, sizeof cell);
    else cell = s->home;

    V2 np = v2(px + stx, sty + py);
    if (!seagull_blocked(s, np, cell)) {
        s->pos = np;
        f32 ex = np.x - target.x, ey = np.y - target.y;
        if (9.99999975e-05f < ey * ey + ex * ex) return;
        s->pos = target;
        s->vel.x = 0.550000012f * s->vel.x;
        s->vel.y = 0.550000012f * s->vel.y;
        return;
    }

    f32 slen = sqrtf(sty * sty + stx * stx);
    if (slen > 0.0f) {
        static const f32 scales[4] = {1.0f, 0.649999976f, 0.400000006f, 0.200000003f};
        f32 cand[5][2];
        cand[0][0] = nx;
        cand[0][1] = ny;
        f32 ax = pnx * 0.850000024f, ay = nx * 0.850000024f;
        cand[1][0] = ax + nx;
        cand[1][1] = ay + ny;
        normalize_or_zero(&cand[1][0], &cand[1][1]);
        cand[2][0] = nx - ax;
        cand[2][1] = ny - ay;
        normalize_or_zero(&cand[2][0], &cand[2][1]);
        cand[3][0] = pnx;
        cand[3][1] = nx;
        normalize_or_zero(&cand[3][0], &cand[3][1]);
        cand[4][0] = -pnx;
        cand[4][1] = -nx;
        normalize_or_zero(&cand[4][0], &cand[4][1]);
        for (int i = 0; i < 5; i++) {
            f32 cx = cand[i][0], cy = cand[i][1];
            if (9.99999997e-07f >= cy * cy + cx * cx) continue;
            for (int j = 0; j < 4; j++) {
                f32 sc = slen * scales[j];
                f32 oy = cy * sc, ox = cx * sc;
                if (oy * ry + ox * rx > rem2) {
                    ox = rx;
                    oy = ry;
                }
                V2 q = v2(ox + s->pos.x, oy + s->pos.y);
                if (!seagull_blocked(s, q, cell)) {
                    f32 kk = s->speed * 0.449999988f;
                    s->vel.y = cy * kk;
                    s->vel.x = cx * kk;
                    s->pos = q;
                    return;
                }
            }
        }
    }

    // nudge toward the centre of the current cell
    f32 px2 = s->pos.x, py2 = s->pos.y;
    f32 ccx = u2f(floor_cell(px2)) + 0.5f;
    f32 ccy = u2f(floor_cell(py2)) + 0.5f;
    f32 my = ccy - py2, mx = ccx - px2;
    f32 m2 = my * my + mx * mx;
    if (m2 > 9.99999975e-05f) {
        f32 step = sse_min(sqrtf(m2), dt * s->speed * 0.600000024f);
        f32 ux = mx, uy = my;
        if (9.99999905e-09f >= m2) {
            ux = uy = 0;
        } else {
            f32 iv = 1.0f / sqrtf(m2);
            ux = iv * mx;
            uy = iv * my;
        }
        f32 sx = step * ux, sy = step * uy;
        V2 q = v2(sx + px2, sy + py2);
        if (!seagull_blocked(s, q, cell)) {
            f32 kk = s->speed * 0.25f;
            s->pos = q;
            normalize_or_zero(&sx, &sy);
            s->vel.x = sx * kk;
            s->vel.y = sy * kk;
            goto clear_path;
        }
    }
    s->vel = v2(0, 0);
clear_path:
    s->path_count = s->path_idx = 0;
    s->path_goal = (V2u){0, 0};
    s->has_path = 0;
}

// 0x140011ca0: move toward `target` (inside `cell`); returns 1 on arrival
static b32 seagull_move_to(Seagull *s, V2u cell, V2 target, f32 dt) {
    f32 dx = s->pos.x - target.x, dy = s->pos.y - target.y;
    if (9.99999975e-05f >= dy * dy + dx * dx) {
        s->vel = v2(0, 0);
        s->pos = target;
        return 1;
    }
    if (!ensure_path(s, cell)) {
        s->vel = v2(0, 0);
        return 0;
    }
    path_advance(s, target);
    b32 final_leg = 1;
    V2 wp = target;
    u32 n = s->path_count;
    if (n > 1) {
        u32 i = s->path_idx + 1;
        if (i < n) {
            final_leg = i + 1 >= n;
            if (!final_leg) wp = v2(u2f(s->path[i].x) + 0.5f, u2f(s->path[i].y) + 0.5f);
        }
    }
    seagull_steer(s, wp, dt, final_leg);
    path_advance(s, target);
    dx = s->pos.x - target.x;
    dy = s->pos.y - target.y;
    if (9.99999975e-05f >= dy * dy + dx * dx) {
        s->vel = v2(0, 0);
        s->pos = target;
        return 1;
    }
    return 0;
}

// 0x140011e40: closest home (hive) to a cell, with the landing offset inside it
HomeTarget *nearest_home(HomeTarget *out, V2u cell) {
    if (g_homes.count == 0) {
        *out = g_flock.default_home;
        return out;
    }
    f32 cx = u2f(cell.x) + 0.5f, cy = u2f(cell.y) + 0.5f;
    u32 best = 0;
    f32 bestd = 0;
    for (u32 i = 0; i < g_homes.count; i++) {
        Home *h = &g_homes.data[i];
        u32 sz = h->big ? 2 : 1;
        f32 hx = u2f(sz) * 0.5f + u2f(h->pos.x);
        f32 hy = u2f(sz) * 0.5f + u2f(h->pos.y);
        f32 ex = hx - cx, ey = hy - cy;
        f32 d = ey * ey + ex * ex;
        if (i == 0) bestd = d;
        else if (d < bestd) {
            bestd = d;
            best = i;
        }
    }
    Home *h = &g_homes.data[best];
    u32 sz = h->big ? 2 : 1;
    f32 ox = u2f(sz) * 0.5f, oy = u2f(sz) * 0.5f;
    if (!(sz & 1)) ox = ox + -0.0500000007f;
    if (!(sz & 1)) oy = oy + -0.0500000007f;
    out->cell = h->pos;
    out->off = v2(ox, oy);
    return out;
}

// 0x140008760: the current job is finished
static void seagull_finish_job(Seagull *s, SeagullEvents *ev) {
    ev->job_done = 1;
    s->work = 0;
    s->path_count = s->path_idx = 0;
    s->path_goal = (V2u){0, 0};
    s->has_path = 0;
    Order *o = SG_ORDER(s);
    if (o->f1c != 0) {
        s->state = SG_RETURNING;
        return;
    }
    if (o->repeat != 0) {
        s->state = SG_WORKING;
        return;
    }
    memset(s->order, 0, 0x18);
    o->repeat = 0;
    o->f1c = 1;
    s->state = SG_IDLE;
    s->busy = 0;
    ev->idle = 1;
}

// 0x14001e020: per-seagull state machine
static SeagullEvents *seagull_update(Seagull *s, SeagullEvents *ev, f32 dt) {
    memset(ev, 0, sizeof *ev);
    f32 t = sse_max(dt, 0.0f);
    Order *o = SG_ORDER(s);
    switch (s->state) {
    case SG_IDLE:
        s->vel = v2(0, 0);
        return ev;
    case SG_RETURNING: {
        f32 hy = u2f(s->home.y) + s->home_off.y;
        f32 hx = u2f(s->home.x) + s->home_off.x;
        V2u c = {floor_cell(hx), floor_cell(hy)};
        V2 hp = v2(hx, hy);
        if (!seagull_move_to(s, c, hp, t)) return ev;
        s->vel = v2(0, 0);
        s->pos = hp;
        ev->at_home = 1;
        s->path_count = s->path_idx = 0;
        s->path_goal = (V2u){0, 0};
        s->has_path = 0;
        if (s->busy && o->repeat) {
            play_sound(&g_snd_squawk, 1.0f);
            s->state = SG_TO_JOB;
            return ev;
        }
        memset(s->order, 0, 0x20);
        o->f1c = 1;
        s->state = SG_IDLE;
        s->busy = 0;
        ev->idle = 1;
        return ev;
    }
    case SG_WORKING:
        s->vel = v2(0, 0);
        if (!s->busy) break;
        s->work = t + s->work;
        s->sound_timer = s->sound_timer - t;
        {
            f64 now = time_now();
            if (0.0f >= s->sound_timer && now - 0.1 > g_last_pick_sound) {
                g_last_pick_sound = now;
                play_sound(&g_snd_pickaxe, 0.200000003f);
                u32 r = rdrand32();
                s->sound_timer = ((f32)(r % 10000) / 10000.0f) * 0.25f + 0.5f;
                f32 j = ((f32)(r % 100000) / 100000.0f) * 0.100000001f - 0.0500000007f;
                g_last_pick_sound = (f64)j + g_last_pick_sound;
            }
        }
        if (s->work < o->duration) return ev;
        seagull_finish_job(s, ev);
        return ev;
    case SG_TO_JOB: {
        if (!s->busy) break;
        if (o->kind == 6 && s->carry_count == 0 && o->a.x == o->b.x && o->a.y == o->b.y) {
            HomeTarget ht;
            V2u b = {(u32)o->b.x, (u32)o->b.y};
            nearest_home(&ht, b);
            o->a.x = (i32)ht.cell.x;
            o->a.y = (i32)ht.cell.y;
            s->path_count = s->path_idx = 0;
            s->path_goal = (V2u){0, 0};
            s->has_path = 0;
        }
        V2u a = {(u32)o->a.x, (u32)o->a.y};
        V2 dest = v2(u2f(a.x) + 0.5f, u2f(a.y) + 0.5f);
        if (!seagull_move_to(s, a, dest, t)) return ev;
        s->state = SG_WORKING;
        s->pos = dest;
        s->work = 0;
        s->vel = v2(0, 0);
        ev->at_job = 1;
        ev->at_job2 = 1;
        if (!(0.0f >= o->duration)) return ev;
        seagull_finish_job(s, ev);
        return ev;
    }
    default:
        return ev;
    }
    // busy flag lost while out: go home
    s->state = SG_RETURNING;
    s->path_count = s->path_idx = 0;
    s->path_goal = (V2u){0, 0};
    s->has_path = 0;
    return ev;
}

// 0x140012eb0
void flock_emit_event(Flock *f, u8 type, u32 seagull, const void *order32) {
    da_reserve_one(&f->events, 4);
    FlockEvent *e = &f->events.data[f->events.count++];
    memset(e, 0, sizeof *e);
    *(u32 *)(e->order + 0x1c) = 1;
    e->type = type;
    e->seagull = seagull;
    memcpy(e->order, order32, 0x20);
}

// 0x1400036d0: give unassigned active orders to the closest idle seagull
void flock_assign_orders(Flock *f) {
    for (u32 oi = 0; oi < f->orders.count; oi++) {
        Order *o = &f->orders.data[oi];
        if (o->active == 0 || o->assigned >= 0) continue;
        f32 ox = u2f((u32)o->a.x) + 0.5f, oy = u2f((u32)o->a.y) + 0.5f;
        i32 best = -1;
        f32 bestd = INFINITY;
        for (u32 i = 0; i < f->gulls.count; i++) {
            Seagull *s = &f->gulls.data[i];
            if (s->state != 0 || s->busy != 0) continue;
            f32 dx = s->pos.x - ox, dy = s->pos.y - oy;
            f32 d = dy * dy + dx * dx;
            if (best < 0 || d < bestd) {
                best = (i32)i;
                bestd = d;
            }
        }
        if (best < 0) return;
        HomeTarget ht;
        if (f->home_fn) {
            V2u a = {(u32)o->a.x, (u32)o->a.y};
            ht = *f->home_fn(&ht, a, f->home_user);
        } else {
            ht = f->default_home;
        }
        if ((u32)best >= f->gulls.count) TRAP();
        Seagull *s = &f->gulls.data[best];
        s->home = ht.cell;
        s->path_count = s->path_idx = 0;
        s->path_goal = (V2u){0, 0};
        s->has_path = 0;
        s->home_off = ht.off;
        s->path_count = s->path_idx = 0;
        s->path_goal = (V2u){0, 0};
        s->has_path = 0;
        s->vel = v2(0, 0);
        s->pos = v2(u2f(s->home.x) + s->home_off.x, u2f(s->home.y) + s->home_off.y);
        memcpy(s->order, o, 0x20);
        u8 kind = o->kind;
        s->work = 0;
        s->wobble_time = 0;
        s->path_count = s->path_idx = 0;
        s->busy = kind != 0;
        s->path_goal = (V2u){0, 0};
        s->state = kind != 0;
        s->vel = v2(0, 0);
        s->has_path = 0;
        play_sound(&g_snd_squawk, 1.0f);
        o->assigned = best;
        flock_emit_event(f, 1, (u32)best, o);
    }
}

// 0x14001e600: update every seagull and turn their state changes into events
void flock_update(Flock *f, f32 dt) {
    f->events.count = 0;
    for (u32 i = 0; i < f->gulls.count; i++) {
        i32 oi = -1;
        for (u32 k = 0; k < f->orders.count; k++)
            if ((u32)f->orders.data[k].assigned == i) {
                oi = (i32)k;
                break;
            }
        SeagullEvents ev;
        seagull_update(&f->gulls.data[i], &ev, dt);
        u8 ord[0x20];
        if (oi < 0) {
            memset(ord, 0, sizeof ord);
            *(u32 *)(ord + 0x1c) = 1;
        } else {
            memcpy(ord, &f->orders.data[oi], 0x20);
        }
        if (ev.job_done && oi >= 0) flock_emit_event(f, 3, i, ord);
        if (ev.at_home) flock_emit_event(f, 4, i, ord);
        if (ev.idle && oi >= 0) {
            memcpy(ord, &f->orders.data[oi], 0x20);
            for (u32 k = 0; k < f->orders.count; k++) {
                Order *o = &f->orders.data[k];
                if ((u32)o->assigned == i) {
                    o->assigned = -1;
                    if (o->repeat == 0) {
                        f->orders.count--;
                        for (u32 m = k; m < f->orders.count; m++) f->orders.data[m] = f->orders.data[m + 1];
                    }
                    break;
                }
            }
            flock_emit_event(f, 5, i, ord);
        }
    }
    flock_assign_orders(f);
}
