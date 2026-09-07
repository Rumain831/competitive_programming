#include<iostream>
using namespace std;
using ll = long long;

//Tags: 数え上げ, AND
//Level: 1.5
//-2は(0, n), (n, 0)除去を意味する

int main(void){
  ll n; cin >> n;
  ll ans=1;
  while(n){
    ll x=n&1;
    if(x) ans*=2;
    n/=2;
  }
  cout << ans-2 << endl;
  return 0; 
}