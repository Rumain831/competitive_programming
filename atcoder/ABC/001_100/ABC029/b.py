#Tags: 文字列

ans = 0

for _ in range(12):
    s = input()
    if s.count("r"): ans += 1

print(ans)