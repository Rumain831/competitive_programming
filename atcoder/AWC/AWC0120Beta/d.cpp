#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: ダイクストラ法

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<ll> h(n);
  for(auto&x:h) cin >> x;
  vector<vector<P>> to(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    ll d=abs(h[u]-h[v]);
    if(d>k) continue;
    to[u].emplace_back(v, d); swap(u, v);
    to[u].emplace_back(v, d);
  }
  vector<ll> dist(n, 1e18);
  priority_queue<P, vector<P>, greater<P>> pri;
  pri.emplace(0, 0);
  dist[0]=0;
  while(pri.size()){
    auto [d, id]=pri.top(); pri.pop();
    if(dist[id]!=d) continue;
    for(auto [v, cost]:to[id]){
      ll nd=d+cost;
      if(dist[v]>nd){
        dist[v]=nd;
        pri.emplace(nd, v);
      }
    }
  }
  cout << (dist[n-1]==1e18?-1:dist[n-1]) << endl;
  return 0; 
}