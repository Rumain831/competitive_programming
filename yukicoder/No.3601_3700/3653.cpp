#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using tu = tuple<int, int, ll>;

//Tags: ポテンシャル, ダイクストラ法, Johnson法
//Level: 4

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> p(n);
  for(auto&x:p) cin >> x;
  vector<vector<P>> to(n+1);
  vector<tu> edge;
  for(int i=0; i<m; i++){
    int u, v; ll t; cin >> u >> v >> t; u--, v--;
    edge.emplace_back(u, v, t);
    to[u].emplace_back(v, t);
  }
  for(int i=0; i<n; i++){
    edge.emplace_back(n, i, 0);
    to[n].emplace_back(i, 0);
  }
  vector<ll> po(n+1, 1e18);
  po[n]=0;
  for(int i=0; i<n; i++){
    bool update=false;
    for(auto [u, v, w]:edge){
      ll nd=po[u]+w;
      if(po[v]>nd){
        po[v]=nd;
        update=true;
      }
    }
    if(!update) break;
  }
  vector dist(n+1, vector<ll>(n+1, 1e18));
  auto dij=[&](int st){
    priority_queue<P, vector<P>, greater<P>> pri;
    pri.emplace(0, st);
    dist[st][st]=0;
    while(pri.size()){
      auto [d, id]=pri.top(); pri.pop();
      if(dist[st][id]!=d) continue;
      for(auto [v, w]:to[id]){
        ll nd=d+w+po[id]-po[v];
        if(dist[st][v]>nd){
          dist[st][v]=nd;
          pri.emplace(nd, v);
        }
      }
    }
  };
  for(int i=0; i<=n; i++) dij(i);
  ll mi=1e18, ans=0;
  for(int i=0; i<n; i++)for(int j=0; j<n; j++)if(i!=j){
    if(dist[i][j]==1e18) continue;
    ll now=dist[i][j]-po[i]+po[j]+p[i]+p[j];
    if(mi>=now){
      if(mi>now) ans=1;
      else ans++;
      mi=now;
    }
  }
  if(mi==1e18) cout << -1 << endl;
  else cout << mi << ' ' << ans << endl;
  return 0; 
}