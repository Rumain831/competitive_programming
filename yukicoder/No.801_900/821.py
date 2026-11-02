#Tags: 考察で瞬殺, 等差数列
#Level: 2.5

n, k = map(int, input().split())
print(k*(n+n-k+1)//2+1)