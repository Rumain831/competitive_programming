#Tags: 条件を満たすものの個数
#Level: 1.5

n = int(input())
a = list(map(int, input().split()))
l = sum(a)//n
print(sum(x>=l+100 for x in a))