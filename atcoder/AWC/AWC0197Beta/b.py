#Tags: 愚直

n, k = map(int, input().split())
a = list(map(int, input().split()))
for i in range(n):
    if a[-i-1]>=k:
        print(n-i)
        exit()

print(-1)