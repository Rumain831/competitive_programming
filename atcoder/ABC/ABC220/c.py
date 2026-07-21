#Tags: 数列

n = int(input())
a = list(map(int, input().split()))
x = int(input())

sm = sum(a)

roop = x//sm
x -= sm*roop
now = 0

for i in range(n):
  now += a[i]
  if x < now:
    print(roop*n+i+1)
    exit()