#Tags: 条件を満たすものの個数

n = int(input())
a = list(map(int, input().split()))
ans = 0 

for i in range(1, n-1):
    if a[i-1] == a[i] or a[i] == a[i+1] or a[i-1] == a[i+1]: continue
    if a[i-1] < a[i] < a[i+1] or a[i-1] > a[i] > a[i+1]: continue
    ans += 1

print(ans)