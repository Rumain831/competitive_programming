#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 二分探索, 区間スケジューリング, 貪欲法

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  ll left=-1, right=1e18;
  auto judge=[&](ll x){
    if(x<0) return false;
    vector<P> seg;
    for(int i=0; i<n; i++){
      ll d=(a[i]?x/a[i]:n);
      ll l=max(0ll, i-d);
      ll r=min(n-1, i+d);
      seg.emplace_back(r, l);
    }
    sort(begin(seg), end(seg));
    int need=0, id=0;
    while(id<n){
      auto [nr, _]=seg[id];
      need++;
      while(id<n){
        auto [r, l]=seg[id];
        if(l<=nr) id++;
        else break;
      }
    }
    return need<=k; 
  };
  while(right-left>1){
    ll mid=(left+right)/2;
    if(judge(mid)) right=mid;
    else left=mid;
  }
  cout << right << endl;
  return 0; 
}