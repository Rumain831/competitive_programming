#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: imos法

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> h(m), imos(m+1);
  for(auto&x:h) cin >> x;
  while(n--){
    ll l, r, a; cin >> l >> r >> a;
    imos[l-1]+=a, imos[r]-=a;
  }
  for(int i=0; i<m; i++) imos[i+1]+=imos[i];
  int ans=0;
  for(int i=0; i<m; i++) ans+=(h[i]<=imos[i]);
  cout << ans << endl;
  return 0; 
}