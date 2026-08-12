#Tags: 条件分岐

s = input()
c = 0

for _ in range(8):
    t = input()
    c += 8-t.count(".")

if c%2 == 0: print(s)
else: print("oda" if s[0] == "y" else "yukiko")