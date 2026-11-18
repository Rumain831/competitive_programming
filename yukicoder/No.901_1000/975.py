#Tags: 条件分岐
#Level: 1

x, n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c1, c2 = a.count(x), b.count(x)

if c1 and c2: print("MrMaxValu")
elif c1: print("MrMax")
elif c2: print("MaxValu")
else: print(-1)