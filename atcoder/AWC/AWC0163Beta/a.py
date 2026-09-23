#Tags: 四則演算

n, m, k = map(int, input().split())
a = list(map(int, input().split()))
print(max(0, sum((x+k-1)//k for x in a)-m))