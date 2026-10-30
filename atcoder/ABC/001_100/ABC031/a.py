#Tags: 四則演算
#max(a*(d+1), (a+1)*d)でもok

a, d = map(int, input().split())
print(a*d+max(a, d))