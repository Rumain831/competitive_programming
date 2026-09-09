#Tags: 一次方程式
#Level: 1.5

a, b, c, d, e, f = map(int, input().split())
det = a*e-b*d
x = (e*c-b*f)/det
y = (-d*c+a*f)/det

print(f"{x:.10f} {y:.10f}")