#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: ダイクストラ法
//Level: 2.5

int main(void){
  ll n, m, p, y; cin >> n >> m >> p >> y;
  vector<vector<P>> to(n);
  for(int i=0; i<m; i++){
    int u, v; ll w; cin >> u >> v >> w; u--, v--;
    to[u].emplace_back(v, w); swap(u, v);
    to[u].emplace_back(v, w);
  }
  vector<ll> d(p), e(p);
  for(int i=0; i<p; i++) cin >> d[i] >> e[i], d[i]--;
  priority_queue<P, vector<P>, greater<P>> pri;
  pri.emplace(0, 0);
  vector<ll> dist(n, 1e18);
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
  ll ans=0;
  for(int i=0; i<p; i++){
    ll rem=max(0ll, y-dist[d[i]]);
    ans=max(ans, rem/e[i]);
  }
  cout << ans << endl;
  return 0; 
}