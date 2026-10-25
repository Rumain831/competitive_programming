#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 尺取り法, 二分探索

int main(void){
  int n, m; cin >> n >> m;
  ll x, y; cin >> x >> y;
  vector<ll> a(n), b(m);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  int ans=0, ia=0, ib=0;
  while(ia<n&&ib<m){
    ll t=a[ia]+x;
    while(ib<m&&b[ib]<t) ib++;
    if(ib==m) break;
    t=b[ib]+y;
    while(ia<n&&a[ia]<t) ia++;
    ans++;
  }
  cout << ans << endl;
  return 0;
}