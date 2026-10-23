#Tags: 愚直, 累積和
#Level: 2

n = int(input())
Sum = [0, 1]
mod, last = 10**9+7, 1

for i in range(2, n+1):
    an = i*(Sum[0] if i&1 else Sum[1])
    an %= mod
    last = an
    Sum[i&1] += an
    Sum[i&1] %= mod

print(last)