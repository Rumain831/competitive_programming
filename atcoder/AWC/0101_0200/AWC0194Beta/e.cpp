#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<ll, ll, ll>;

//Tags: ダイクストラ法

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<vector<tu>> to(n);
  for(int i=0; i<m; i++){
    int u, v, a, b, s, t;
    cin >> u >> v >> a >> b >> s >> t; u--, v--;
    to[u].emplace_back(v, a*2, s);
    to[u].emplace_back(v, b*2, t);
    to[v].emplace_back(u, a*2, s);
    to[v].emplace_back(u, b*2, t);
  }
  vector dist(n, vector<ll>(k+1, 1e18));
  dist[0][0]=0;
  priority_queue<tu, vector<tu>, greater<tu>> pri;
  pri.emplace(0, 0, 0);
  while(pri.size()){
    auto [d, id, co]=pri.top(); pri.pop();
    if(dist[id][co]!=d) continue;
    for(auto [v, cost, dt]:to[id]){
      ll nd=d+dt, nc=co+cost;
      if(nc<=k&&dist[v][nc]>nd){
        dist[v][nc]=nd;
        pri.emplace(nd, v, nc);
      }
    }
  }
  ll ans=*min_element(begin(dist[n-1]), end(dist[n-1]));
  cout << (ans==1e18?-1:ans) << endl;
  return 0; 
}