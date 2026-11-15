#Tags: 条件分岐

k = int(input())
a = list(map(int, input().split()))
mi, mx = min(a), max(a)

print(mi if mx==9 else -1)