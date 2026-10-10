#Tags: 文字列

s = input()

for x in s:
    if "a"<=x<="z":
        print("error")
        exit()

n = int(s)
print(n*2)