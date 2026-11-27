#Tags: Simulation

n = int(input())
s = input()
ans = 0

for x in s:
    if x == 'W': ans += 3
    else: ans = max(0, ans-1)

print(ans)