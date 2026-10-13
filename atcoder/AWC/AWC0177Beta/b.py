#Tags: 条件を満たすものの個数, 文字列

n = int(input())
s = input()
ans = sum(1 for i in range(n) if s[i]==s[max(0, i-1)]==s[min(i+1, n-1)]==".")
print(ans)