#Tags: 愚直

h, w = map(int, input().split())

for _ in range(h):
    s = input()
    no = True
    for j in range(w):
        if s[j]=='o':
            print(j+1)
            no = False
            break
    if no:
        print(-1)