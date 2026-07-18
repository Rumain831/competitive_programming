def gcd(a, b):
  if b==0: return a
  else: return gcd(b, a%b)

def digit(n):
  ans = 0
  while n>0:
    ans += 1
    n//=10
  return ans  

mod = 998244353

def solve():
  n, m = map(int, input().split())
  d = digit(n)
  pre, now, ten = 0, 9, 10
  ans = 0
  for i in range(1,d+1):
    num = n-pre if i == d else now-pre
    g = gcd(ten-1, m)
    ans += n//(m//g)*num
    ans %= mod
    pre = now
    now = now*10+9
    ten *= 10
  print(ans%mod) 

t = int(input())

for _ in range(t):
  solve()