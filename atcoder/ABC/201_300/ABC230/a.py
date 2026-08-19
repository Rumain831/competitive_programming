#Tags: 条件分岐, 文字列

n = int(input())
if n<=41:
    if n<10: print("AGC00"+str(n))
    else: print("AGC0"+str(n))
else: print("AGC0"+str(n+1))