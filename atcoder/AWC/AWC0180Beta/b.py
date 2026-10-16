#Tags: 文字列

n, m = map(int, input().split())
s = input()
t = input()
ans = 10**9

for i in range(n):
    if i+m-1 >= n: break
    u = s[i:i+m]
    now = sum(1 for j in range(m) if u[j]!=t[j])
    ans = min(ans, now)

print(ans)