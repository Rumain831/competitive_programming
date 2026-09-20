#Tags: 四則演算
#Level: 1.5

n = int(input())
ans, mod = 0, 10**9+7

for _ in range(n):
    c, d = map(int, input().split())
    ans += (c+1)//2*d
    ans %= mod

print(ans)