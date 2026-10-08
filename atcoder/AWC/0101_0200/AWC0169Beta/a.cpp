#include<iostream>
using namespace std;
using ll = long long;

//Tags: Simulation

int main(void){
  ll n, s; cin >> n >> s;
  ll ans=0, now=0;
  while(n--){
    ll x; cin >> x;
    now+=x;
    if(now>=s){
      ans++, now=0;
    }
  }
  cout << ans << endl;
  return 0; 
}