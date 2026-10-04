import re, struct
d = open("CyberSeagull5.exe","rb").read()
# .rdata va 0x21000 raw 0x20200 ; .data va 0x29000 raw 0x27c00 size 0x800
def rd(va, n):
    if 0x21000 <= va < 0x21000+0x78bc: o = va-0x21000+0x20200
    elif 0x29000 <= va < 0x29800: o = va-0x29000+0x27c00
    else: return None
    return d[o:o+n]
src = open("decomp.c").read()
addrs = sorted(set(int(a,16) for a in re.findall(r"DAT_14002([0-4][0-9a-f]{3})\b", src)))
for a in addrs:
    va = 0x20000 + a
    b = rd(va, 8)
    if b is None: continue
    f = struct.unpack("<f", b[:4])[0]; dd = struct.unpack("<d", b)[0]; i = struct.unpack("<I", b[:4])[0]
    print("%05x f=%-14.8g i=0x%08x d=%g" % (va, f, i, dd))
