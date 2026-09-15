#Tags: Simulation

n, m = map(int, input().split())
a = list(map(int, input().split()))

for _ in range(m):
  b, c = map(int, input().split())
  b -= 1
  if a[b] >= c:
    a[b] -= c
    
print(*a)