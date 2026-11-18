#Tags: Simulation

n, k = map(int, input().split())
s = input()
cnt = 0

for i in range(n):
    if s[i] == 'S': cnt += 1
    if cnt == k:
        print(i+1)
        exit()

print(-1)