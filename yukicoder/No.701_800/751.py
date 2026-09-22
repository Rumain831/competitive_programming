#Tags: 四則演算, 整数
#Level: 2

def gcd(a, b):
    if b == 0: return a
    else: return gcd(b, a%b)

n1 = int(input())
a = list(map(int, input().split()))
n2 = int(input())
b = list(map(int, input().split()))

bunsi, bumbo = a[0], 1

for i in range(1, n1): bumbo *= a[i]
for i in range(n2):
    if i%2: bunsi *= b[i]
    else: bumbo *= b[i]

g = gcd(abs(bunsi), abs(bumbo))
bunsi //= g
bumbo //= g

if bumbo < 0: 
    bunsi *= -1
    bumbo *= -1

print(bunsi, bumbo)

