#Tags: 四則演算

x, y = map(int, input().split())
print((y-x+9)//10 if y>x else 0)