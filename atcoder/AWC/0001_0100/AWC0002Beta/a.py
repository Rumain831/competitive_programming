n, k = map(int, input().split())
a = list(map(int, input().split()))

print(a.index(k) + 1 if k in a else -1)