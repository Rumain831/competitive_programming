#Tags: 愚直

n = int(input())
a = list(map(int, input().split()))
print(min(abs(a[i]-a[i+1]) for i in range(n-1)))