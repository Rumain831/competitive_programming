#Tags: 数え上げ, マンハッタン距離
#Level: 1.5

x, y, d = map(int, input().split())
l, r = max(0, d-y), min(x, d)
print(max(0, r-l+1))