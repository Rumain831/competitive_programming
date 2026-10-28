#Tags: 条件分岐

n = int(input())
a = list(map(int, input().split()))
mx, ans = -1, 0

for i in range(n-1):
    now = a[i+1]-a[i]
    if mx < now:
        mx, ans = now, i+1

print(ans)