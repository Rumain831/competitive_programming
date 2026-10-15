#Tags: 貪欲法

n, k = map(int, input().split())
cat = [0]*(n+1)

for _ in range(n):
    b, d = map(int, input().split())
    cat[b] = max(cat[b], d)

cat.sort(reverse=True)
print(sum(cat[:k]))