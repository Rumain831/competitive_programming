#Tags: Simulation

n = int(input())
ans = 0

for _ in range(n):
    d, x = input().split()
    y = int(x)
    if d == "R": ans += y
    else: ans -= y
    print(ans)