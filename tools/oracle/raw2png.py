import sys, struct, zlib
def conv(src, dst):
    d = open(src, "rb").read(); w, h = struct.unpack("<ii", d[:8]); px = d[8:]
    rows = b"".join(b"\0" + bytes(b for i in range(w) for b in (px[(y*w+i)*4+2], px[(y*w+i)*4+1], px[(y*w+i)*4])) for y in range(h))
    def ch(t, x): return struct.pack(">I", len(x)) + t + x + struct.pack(">I", zlib.crc32(t + x) & 0xffffffff)
    open(dst, "wb").write(b"\x89PNG\r\n\x1a\n" + ch(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0)) + ch(b"IDAT", zlib.compress(rows)) + ch(b"IEND", b""))
for a in sys.argv[1:]: conv(a, a.replace(".raw", ".png"))
