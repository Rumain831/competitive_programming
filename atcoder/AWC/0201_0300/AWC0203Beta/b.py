#Tags: grid

h, w = map(int, input().split())
s = [input() for i in range(h)]

for j in range(w):
    print(sum(1 if s[i][j]=='#' else 0 for i in range(h)), end=" ")