#Tags: 累積和

n = int(input())
v = list(map(int, input().split()))
ans, mi, now = int(-10**18), 0, 0

for i in range(n):
    now += v[i]
    ans = max(ans, now-mi)
    mi = min(mi, now)

print(ans)