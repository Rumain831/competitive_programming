#Tags: 文字列

h, w = map(int, input().split())
mx, ans = -1, 1

for i in range(h):
    s = input()
    x = s.count(".")
    if mx < x:
        mx = x
        ans = i+1

print(ans)