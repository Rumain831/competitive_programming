#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 尺取り法

int main(void){
  ll n, c, t, k; cin >> n >> c >> t >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  int l=0, r=-1;
  ll ans=0, now=0;
  while(l<n){
    if(r<l) r=l, now=0;
    while(r<n){
      if(now+c*a[r]<=t) now+=c*a[r], r++;
      else break;
    }
    ll len=r-l;
    ans+=max(0ll, len-k+1);
    if(l<r) now-=c*a[l];
    l++;
  }
  cout << ans << endl;
  return 0; 
}