#Tags: 愚直

n = int(input())
mx, ans = -1, 0

for i in range(n):
    a, b = map(int, input().split())
    now = a*b
    if mx < now:
        mx = now
        ans = i+1

print(ans)