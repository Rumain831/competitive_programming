#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 相対
//Level: 2

void solve(){
  int n; cin >> n;
  vector<ll> a(n);
  ll ans=0;
  for(auto&x:a) cin >> x;
  for(int i=0; i<n-1; i++){
    ll d=a[i+1]-a[i];
    ans=max(ans, 1-min(1ll, d));
  }
  cout << ans << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}