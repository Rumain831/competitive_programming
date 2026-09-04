#Tags: 場合の数

n = int(input())
ans = 1

for _ in range(n):
  x = int(input())
  ans *= x
  
print(ans)