#Tags: 小数の扱い
#Level: 2.5
#AIに聞いたら教えてくれた解答。知らんかった。

from decimal import Decimal

n = int(input())
ans = sum(Decimal(input()) for _ in range(n))

print(f"{ans:.10f}")