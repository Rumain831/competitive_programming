#Tags: grid

n, m = map(int, input().split())
s = [input() for i in range(n)]

for i in range(n):
    if s[i].count('o')==0:
        print("Faucet", i+1)
        exit()

for j in range(m):
    if sum(1 if s[i][j]=='o' else 0 for i in range(n))==0:
        print("Drain", j+1)
        exit()