#Tags: 条件分岐

a, b= map(int, input().split())
if a and b==0:
    print("Gold")
elif b and a==0:
    print("Silver")
else:
    print("Alloy")