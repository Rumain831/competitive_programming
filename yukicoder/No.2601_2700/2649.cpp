#include<iostream>
using namespace std;
using ll = long long;

//Tags: 多倍長整数
//Level: 2

void solve(){
  string n; ll m; cin >> n >> m;
  ll r=0; m*=2;
  for(auto p:n){
    int now=p-'0';
    r=(r*10+now)%m;
  }
  ll ans=r*(r+1)%m/2;
  cout << ans << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}