#Tags: 条件分岐

n, m, s, t = map(int, input().split())
l, r = min(s, t), max(s, t)
ans = 0

for _ in range(m):
    p, v = map(int, input().split())
    if l <= p <= r: ans += v

print(ans)