#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 累積和

int main(void){
  ll n, q, t; cin >> n >> q >> t;
  vector<ll> sum(n+1);
  for(int i=0; i<n; i++){
    ll a; cin >> a;
    sum[i+1]=sum[i]+a;
  }
  while(q--){
    int l, r; cin >> l >> r;
    ll now=sum[r]-sum[l-1];
    cout << (now>t?"Yes":"No") << '\n';
  }
  return 0; 
}