#Tags: 条件分岐

n = int(input())
a = list(map(int, input().split()))

mx = -1
s = []

for i in range(n):
    if i==0 or mx < a[i]: s.append('o')
    else: s.append('x')
    mx = max(mx, a[i])

print(''.join(s))