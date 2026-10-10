#Tags: 配列, 実装

n = int(input())
cnt = [[0, 0] for _ in range(n)]

for i in range(n):
    x = int(input())
    x -= 1
    cnt[i][1] = i+1
    cnt[x][0] += 1

cnt.sort()

if cnt[0][0] == 0:
    print(cnt[-1][1], cnt[0][1])
else:
    print("Correct")