#Tags: 文字列

h, w = map(int, input().split())
ans = 0

for _ in range(h):
    s = input()
    ans = max(ans, s.count("x"))

print(ans)