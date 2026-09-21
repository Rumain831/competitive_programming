#Tags: 全探索
#Level: 1

a, b, c = map(int, input().split())
ans = []

for i in range(1, 2000001):
    now = i*a
    if now > b: now -= b
    if now == c: ans.append(i)

if len(ans) == 0: print(-1)
else:
    for x in ans: print(x)