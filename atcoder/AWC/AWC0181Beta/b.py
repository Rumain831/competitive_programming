#Tags: 文字列

h, w = map(int, input().split())
ans = 0

for _ in range(h):
    s = input()
    ans += 1 if s.count('x')==0 else 0
print(ans)