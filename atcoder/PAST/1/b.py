#Tags: 条件分岐

n = int(input())
pre = int(input())

for _ in range(n-1):
    a = int(input())
    if pre == a: print("stay")
    else:
        d = abs(a-pre)
        print("up" if pre < a else "down", d)
    pre = a