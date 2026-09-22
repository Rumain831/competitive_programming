#Tags: Simulation

n, m = map(int, input().split())
s = list(map(int, input().split()))
for _ in range(m):
    t, p = map(int, input().split())
    t -= 1
    if s[t] >= p: s[t] -= p

print(sum(x == 0 for x in s))