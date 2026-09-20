#Tags: Simulation
#Level: 1.5

aw, ab = map(int, input().split())
bw, bb = map(int, input().split())
c, d = map(int, input().split())

#print(aw-max(0, c-ab)+min(d, bw+max(0, c-ab)))でも可

if ab < c:
    aw -= c-ab
    bw += c-ab

aw += min(bw, d)
print(aw)