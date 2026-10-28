#Tags: 文字列, Simulation

n = int(input())
a = list(map(int, input().split()))
ans = []
x = 0
for i in range(n):
    if a[i]==0:
        ans.append("x")
        x += 1
    else:
        ans.append("o" if x==0 else "x")
print("".join(ans))