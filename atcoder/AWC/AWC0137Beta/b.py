#Tags: Simulation, 差分

n, q = map(int, input().split())
a = list(map(int, input().split()))
ans = sum(a)

for _ in range(q):
    x, y = map(int, input().split())
    x -= 1
    ans -= a[x]
    a[x] = y
    ans += a[x]
    print(ans)