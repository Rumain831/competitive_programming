#Tags: 貪欲法

n, m, k = map(int, input().split())
d = list(map(int, input().split()))

if n == 1:
    print(0)
    exit()

put, pre, now = 1, 0, 0

for i in range(m-1):
    now += d[i]
    if abs(pre-now)>=k:
        put += 1
        pre = now


print(sum(d) if put >= n else -1)