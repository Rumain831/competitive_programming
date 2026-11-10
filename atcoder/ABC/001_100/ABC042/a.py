#Tags: 条件分岐
#5の登場回数が2回, 7の登場回数が1回などで判定しても良い
#もちろん、a=b=5, c=7 etcでif文を書いてもいい

a, b, c = map(int, input().split())
print("YES" if a*b*c==25*7 else "NO")