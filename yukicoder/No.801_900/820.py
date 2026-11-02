#Tags: 整数
#Level: 1

n, k = map(int, input().split())

if k>n:
    print(0)
    exit()

print((1<<(n-k)))