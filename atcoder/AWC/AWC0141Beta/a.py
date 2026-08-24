#Tags: 条件分岐

n, k, s, e = map(int, input().split())
ans = 0

for _ in range(n):
    t, h, b = map(int, input().split())
    if s<=t<=e and h>=k:
        ans += b

print(ans)