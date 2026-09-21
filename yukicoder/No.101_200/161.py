#Tags: 最適化, じゃんけん
#Level: 2

g, c, p = map(int, input().split())
s = input()
og, oc, op = s.count("G"), s.count("C"), s.count("P")
ans = 0
gc, cp, pg = min(g, oc), min(c, op), min(p, og)
ans += 3*(gc+cp+pg)
g, oc = g-gc, oc-gc
c, op = c-cp, op-cp
p, og = p-pg, og-pg
ans += min(g, og)+min(c, oc)+min(p, op)
print(ans)