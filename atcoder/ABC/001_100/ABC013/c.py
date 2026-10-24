#Tags: 最適化, 全探索
#食事をする回数を全部試している。
#普通の食事onlyで切り抜けられるときに限り、最大何回まで質素な食事に変えられるかを計算し、食費を計算、minを取っている。

n, h = map(int, input().split())
a, b, c, d, e = map(int, input().split())
h -= 1
ans = int(10**18)

for eat in range(n+1):
    rem = n-eat
    hp = h+b*eat
    if hp < rem*e: continue
    x = hp-rem*e
    minus = min(eat, x//(b-d))
    ans = min(ans, (eat-minus)*a+minus*c)

print(ans)