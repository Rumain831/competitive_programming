#Tags: 貪欲法

n, c = map(int, input().split())
w = list(map(int, input().split()))
w.sort()
ans, sw = 1, 0

for i in range(n-1):
    if sw+w[i] <= c:
        ans += 1
        sw += w[i]
    else: break

print(ans)