# Generates deterministic placeholder assets (the real resources/ folder is not in the exe).
import zlib, struct, os, sys, random, math
out = sys.argv[1]
os.makedirs(out + "/resources/textures", exist_ok=True)
os.makedirs(out + "/resources/sounds", exist_ok=True)
def png(path, w, h, seed):
    r = random.Random(seed)
    rows = b""
    for y in range(h):
        row = bytearray([0])
        for x in range(w):
            tx, ty = x // 16, y // 16
            c = (tx * 37 + ty * 91 + seed * 13) & 0xff
            a = 255 if ((x ^ y) & 7) else (0 if (tx + ty) % 3 == 0 else 128)
            row += bytes([(c + x * 3) & 255, (c * 2 + y * 5) & 255, (c * 7 + (x ^ y)) & 255, a])
        rows += bytes(row)
    def chunk(t, d): return struct.pack(">I", len(d)) + t + d + struct.pack(">I", zlib.crc32(t + d) & 0xffffffff)
    data = b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, 6, 0, 0, 0)) + chunk(b"IDAT", zlib.compress(rows)) + chunk(b"IEND", b"")
    open(path, "wb").write(data)
def wav(path, n, freq):
    pcm = b"".join(struct.pack("<hh", int(8000*math.sin(i*freq/44100*6.283)), int(8000*math.sin(i*freq/44100*6.283))) for i in range(n))
    hdr = b"RIFF" + struct.pack("<I", 36 + len(pcm)) + b"WAVE" + b"fmt " + struct.pack("<IHHIIHH", 16, 1, 2, 44100, 44100*4, 4, 16) + b"data" + struct.pack("<I", len(pcm))
    open(path, "wb").write(hdr + pcm)
T = out + "/resources/textures/"
png(T + "tileset.png", 512, 512, 1)
names = "assembler assembler_big bee cam_lens camera chute circuit conveyor copper_ore copper_wire cyber_seagull elevator feather furnace gear hive hive_big honey iron_ore iron_plate landing pollen power_core seagull splitter uranium".split()
for i, n in enumerate(names): png(T + "tooltip_%s.png" % n, 96, 40, 10 + i)
for i in range(9): png(T + "tutorial_%d.png" % i, 200, 100, 50 + i)
png(T + "controls.png", 160, 120, 70)
png(T + "win_message.png", 240, 80, 71)
wav(out + "/resources/sounds/bees.wav", 22050, 220)
wav(out + "/resources/sounds/pickaxe.wav", 8000, 880)
