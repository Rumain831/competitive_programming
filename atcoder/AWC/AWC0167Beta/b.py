#Tags: 木

n = int(input())
a = list(map(int, input().split()))

print("Yes" if a.count(0) or a.count(1)>=2 else "No")