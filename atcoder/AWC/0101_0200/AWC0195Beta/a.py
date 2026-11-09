#Tags: 四則演算

n = int(input())

for _ in range(n):
    a, b = map(int, input().split())
    print(max(0, a-b))