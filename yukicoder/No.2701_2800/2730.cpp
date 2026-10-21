#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: bit全探索, 累積和, 貪欲法
//Level: 2.5

int main(void){
  ll n, m, w; cin >> n >> m >> w;
  vector<ll> a(n), b(m), c(m);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  for(auto&x:c) cin >> x;
  sort(rbegin(a), rend(a));
  vector<ll> suma(n+1);
  for(int i=0; i<n; i++) suma[i+1]=suma[i]+a[i];
  ll ans=0, mx=(1<<m);
  for(int i=0; i<mx; i++){
    ll nw=0, v=0;
    for(int j=0; j<m; j++)if(i>>j&1){
      nw+=b[j], v+=c[j];
    }
    if(nw>w) continue;
    ll rem=min(n, w-nw);
    ans=max(ans, v+suma[rem]);
  }
  cout << ans << endl;
  return 0; 
}