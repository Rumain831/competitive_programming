#Tags: 幾何
#Level: 1.5
# 半径rの円が長さ2πRにわたって連なっていると考えれば πr^2 * 2πR で体積が求まる。
# ここで、r=(R_out-R_in)/2, R=(R_in+R_out)/2

import math
PI = math.pi

c = int(input())
i, o = map(int, input().split())
r = (o-i)/2
ans = PI*r*r*2*PI*(i+o)/2*c

print(f"{ans:.10f}")