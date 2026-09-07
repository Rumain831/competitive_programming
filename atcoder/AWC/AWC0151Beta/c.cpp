#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: imos法

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> a(n), t(n), imos(n+1);
  for(int i=0; i<n; i++) cin >> a[i] >> t[i];
  while(q--){
    int l, r; ll x; cin >> l >> r >> x;
    imos[l-1]+=x, imos[r]-=x;
  }
  for(int i=0; i<n; i++) imos[i+1]+=imos[i];
  int ans=0;
  for(int i=0; i<n; i++){
    if(imos[i]+a[i]>=t[i]) ans++;
  }
  cout << ans << endl;
  return 0; 
}