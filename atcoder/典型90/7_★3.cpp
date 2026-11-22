#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 二分探索
//解説URL: https://twitter.com/e869120/status/1379565222541680644

int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  a.push_back(-1e9-10);
  a.push_back(2e9+10);
  sort(begin(a), end(a));
  int q; cin >> q;
  while(q--){
    int b; cin >> b;
    auto it=lower_bound(begin(a), end(a), b);
    ll ans=1e18;
    ans=min(ans, abs((*it)-b)); it--;
    ans=min(ans, abs((*it)-b));
    cout << ans << '\n';
  } 
  return 0;
}