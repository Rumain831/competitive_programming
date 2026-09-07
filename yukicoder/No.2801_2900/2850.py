#Tags: 四則演算
#Level: 1

a, b, c, d = map(int, input().split())
ca = 2000 if a == 0 else c//a
cb = 2000 if b == 0 else d//b
print(min(ca, cb))