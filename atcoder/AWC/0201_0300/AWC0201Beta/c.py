#Tags: Simulation

n = int(input())
a = list(map(int, input().split()))
for i in range(n-1):
    a[i+1] += max(0, a[i]-1)

print(a[n-1])