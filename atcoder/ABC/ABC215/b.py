n = int(input())
two, ans = 1, 0

while two*2 <= n:
  two*=2
  ans+=1
  
print(ans)