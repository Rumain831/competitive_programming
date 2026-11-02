#Tags: 構築, 整数
#Level: 1.5

n = int(input())
cnt = [1]*n
cnt[0] = 3

while sum(cnt)%3 != 1:
    cnt[-1] += 1

print(*cnt)