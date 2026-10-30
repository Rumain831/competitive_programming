#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: ダイクストラ法, 貪欲法

int main(void){
  ll n, m, t; cin >> n >> m >> t;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector to(2, vector<vector<P>>(n));
  for(int i=0; i<m; i++){
    int a, b, c; cin >> a >> b >> c; a--, b--;
    to[0][a].emplace_back(b, c);
    to[1][b].emplace_back(a, c);
  }
  auto dij=[&](int type){
    vector<ll> dist(n, 1e18);
    dist[0]=0;
    priority_queue<P, vector<P>, greater<P>> pri;
    pri.emplace(0, 0);
    while(pri.size()){
      auto [d, id]=pri.top(); pri.pop();
      if(dist[id]!=d) continue;
      for(auto [v, w]:to[type][id]){
        ll nd=d+w;
        if(dist[v]>nd){
          dist[v]=nd;
          pri.emplace(nd, v);
        }
      }
    }
    return dist;
  };
  auto d1=dij(0);
  auto d2=dij(1);
  ll ans=0;
  for(int i=0; i<n; i++){
    ll need=d1[i]+d2[i];
    if(need>t) continue;
    ll rem=t-need;
    ans=max(ans, rem*a[i]);
  }
  cout << ans << endl;
  return 0; 
}