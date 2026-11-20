#Tags: 文字列

n = int(input())
s = input()

for i in range(n):
    if s[i] == 'z':
        print(i+1)
        exit()

print(-1)