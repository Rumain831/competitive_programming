#Tags: 条件分岐

y, n = map(int, input().split())
a = list(map(int, input().split()))

suma = sum(a)

print("red" if suma > y else y-suma)