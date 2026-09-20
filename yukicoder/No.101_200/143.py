#Tags: 四則演算
#Level: 1

k, n, f = map(int, input().split())
a = list(map(int, input().split()))
s = sum(a)
res = k*n-s
print(res if res>=0 else -1)