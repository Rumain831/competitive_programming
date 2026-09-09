#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: ダイクストラ法

int main(void){
  int n, m, s; cin >> n >> m >> s; s--;
  vector<vector<P>> to(n);
  for(int i=0; i<m; i++){
    int u, v; ll w; cin >> u >> v >> w; u--, v--;
    to[u].emplace_back(v, w); swap(u, v);
    to[u].emplace_back(v, w);
  }
  vector<ll> dist(n, 1e18);
  priority_queue<P, vector<P>, greater<P>> pri;
  pri.emplace(0, s);
  dist[s]=0;
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
  ll ans=0;
  for(auto&x:dist)if(x!=1e18) ans+=x;
  cout << ans << endl;
  return 0; 
}