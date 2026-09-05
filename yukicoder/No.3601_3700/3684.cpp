#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 累積和
//Level: 1.5

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> a(n), b(n), p(n), sum(n+1);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  for(int i=0; i<n; i++){
    ll x=max(0ll, a[i]-b[i]);
    sum[i+1]=sum[i]+x;
  }
  ll ans=0;
  for(int i=0; i<n-m+1; i++) ans=max(ans, sum[i+m]-sum[i]);
  cout << ans << endl;
  return 0; 
}