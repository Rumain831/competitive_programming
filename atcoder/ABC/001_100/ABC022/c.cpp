#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: グラフ, 最短距離, ダイクストラ法

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<P>> to(n);
  for(int i=0; i<m; i++){
    int u, v; ll w; cin >> u >> v >> w; u--, v--;
    to[u].emplace_back(v, w); swap(u, v);
    to[u].emplace_back(v, w);
  }
  vector dist(n, vector<ll>(n, 1e18));
  for(int i=1; i<n; i++){
    priority_queue<P, vector<P>, greater<P>> pri;
    pri.emplace(0, i);
    dist[i][i]=0;
    while(pri.size()){
      auto [d, id]=pri.top(); pri.pop();
      if(dist[i][id]!=d) continue;
      for(auto [v, w]:to[id])if(v!=0){
        ll nd=d+w;
        if(dist[i][v]>nd){
          dist[i][v]=nd;
          pri.emplace(nd, v);
        }
      }
    }
  }
  ll ans=1e18, p=to[0].size();
  for(int i=0; i<p-1; i++)for(int j=i+1; j<p; j++){
    auto [u, lu]=to[0][i];
    auto [v, lv]=to[0][j];
    ll now=dist[u][v]+lu+lv;
    ans=min(ans, now);
  }
  cout << (ans==1e18?-1:ans) << endl;
  return 0; 
}