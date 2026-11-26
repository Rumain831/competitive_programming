#Tags: Simulation

n, x = map(int, input().split())

for _ in range(n):
    t, a = input().split()
    b = int(a)
    if t == 'D': x += b
    else:
        if x >= b: x -= b
    print(x)