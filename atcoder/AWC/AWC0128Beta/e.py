#Tags: xor, 考察で瞬殺

n, k = map(int, input().split())
v = list(map(int, input().split()))
print(sum(v)-max(v))