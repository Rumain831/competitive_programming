#Tags: 条件分岐

n, k = map(int, input().split())
ans = []

for _ in range(n):
    a, b = map(int, input().split())
    ans.append('L' if abs(a-b)>=k else 'S')

print(''.join(ans))