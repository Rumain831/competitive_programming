#include<iostream>
using namespace std;
using ll = long long;

//Tags: 約数

int main(void){
  int q; cin >> q;
  while(q--){
    ll n; cin >> n;
    ll ans=1;
    for(ll i=1; i*i<=n; i++)if(n%i==0){
      ans=max(ans, min(i, n/i));
    }
    cout << ans << '\n';
  }
  return 0; 
}