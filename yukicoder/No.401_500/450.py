#Tags: 算数, 相対速度
#Level: 2

vl, vw = map(int, input().split())
d = int(input())
w = int(input())
ans = d/(vl+vw)*w
print(f"{ans:.10f}")