#Tags: 条件分岐
#Level: 1

n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort(reverse=True)
print("Yes" if a[k-1] >= 30 else "No")