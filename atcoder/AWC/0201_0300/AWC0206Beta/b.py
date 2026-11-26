#Tags: grid, 条件を満たすものの個数

h, w = map(int, input().split())
print(sum(input().count(".") for _ in range(h)))