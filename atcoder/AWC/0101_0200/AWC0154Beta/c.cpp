#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: imos法

int main(void){
  ll n, k, q; cin >> n >> k >> q;
  vector<ll> c(n), imos(n+1);
  for(auto&x:c) cin >> x;
  while(q--){
    int l, r; cin >> l >> r;
    imos[l-1]+=k, imos[r]-=k;
  }
  for(int i=0; i<n; i++) imos[i+1]+=imos[i];
  for(int i=0; i<n; i++) cout << c[i]+imos[i] << ' ';
  return 0; 
}