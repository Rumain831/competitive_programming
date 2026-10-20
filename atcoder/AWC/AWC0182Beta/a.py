#Tags: 条件分岐

n = int(input())

for _ in range(n):
    a, b = map(int, input().split())
    print("Balanced" if a == b else "Left" if a>b else "Right")