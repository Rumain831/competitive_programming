#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main(void){
  ll n, m, y; cin >> n >> m >> y;
  vector<vector<P>> to(n+1);
  for(int i=0; i<m; i++){
    int u, v; ll w; cin >> u >> v >> w; u--, v--;
    to[u].emplace_back(v, w); swap(u, v);
    to[u].emplace_back(v, w);
  }
  vector<ll> X(n);
  for(auto&x:X) cin >> x;
  for(int i=0; i<n; i++){
    to[i].emplace_back(n, X[i]);
    to[n].emplace_back(i, X[i]+y);
  }
  priority_queue<P, vector<P>, greater<P>> pri;
  pri.emplace(0, 0);
  vector<ll> dist(n+1, 1e18);
  dist[0]=0;
  while(pri.size()){
    auto [d, id]=pri.top(); pri.pop();
    if(dist[id]!=d) continue;
    for(auto [v, w]:to[id]){
      ll nd=d+w;
      if(dist[v]>nd){
        dist[v]=nd;
        pri.emplace(nd, v);
      }
    }
  }
  for(int i=1; i<n; i++) cout << dist[i] << ' ';
  return 0; 
}