#Tags: 条件分岐

n, x, y = map(int, input().split())
ans = []

for _ in range(n):
    a, b = map(int, input().split())
    ans.append('G' if a>=x and b<=y else 'B')

print(''.join(ans))