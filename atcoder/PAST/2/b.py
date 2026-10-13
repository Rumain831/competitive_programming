#Tags: 文字列

s = input()
t = "abc"
cnt = [[s.count(t[i]), t[i]] for i in range(3)]
cnt.sort()
print(cnt[-1][1])