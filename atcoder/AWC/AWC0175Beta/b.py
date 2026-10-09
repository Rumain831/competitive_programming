#Tags: 文字列

h, w, k = map(int, input().split())
print("".join(input()[k-1] for i in range(h)))