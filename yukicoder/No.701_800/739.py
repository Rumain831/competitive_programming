#Tags: 文字列
#Level: 1

s = input()
n = len(s)

if n%2:
    print("NO")
    exit()

print("YES" if s[:n//2] == s[n//2:] else "NO")