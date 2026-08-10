#Tags: 実装, 小数の扱い

n = int(input())
ans = 0

for _ in range(n):
    a = input()
    if a.count("."):
        s, t = a.split(".")
        ns = int(s)
        ns *= int(1e10)
        while len(t)<10:
            t = t+"0"
        nt = int(t)
        if s[0] == "-":
            ns = -abs(ns)
            nt = -abs(nt)
        ans += ns+nt
    else:
        b = int(a)
        ans += b*int(1e10)

if ans == 0:
    print("0.0000000000")
    exit()
    
pre = abs(ans)//int(1e10)
if ans < 0:
    pre = "-" + str(pre)
if ans >= 0: ans += int(10**25)
else: ans -= int(10**25)
p = str(ans)
print(pre, ".", p[-10:], sep="")
