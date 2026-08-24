#Tags: 二分探索
#Level: 3
#答えを x/1e12 としてxを二分探索している

n = int(input())
l = list(map(int, input().split()))
k = int(input())

left, right = 0, int(1e22)

while right-left>1:
    mid = (left+right)//2
    cnt = 0
    for i in range(n):
        cnt+=l[i]*int(1e12)//mid
    if cnt >= k: left = mid
    else: right = mid 

ans = left/1e12
print(f"{ans:.12f}")