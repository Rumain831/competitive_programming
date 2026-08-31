#Tags: 条件を満たすものの個数
#Level: 1

s = input()
n, ans = len(s), 0

for i in range(n-2):
    if (s[i] == s[i+1] or s[i+1] == s[i+2]) and s[i] != s[i+2]: ans += 1

print(ans)
