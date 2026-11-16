#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 累積和

int main(void){
  ll n, c; cin >> n >> c;
  vector<ll> a(n);
  for(auto&x:a) cin >> x, x-=c;
  ll ans=0, now=0, mi=0;
  for(int i=0; i<n; i++){
    now+=a[i];
    ans=max(ans, now-mi);
    mi=min(mi, now);
  }
  cout << ans << endl;
  return 0; 
}