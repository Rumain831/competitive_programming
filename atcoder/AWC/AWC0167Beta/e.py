#Tags: 木

n, m, k = map(int, input().split())
mi = int(10**18)

for _ in range(m):
    u, v, w = map(int, input().split())
    mi = min(mi, w)

print(mi)