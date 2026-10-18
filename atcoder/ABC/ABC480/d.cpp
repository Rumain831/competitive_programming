#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 累積和

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> a(n), sum(n+1), len(n+1), block(n+1);
  for(int i=0; i<n; i++){
    cin >> a[i], sum[i+1]=sum[i]+a[i], len[i+1]=len[i]+i+1;
  }
  for(int i=0; i<n; i++) block[i+1]=block[i]+sum[i+1];
  auto f=[&](ll x){
    if(x==0) return 0ll;
    int bi=upper_bound(begin(len), end(len), x)-begin(len); bi--;
    ll base=block[bi];
    ll l=x-len[bi];
    base+=sum[l];
    return base;
  };
  while(q--){
    ll l, r; cin >> l >> r;
    ll ans=f(r)-f(l-1);
    cout << ans << '\n';
  }
  return 0; 
}