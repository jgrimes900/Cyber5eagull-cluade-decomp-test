import re, struct
d = open("CyberSeagull5.exe","rb").read()
def rd(va, n):
    if 0x21000 <= va < 0x21000+0x78bc: o = va-0x21000+0x20200; return d[o:o+n]
    return None
src = open("decomp.c").read()
doubles = {0x24f78,0x24f90,0x24fa0,0x24fb0,0x24fd0}
def fmt(v):
    s = repr(float(v))
    return s
def sub(m):
    va = int(m.group(1),16) - 0x140000000
    if not (0x24ec8 <= va < 0x2501c): return m.group(0)
    b = rd(va, 8)
    if va in doubles: return "(%s)" % fmt(struct.unpack("<d", b)[0])
    f = struct.unpack("<f", b[:4])[0]
    return "(%sf)" % ("%.9g" % f)
out = re.sub(r"\bDAT_(1400[0-9a-f]{5})\b", sub, src)
open("decomp_ann.c","w").write(out)
for va in range(0x25000, 0x25040, 4):
    print(hex(va), struct.unpack("<f", rd(va,4))[0], rd(va,4).hex())
