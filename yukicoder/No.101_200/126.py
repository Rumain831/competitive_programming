#Tags: 場合分け
#Level: 2

a, b, s = map(int, input().split())

if abs(a-s)<=abs(b-s) or s==1:
    print(abs(a-s)+s)
else:
    ans = int(1000)
    if a: ans=min(ans, abs(b-s)+abs(s-a)+a)
    ans=min(ans, abs(b-s)+abs(s-1)+abs(1-a)+1)
    print(ans)