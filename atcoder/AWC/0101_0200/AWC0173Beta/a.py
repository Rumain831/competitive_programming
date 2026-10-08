#Tags: 条件分岐

n, b = map(int, input().split())
a = list(map(int, input().split()))
print("Yes" if sum(a) <= b else "No")