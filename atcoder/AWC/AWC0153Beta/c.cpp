#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: imos法

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<ll> a(n), imos(n+1);
  for(auto&x:a) cin >> x;
  while(m--){
    int l, r; cin >> l >> r;
    imos[l-1]++, imos[r]--;
  }
  for(int i=0; i<n; i++) imos[i+1]+=imos[i];
  int ans=0;
  for(int i=0; i<n; i++){
    ll now=a[i]+imos[i];
    ans+=(now>=k);
  }
  cout << ans << endl;
  return 0; 
}