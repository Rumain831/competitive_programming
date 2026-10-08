#Tags: 愚直

n = int(input())
mx, ans = -1, 0

for i in range(n):
    h, s, d = map(int, input().split())
    if mx < h+s:
        mx = h+s
        ans = i+1

print(ans)