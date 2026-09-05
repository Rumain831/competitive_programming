#Tags: 条件分岐
#Level: 1.5

n = int(input())
a = list(map(int, input().split()))
print("No" if sum(a)%n else "Yes")