#Tags: 条件分岐
#Level: 1

s = []
for _ in range(3): s.append(input())
print("RED" if s.count("RED")>=2 else "BLUE")