#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: Simulation, ダイクストラ法

int main(void){
  int n; cin >> n;
  vector<ll> s(n), t(n);
  for(auto&x:s) cin >> x;
  priority_queue<P, vector<P>, greater<P>> pri;
  for(int i=0; i<n; i++) cin >> t[i], pri.emplace(t[i], i);
  while(pri.size()){
    auto [time, id]=pri.top(); pri.pop();
    if(t[id]!=time) continue;
    int nxt=(id+1)%n; ll nxtt=time+s[id];
    if(t[nxt]>nxtt){
      t[nxt]=nxtt;
      pri.emplace(nxtt, nxt);
    }
  }
  for(auto p:t) cout << p << '\n';
  return 0;
}