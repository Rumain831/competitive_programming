#Tags: 最適化

n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
Sum = sum(a)
tar, r, ans = Sum//n, Sum%n, 0

for i in range(n):
    ans += abs(tar+1-a[i]) if i<r else abs(tar-a[i])

print(ans//2)