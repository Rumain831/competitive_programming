#Tags: dp, bitset高速化
#Level: 2.5

def solve():
    n, s = map(int, input().split())
    a = list(map(int, input().split()))
    f = (1<<(s+1))-1
    dp = 1
    for i in range(n):
        dp |= (dp<<a[i])
        dp &= f
    print(dp.bit_length()-1)


t = int(input())
for _ in range(t):
    solve()