#Tags: ソート

a, b, c = map(int, input().split())
cnt = [[a, -1], [b, -2], [c, -3]]
cnt.sort(reverse=True)
print(-cnt[0][1])