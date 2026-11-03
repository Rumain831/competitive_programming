#Tags: 構築
#Level: 3
#a1=xとおくと、aiはx+整数 or -x+整数 の形に書けるので、
#1<=ai<=10**18からxが取れる範囲が求められる。

n= int(input())
a = [[1, 0]]
p, y = 1, 0
inf = 10**18
l, r = 1, inf

for i in range(n):
    b = int(input())
    nl, nr = 0, 0
    if i%2 == 0:
        #px+y+z=b z=-px+b-y
        p, y = -p, b-y
    else:
        #px+y-z=b z=px+y-b
        p, y = p, y-b
    if p==1: nl, nr = 1-y, inf-y
    else: nl, nr = y-inf, y-1
    a.append([p, y])
    l, r = max(l, nl), min(r, nr)

if l>r:
    print(-1)
    exit()

print(n+1)
for i in range(n+1):
    print(a[i][0]*l+a[i][1]) 