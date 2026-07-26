#Tags: 文字列

l, r = map(int, input().split())
s = input()
t = s[l-1:r]
print(s[:l-1]+t[::-1]+s[r:])