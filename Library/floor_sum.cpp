#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

ll floor_sum(ll n, ll a, ll b, ll m){
  //S(n, a, b, m)=\sum_{i=0}^{n-1} \floor((ai+b)/m)
  //y=(ax+b)/m の下側にある格子点の個数と解釈できるときも
  //x軸上の点は除く
  //a=pa M + qa b=pb M + qb
  auto floor=[&](ll x, ll y){
    if(x>=0) return x/y;
    else return -(-x+y-1)/y;
  };
  if(n==0) return 0ll;
  if(a==0) return floor(b, m)*n;
  ll pa, pb;
  pa=floor(a, m), a=a-pa*m;
  pb=floor(b, m), b=b-pb*m;
  //not(my<=ai+b) <=> my>ai+b <=> my>=ai+b+1  90度回転
  //mi>=ay+b+1 <=> ay<=mi-b-1
  //t=floor((a(n-1)+b)/m)
  //S(n, a, b, m)=nt-sum_{i=1}^{t}floor((mi-b-1)/a)+1) y軸上の点を除く
  //floor((mi-b-1)/a)+1) = floor((mi+a-b-1)/a)) 
  //sum_{i=1}^{t}floor((mi+a-b-1)/a))=sum_{i=0}^{t-1}floor((mi+m+a-b-1)/a))
  ll ans=n*(n-1)/2*pa+pb*n;
  ll t=floor(a*(n-1)+b, m), r=m+a-b-1;
  ans+=n*t-floor_sum(t, m, r, a);
  return ans;
}

int main(void){
  return 0;
}