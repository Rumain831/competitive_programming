#Tags: 条件分岐

n = int(input())
s = []
for _ in range(n):
    a, b = map(int, input().split())
    s.append("E" if a == b else "H" if a > b else "L")

print(s)