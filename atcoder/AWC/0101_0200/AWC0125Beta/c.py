#Tags: 整数, 最小公倍数

def gcd(a, b):
  if b==0: return a
  else: return gcd(b, a%b)

n = int(input())
t = list(map(int, input().split()))

lcm = 1

for i in range(1, n):
  g = gcd(t[0], t[i])
  t[i] //= g
  g = gcd(lcm, t[i])
  lcm = lcm//g*t[i]

print(f"{lcm}/1")