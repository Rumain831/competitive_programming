#Tags: 四則演算
#Level: 1

n, x = map(int, input().split())
a = list(map(int, input().split()))
print(max(0, sum(a)-x))