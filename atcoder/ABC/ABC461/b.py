n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

for i in range(n):
  if b[a[i]-1]-1!=i:
    print("No")
    exit()
    
print("Yes")