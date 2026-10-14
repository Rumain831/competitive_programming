#Tags: 貪欲法

n, k, m = map(int, input().split())
D = []
for _ in range(k):
    b, d = map(int, input().split())
    D.append(d)
D.sort(reverse=True)
print(sum(2*D[i] for i in range(0, k, m)))