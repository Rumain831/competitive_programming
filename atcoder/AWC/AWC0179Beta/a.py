#Tags: 条件分岐

n, x = map(int, input().split())
a = list(map(int, input().split()))
print(''.join("o" if y<=x else "x" for y in a))