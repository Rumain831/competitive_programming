#Tags: 四則演算
#Level: 1

a, b, c, d = map(int, input().split())
p, q, r, s, t = map(int, input().split())
print("Yes" if a*p+b*q+c*r+d*s<=t else "No")