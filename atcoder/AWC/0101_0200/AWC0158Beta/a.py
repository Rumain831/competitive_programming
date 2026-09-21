#Tags: 四則演算

n, s, c = map(int, input().split())
r = list(map(int, input().split()))
print(max(0, (sum(r)-s)*c))