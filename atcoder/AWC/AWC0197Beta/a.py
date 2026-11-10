#Tags: 条件分岐

n = int(input())
a = list(map(int, input().split()))
print(''.join('A' if x%2 else 'T' for x in a))