#Tags: 四則演算

n, m = map(int, input().split())
d = list(map(int, input().split()))
print((sum(d)+m-1)//m)