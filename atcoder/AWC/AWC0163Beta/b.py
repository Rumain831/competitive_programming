#Tags: Simulation

l, w = map(int, input().split())
ans = 0

while l>w:
    ans += 1
    l = (l+1)//2

print(ans)