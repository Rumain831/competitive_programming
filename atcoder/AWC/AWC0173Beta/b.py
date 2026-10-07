#Tags: 文字列

h, w = map(int, input().split())
s = []
for _ in range(h):
    x = input()
    s.append(x)
t = list(zip(*s[::-1]))
print(sum(1 for i in range(w) if t[i].count("#")==0))