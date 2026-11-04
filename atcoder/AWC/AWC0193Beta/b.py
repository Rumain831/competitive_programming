#Tags: 愚直

n = int(input())
a = list(map(int, input().split()))
mx, ans = -1, 0

for i in range(n):
    now = a[i]
    if mx < now:
        mx = now
        ans = i+1

print(ans)