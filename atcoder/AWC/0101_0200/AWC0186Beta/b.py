#Tags: 四則演算

a, b, c = map(int, input().split())
print(max(0, (c-a+b-1)//b))