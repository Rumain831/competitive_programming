#Tags: 配列

n = int(input())
a = list(map(int, input().split()))
print(sum(x%2 for x in a))