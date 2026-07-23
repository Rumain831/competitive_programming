#include<iostream>
using namespace std;
using ll = long long;

//Tags: Simulation

int main(void){
  ll n, m, a; cin >> n >> m >> a;
  int ans=0;
  for(int i=0; i<n; i++){
    ll h; cin >> h;
    if(h<=a) continue;
    if(h>m){
      cout << -1 << endl; return 0;
    }
    ans++, m/=2;
  }
  cout << ans << endl;
  return 0; 
}