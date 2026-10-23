#Tags: 文字列, 場合分け
#Level: 1

h, n = map(int, input().split())
a = [h]
last = ["th", "st", "nd", "rd", "th"]
for _ in range(n-1): a.append(int(input()))
a.sort(reverse=True)

for i, x in enumerate(a):
    if x == h:
        print(str(i+1)+last[min((i+1)%10, 4)])
        exit()