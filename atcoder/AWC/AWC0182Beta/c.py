#Tags: 貪欲法

n, k = map(int, input().split())
snack = []

for _ in range(n):
    a, b = map(int, input().split())
    snack.append([b, a])

snack.sort(reverse=True)

cnt, ans = 0, 0

for b, a in snack:
    if cnt+a<=k:
        cnt += a
        ans += b*a
    else:
        rem = k-cnt
        cnt += rem
        ans += b*rem
        break
print(-1 if cnt!=k else ans)