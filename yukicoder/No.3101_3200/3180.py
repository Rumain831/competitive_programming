#Tags: 幾何
#Level: 2.5

t = int(input())

for _ in range(t):
    ax, ay, bx, by, cx, cy = map(int, input().split())
    # (ax+iay)(bx+iby) = x+iy
    x = ax*bx - ay*by
    y = ay*bx + ax*by
    # x+iy と cx+icy が 平行 かつ 内積が正
    if x*cy == y*cx and x*cx + y*cy > 0:
        print("Yes")
    else:
        print("No")