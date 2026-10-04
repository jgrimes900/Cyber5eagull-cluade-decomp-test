import sys,struct
def load(p):
    d=open(p,'rb').read(); w,h=struct.unpack_from('<ii',d); return w,h,d[8:]
a=load(sys.argv[1]); b=load(sys.argv[2])
if a[:2]!=b[:2]: print('size',a[:2],b[:2]); sys.exit()
w,h=a[:2]; n=0; box=[w,h,-1,-1]; first=None
for i in range(w*h):
    if a[2][i*4:i*4+3]!=b[2][i*4:i*4+3]:
        n+=1; x,y=i%w,i//w
        box=[min(box[0],x),min(box[1],y),max(box[2],x),max(box[3],y)]
        if first is None: first=(x,y,a[2][i*4:i*4+4].hex(),b[2][i*4:i*4+4].hex())
print(sys.argv[1].split('/')[-1], 'diff pixels',n,'bbox',box if n else '', first)
