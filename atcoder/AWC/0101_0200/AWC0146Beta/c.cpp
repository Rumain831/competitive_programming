#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: imos法

int main(void){
  ll n, m, k; cin >> n >> m >> k;
  vector<ll> L(n), imos(n+1);
  for(auto&x:L) cin >> x;
  while(m--){
    int l, r; ll z; cin >> l >> r >> z;
    imos[l-1]+=z, imos[r]-=z;
  }
  for(int i=0; i<n; i++) imos[i+1]+=imos[i];
  int ans=0;
  for(int i=0; i<n; i++){
    ll now=L[i]+imos[i];
    ans+=(now>=k);
  }
  cout << ans << endl;
  return 0; 
}