#Tags: 文字列

h, w = map(int, input().split())
s = []

for i in range(h):
    if input().count('T'): s.append('o')
    else: s.append('x')

print(''.join(s))