#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 尺取り法

int main(void){
  ll n, d; cin >> n >> d;
  vector<ll> x(n), p(n);
  ll sum=0, ans=1e18;
  for(int i=0; i<n; i++) cin >> x[i] >> p[i], sum+=p[i];
  int l=0, r=-1;
  ll now=0;
  while(l<n){
    if(r<l) r=l;
    ll pos=x[l];
    while(r<n){
      if(x[r]<pos+d) now+=p[r++];
      else break;
    }
    ans=min(ans, sum-now);
    now-=p[l++];   
  }
  cout << ans << endl;
  return 0; 
}