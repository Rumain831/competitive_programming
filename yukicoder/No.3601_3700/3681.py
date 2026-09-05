#Tags: 二分探索
#Level: 2

r, p, q = map(int, input().split())
a, b, c, d = map(int, input().split())

left, right = 0, int(2e9)

while right-left>1:
    mid = (left+right)//2
    ch, ok = 0, 0
    ch = max(0, mid-a)+max(0, mid-b)+max(0, mid-c)
    ok = max(0, a-mid)+max(0, b-mid)+max(0, c-mid)+d
    need = ch*q+p*mid
    if need <= r and ch <= ok: left = mid
    else: right = mid

print(left)