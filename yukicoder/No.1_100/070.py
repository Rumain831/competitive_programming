#Tags: 時間
#Level: 1

n = int(input())
ans = 0

for _ in range(n):
    s, t = input().split()
    h1, m1 = map(int, s.split(':'))
    h2, m2 = map(int, t.split(':'))
    dh = h2 - h1
    dm = m2 - m1
    if dm < 0:
        dh -= 1
        dm += 60
    if dh < 0:
        dh += 24
    ans += dh*60+dm

print(ans)