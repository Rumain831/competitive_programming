#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 等差数列, 余りで分類

int main(void){
  ll n, d, t; cin >> n >> d >> t;
  map<int, vector<int>> mp;
  for(int i=0; i<n; i++){
    ll x; cin >> x;
    ll nx=((x%d)+d)%d;
    mp[nx].push_back(x);
  }
  ll ans=0;
  auto f=[&](ll l, ll r){
    if(r<l) return 0ll;
    return (r-l+d)/d;
  };
  for(auto& [_, vec]:mp){
    sort(begin(vec), end(vec));
    vec.erase(unique(begin(vec), end(vec)), end(vec));
    ll l=-1e18, r=-(ll)1e18-10;
    for(auto p:vec){
      ll nl=p-d*t, nr=p+d*t;
      if(r<nl){
        ans+=f(l, r);
        l=nl, r=nr;
      }
      else r=nr;
    }
    ans+=f(l, r);
  }
  cout << ans << endl;
  return 0; 
}