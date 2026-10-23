#Tags: 場合分け
#Level: 1.5

n, m = map(int, input().split())

if m>=n: print(1)
elif n%2: print(-1)
else: print(2 if m>=n//2 else -1)

#print(1 if m>=n else 2 if n%2==0 and m>=n//2 else -1)