#Tags: 幾何
#Level: 1
#辺BCを固定すると、点Aは、BCの垂直二等分線と円との交点のうち、BCから遠い方にあるべき
#このときAB=BCとなる。このABに対して同じ議論をして、CA=CBとなるべきことが分かる。
#よってABCは正三角形。正三角形の外心と重心が一致することなどから、S=3\sqrt(3)r^2/4 が答え

import math
sq3 = math.sqrt(3)

t = int(input())

for _ in range(t):
    r = int(input())
    ans = 3*sq3*r*r/4
    print(f"{ans:.10f}")