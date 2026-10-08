#Tags: 文字列

h, w = map(int, input().split())
for _ in range(h):
    s = input()
    if s.count("o") == 0:
        print("No")
        exit()

print("Yes")