#pragma once
#include "base.h"
// Decode a PNG file into malloc'd RGBA bytes (see png.c for format quirks).
u8 *png_decode(const u8 *data, u64 size, u32 *w, u32 *h);
