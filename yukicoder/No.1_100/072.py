#Tags: 数え上げ, AM-GM
#Level: 2

n = int(input())
a = n//2
b = n-a
mod = int(1e6+7)
print(((a+1)*(b+1)-1+mod)%mod)