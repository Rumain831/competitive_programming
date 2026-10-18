#Tags: 等差数列, 二分探索

inf = 10**18

def f(a1, d, cnt):
    ans, x = int(a1), int(a1)
    cnt -= 1
    while cnt:
        x += d
        ans *= x
        if ans > inf:
            return int(inf)+10
        cnt -= 1 
    return ans

n = int(input())
ans = 0

for num in range(3, 20):
    i = 1
    while 1:
        if f(i, 1, num) > n: break
        left, right = 1, int(10**9)
        while right - left > 1:
            mid = (left+right)//2
            if f(i, mid, num) > n: right = mid
            else: left = mid
        ans += left
        i += 1

print(ans)