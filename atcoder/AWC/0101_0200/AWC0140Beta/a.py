#Tags: Simulation

n = int(input())
a = list(map(int, input().split()))
pre, ans = 10**10, 0

for i in range(n):
  if pre < a[i]:
    ans += 2*a[i]
  else:
    ans += a[i]
  pre = a[i]
  
print(ans)