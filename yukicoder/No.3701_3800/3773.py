#Tags: 全探索
#Level: 1

n, a, b = map(int, input().split())
ans = 0

for i in range(1, n+1):
    if i%a > i%b: ans += 1

print(ans)