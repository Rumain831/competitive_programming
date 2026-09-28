#include<iostream>
#include<map>
using namespace std;
using ll = long long;

//Tags: 差分更新
//Level: 2

int main(void){
  ll h, w, q; cin >> h >> w >> q;
  ll ans=h*w;
  map<ll, ll> mi;
  while(q--){
    ll y, x; cin >> y >> x;
    if(mi.count(x)){
      ans-=mi[x]-1;
      mi[x]=min(mi[x], y);
    }
    else{
      ans-=h;
      mi[x]=y;
    }
    ans+=mi[x]-1;
    cout << ans << '\n';
  }
  return 0; 
}