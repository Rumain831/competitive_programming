#Tags: 条件を満たすものの個数

n = int(input())
s = input()

print(sum(1 if s[i-1]==s[i] else 0 for i in range(1, n)))