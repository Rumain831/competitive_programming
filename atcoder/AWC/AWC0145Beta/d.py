#Tags: 場合分け

a, b, c, d = map(int, input().split())

lt, rt = min(a, c), max(a, c)
la, ra = min(b, d), max(b, d)
base = abs(rt-lt)+abs(ra-la)

if max(lt, la) < min(rt, ra):
    sg = (c-a)*(d-b)
    if sg < 0:
        print(base-1)
    elif sg >= 0:
        if lt<=la<=ra<=rt or la<=lt<=rt<=ra:
            print(base+1)
        else:
            print(base)
else:
    print(base)
