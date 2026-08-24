#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: 貪欲法
//Level: 1.5

int main(void){
  P p[4];
  for(auto&[_, x]:p) cin >> x;
  for(auto&[x, _]:p) cin >> x;
  ll t; cin >> t;
  sort(p, p+4);
  ll ans=0;
  for(int i=0; i<4; i++){
    auto [dt, c]=p[i];
    if(dt*c<=t){
      ans+=c, t-=dt*c;
    }
    else{
      ans+=t/dt; break;
    }
  }
  cout << ans << endl; 
  return 0; 
}