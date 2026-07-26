#Tags: 整数, n進数

k = int(input())
s = format(k, 'b')
for x in s:
  print("0" if x == "0" else "2", end='')