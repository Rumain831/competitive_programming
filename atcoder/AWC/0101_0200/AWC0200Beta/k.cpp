#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 最大長方形問題

int main(void){
  ll n, s; cin >> n >> s;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  a.push_back(0); n++;
  vector<P> fence;
  ll ans=1e18;
  for(int i=0; i<n; i++){
    ll x=a[i], nw=0, mi=1e18;
    while(fence.size()){
      auto [y, w]=fence.back();
      if(y<x) break;
      nw+=w;
      mi=min(mi, y);
      if((s+mi-1)/mi<=nw) ans=min(ans, (s+mi-1)/mi);
      fence.pop_back();
    }
    fence.emplace_back(x, nw+1);
  }
  cout << (ans==1e18?-1:ans) << endl;
  return 0; 
}