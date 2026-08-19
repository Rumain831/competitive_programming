n, m, s = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

d = sum(a)-sum(b)

if d >= 0:
  print(-1)
  exit()

print(s//(-d))

