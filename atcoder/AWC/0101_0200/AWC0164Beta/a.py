#Tags: 木

n = int(input())
ans = 0

for _ in range(n-1):
    u, v, w = map(int, input().split())
    ans += w

print(ans)