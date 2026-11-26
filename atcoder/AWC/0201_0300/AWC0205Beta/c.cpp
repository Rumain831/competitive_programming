#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 累積和

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> a(n), sum(n+1);
  for(int i=0; i<n; i++) cin >> a[i], sum[i+1]=sum[i]+a[i];
  while(q--){
    ll l, r, t; cin >> l >> r >> t;
    cout << (sum[r]-sum[l-1])*t << '\n';
  }
  return 0; 
}