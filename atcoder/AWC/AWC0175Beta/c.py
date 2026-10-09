#Tags: 数列, 貪欲法

n = int(input())
h =list(map(int, input().split()))
ans = sum(max(0, min(h[i-1], h[i+1])-h[i]) for i in range(1, n-1))
print(ans)