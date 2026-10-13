#Tags: 文字列

s, t = input().split()
x = ["B1","B2","B3","B4","B5","B6","B7","B8","B9"][::-1]+["1F","2F","3F","4F","5F","6F","7F","8F","9F"]
print(abs(x.index(s)-x.index(t)))