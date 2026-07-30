#Tags: 二分探索

n, m = map(int, input().split())
r = list(map(int, input().split()))

sumr = sum(r)

if m > sumr:
    print(-1)
    exit()

left, right = 0, sumr+1

while right-left>1:
    mid = (left+right)//2
    now = 0
    for i in range(n):
        now += max(0, r[i]-mid)
    if now > m:
        left = mid
    else:
        right = mid

print(right)