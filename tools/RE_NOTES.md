# Cyber5eagull RE notes
## Globals
- 29818 arena "temp" (base,size,used) 1GB ; 29830 arena2 1GB ; 29848/29860 frame arenas (swapped each frame) ; 29878 main arena 64GB reserve. Arena = {u8*base; u64 size; u64 used}
- DynArray {Arena* a (null=>main 29878); T* data; u32 count; u32 cap} grow: cap=max(8,cap*2), if data is last alloc extend in place else realloc+copy.
- 29a88 map w (64), 29a8c map h (64); 299a8 layers (2); 29a90 u8 terrain[w*h]; 29a98 u32 entgrid[layer][h][w]; 29aa0 u8 portgrid[layer][h][w]; 29ac8 bees array 0x40 stride count 299ac
- 2a868/2a870/2a874: entity ptr array (index 0 = null) count/cap ; arena ptr 2a860
- 29aa8..29ac0 xoshiro256++ state (seeded by rdrand)
- 296d0/296d4 backbuffer w/h ; 296c8 pixels ; 29680 hwnd
- 29700[256] key down ; 29801..29805 mouse buttons ; 29808 key callback ; 29810 mouse callback
- 29628 dt (min(frame time, 0.1)); 29620 last time
- 29630/29634 camera x,y ; 29020 = zoom scale (4)
- 29890 tileset image {u32* px; i32 w; i32 h?}; sprites at 1400eaa20.. stride 0x20 {Image* img; i32 x,y,w,h; i32 frames; u32 ?(local_c)}
## Funcs
- 140001000 dynarray_init3(arr, arena, a,b,c)  140001210 log_fmt_uint_str ; 140001400 log_fmt_int ; 1400014b0 push 0x2080 obj
- 1400015f0 read_entire_file(&size, arena, str) ; 140001ca0 str_concat(out, arena, a, b) ; 140001d10 fmt_uint(out, arena, fmt, n) ('%' placeholder, 'x' after % => hex)
- 140001e60 init seagull? (0x2080 struct) ; 140002060/1400021c0 spawn seagull at pos / at landing
- 1400200a0 memcpy 1400200d0 memset 1400200f0 strlen ; 140002010/140002030 fatal(msg) ; 140012ca0 fatal/log
- 140004410 blit_opaque(sprite,x,y,scale,frame); 140004550 blit_alpha; 1400046a0 blit keep low byte; 1400047f0 blit keep &ffff0000
- 140004940 draw_rect_outline(x,y,w,h,thick,color) 140004bc0 draw_rect_filled_outlined(x,y,w,h,thick,border,fill)
- 140004d40 huffman build (png)
- 140003c20 update bees? (0x40 struct: pos u32x2, timer f32 @8, n particles @0xc, particles[n] 16B @0x10)
- 140003fe0 collision check for flying unit vs terrain 7/8 (cliffs?)
- 140004300 craftable count for recipe at 294d0 (inventory 29a28 u32[] count 29a30)
- recipes table 29290 stride 0x30, 12 entries: {u8 id; pad; {u8 item,u32 cnt}x4 @+4 (8B each); u32 n @0x24; u8 out @0x28; u32 outcnt @0x2c}
