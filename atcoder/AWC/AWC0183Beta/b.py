#Tags: grid, 文字列

h, w = map(int, input().split())

for i in range(h):
    s = input()
    if s.count('X'):
        print(i+1)
        exit()

print(-1)