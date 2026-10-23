#Tags: 四則演算

n, c = map(int, input().split())
for _ in range(n):
    w, a = map(int, input().split())
    print(max(0, w*a-c))