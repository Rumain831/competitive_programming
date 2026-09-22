#Tags: grid, クイーン
#Level: 1

n = int(input())
h, w = map(int, input().split())
di, dj = h-1, w-1
print("Yes" if di == 0 or dj == 0 or di == dj else "No")