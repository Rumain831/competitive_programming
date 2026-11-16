#Tags: 文字列

n = int(input())
s = input()

for i in range(n):
    if s[-i-1]=='D':
        print(n-i)
        exit()

print(-1)