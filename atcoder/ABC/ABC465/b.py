x, y, l, r, a, b = map(int, input().split())
ans = 0

for i in range(a, b):
  if l<=i<r: ans+=x
  else: ans+=y
  
print(ans)