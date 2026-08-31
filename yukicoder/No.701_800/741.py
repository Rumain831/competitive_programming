#Tags: 数え上げ
#Level: 2

n = int(input())
p, q = 1, 1

for i in range(9):
    p *= n+10-i-1
    q *= i+1

ans = p//q % (10**9+7)
print(ans)