#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: imos法

int main(void){
  ll n, m, t; cin >> n >> m >> t;
  vector<ll> f(n), imos(n+1);
  for(auto&x:f) cin >> x;
  while(m--){
    int l, r; ll d; cin >> l >> r >> d; l--;
    imos[l]+=d, imos[r]-=d;
  }
  for(int i=0; i<n; i++) imos[i+1]+=imos[i];
  ll ans=0;
  for(int i=0; i<n; i++){
    ll now=max(0ll, f[i]-imos[i]);
    ans+=(now<=t);
  }
  cout << ans << endl;
  return 0; 
}