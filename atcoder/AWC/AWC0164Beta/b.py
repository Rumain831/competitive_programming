#Tags: 条件を満たすものの個数

n, t = map(int, input().split())
s = list(map(int, input().split()))
ans, mx = 0, -1

for i in range(n):
    if s[i] < mx and mx >= t:
        ans += 1
    mx= max(mx, s[i])

print(ans)