#include<iostream>
using namespace std;
using ll = long long;

//Tags: 最短距離
//Level: 1.5

ll n;
ll f(ll u, ll v){
  return (v>=u?v-u:n+v-u);
}
int main(void){
  ll q, s, t, c; cin >> n >> q >> s >> t >> c;
  while(q--){
    int u, v; cin >> u >> v;
    ll d1=f(u, v);
    ll d2=f(u, s)+c+f(t, v);
    cout << min(d1, d2) << '\n';
  }
  return 0; 
}