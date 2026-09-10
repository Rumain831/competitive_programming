#Tags: 四則演算

n, p = map(int, input().split())
ans = 0

for _ in range(n):
    x, v = map(int, input().split())
    if p != x:
        ans += v/abs(p-x)

print(f"{ans:.10f}")