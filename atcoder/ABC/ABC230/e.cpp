#include<iostream>
using namespace std;
using ll = long long;

//Tags: 整数, floor

int main(void){
  ll n; cin >> n;
  // n/i=x -> x<=n/i<x+1 n/(x+1)<i<=n/x
  ll ans=0, last;
  for(ll x=1; x*x<=n; x++) ans+=(n/x-n/(x+1))*x, last=x;
  last++;
  for(ll i=n/last; i>=1; i--) ans+=n/i;
  cout << ans << endl;
  return 0;
}