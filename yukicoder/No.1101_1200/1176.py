#Tags: 整数, 全探索
#Level: 2

a = int(input())
ans = a

for n in range(2, 121):
    m, now = 1, n
    while now < a:
        m += 1
        now *= n
    ans = min(ans, n*m)

print(ans)