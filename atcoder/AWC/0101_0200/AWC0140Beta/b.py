#Tags: 累積和

n, m = map(int, input().split())
a = list(map(int, input().split()))
s =[0]*(n+1)

for i in range(n):
  s[i+1]=s[i]+a[i]
  
for i in range(m):
  l, r, k = map(int, input().split())
  now = s[r] - s[l-1]
  print("Dangerous" if now >= k else "Safe")