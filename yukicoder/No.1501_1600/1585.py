#Tags: 整数
#Level: 1.5

n = int(input())
left, right = 0, 1000001
while right-left>1:
    mid = (left+right)//2
    if mid**3 > n: right = mid
    else: left = mid

print("Yes" if left**3 == n else "No")