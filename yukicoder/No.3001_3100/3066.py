#Tags: 最適化
#Level: 1.5

n = int(input())
c = list(map(int, input().split()))
c.append(0)
print(2*(max(c)-min(c)))