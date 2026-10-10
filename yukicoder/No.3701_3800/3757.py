#Tags: 文字列
#Level: 1.5

n = int(input())
s = input()
t = s[:-5]+"HAPPY"
ans = sum(1 for i in range(1, 6) if s[-i]!="HAPPY"[-i])+t.count("HAPPY")-1
print(ans)