#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 尺取り法

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> w(n);
  ll tar=1e18;
  for(auto&x:w) cin >> x;
  while(m--){
    ll c; cin >> c;
    tar=min(tar, c);
  }
  ll ans=0, r=0, now=0;
  for(int i=0; i<n; i++){
    if(r<i) r=i, now=0;
    while(r<n){
      if(now+w[r]<=tar) now+=w[r], r++;
      else break;
    }
    ans+=r-i;
    if(i<r) now-=w[i];
  }
  cout << ans << endl;
  return 0; 
}