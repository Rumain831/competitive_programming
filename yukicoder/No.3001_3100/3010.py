#Tags: 条件を満たすものの個数
#Level: 1

n, m = map(int, input().split())
ans = 0

for _ in range(n):
    s, r = input().split()
    r = int(r)
    if r >= 1200 and s[:4].count('x'):
        ans += 1

print(ans)