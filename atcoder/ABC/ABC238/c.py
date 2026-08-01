#Tags: 整数, 数え上げ, 桁数

n = int(input())
left, right, mod, ans, rev2 = 1, 9, 998244353, 0, 499122177

while 1:
  cnt = min(right, n)-left+1
  ans += cnt*(1+cnt)%mod*rev2%mod
  ans %= mod
  left *= 10
  right = right*10+9
  if left > n:
    break

print(ans%mod)