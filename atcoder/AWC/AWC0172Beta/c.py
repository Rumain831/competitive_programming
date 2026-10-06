#Tags: グラフ

n, m = map(int, input().split())
w = list(map(int, input().split()))
a = [0]*n

for _ in range(n):
    u, v = map(int, input().split())
    u, v = u-1, v-1
    if w[u] > w[v]: 
        u, v = v, u
    if w[u] != w[v]:
        a[u] |= 1

print(sum(a)) 