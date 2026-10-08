#Tags: 貪欲法

n, m, k = map(int, input().split())
w = list(map(int, input().split()))
r = list(map(int, input().split()))
w.sort()
print("Yes" if sum(w[-k:])>=sum(r) else "No")