#Tags: Simulation

n, s, t = map(int, input().split())
w = int(input())
ans = (s<=w<=t)

for _ in range(n-1):
    a = int(input())
    w += a
    ans += (s<=w<=t)

print(ans)