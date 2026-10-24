#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 場合分け, 最短距離

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> l(n+2, 2e9), r(n+2, 2e9);
  vector<ll> ml(n+2, 2e9), mr(n+2, 2e9);
  for(int i=2; i<=n; i++) cin >> l[i];
  for(int i=1; i<n; i++) cin >> r[i];
  for(int i=0; i<n+1; i++) mr[i+1]=min(r[i+1], mr[i]);
  for(int i=n+1; i>=1; i--) ml[i-1]=min(l[i-1], ml[i]);
  while(q--){
    int s, t; cin >> s >> t;
    ll ans;
    if(s<t) ans=min(r[s], l[s]+mr[s-1]);
    else ans=min(l[s], r[s]+ml[s+1]); 
    cout << ans << '\n';
  }
  return 0; 
}