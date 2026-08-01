#Tags: 二分探索, 等差数列

def F(n, a, b, c):
    left, right = 0, int(1e16)
    while right - left > 1:
        mid = (left+right)//2
        up = mid//b
        a0 = a
        an = a0 + (up-1)*c
        full = (a0+an)*b*up//2
        full += (an+c)*(mid%b)
        if full >= n: right = mid
        else: left = mid
    return right

n = int(input())
a, b, c = map(int, input().split())
d, e, f = map(int, input().split())
kc = F(n, a, b, c)
ku = F(n, d, e, f)

if kc == ku: print("Same")
else: print("KCPC" if kc < ku else "KUPC")
