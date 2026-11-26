#Tags: 四則演算

n, m = map(int, input().split())
print(sum(min(m, x//100) for x in list(map(int, input().split()))))