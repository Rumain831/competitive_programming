#include<iostream>
#include<queue>
using namespace std;
using ll = long long;

//Tags: 実装

int main(void){
  ll q, v; cin >> q >> v;
  priority_queue<ll> pri;
  while(q--){
    int T; cin >> T;
    if(T==1){
      ll t, w; cin >> t >> w;
      pri.emplace(w-t);
    }
    else{
      ll t; cin >> t;
      if(pri.empty()) cout << -1 << '\n';
      else{
        cout << min(v, t+pri.top()) << '\n';
        pri.pop();
      }
    }
  }
  return 0; 
}