#Tags: 考察で瞬殺

n, p = map(int, input().split())
a = list(map(int, input().split()))
ans = 1

for x in a:
    ans *= x
    ans %= p

print(ans)