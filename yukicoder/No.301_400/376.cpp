#include<iostream>
using namespace std;
using ll = long long;

//Tags: 整数, 全探索
//Level: 2.5

int main(void){
  ll n; cin >> n;
  ll mi=1e18, mx=-1;
  for(ll i=1; i*i*i<=n; i++){
    if(n%i) continue;
    for(ll j=i; i*j*j<=n; j++){
      if(n/i%j) continue;
      ll now=i+j+n/i/j-3;
      mi=min(mi, now);
      mx=max(mx, now);
    }
  }
  cout << mi << ' ' << mx << endl;
  return 0; 
}