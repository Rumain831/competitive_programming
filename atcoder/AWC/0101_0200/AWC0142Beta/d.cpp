#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 二分探索, ダイクストラ法

int main(void){
  ll n, m, t; cin >> n >> m >> t;
  vector<ll> p(n);
  for(auto&x:p) cin >> x;
  vector<vector<P>> to(n);
  for(int i=0; i<m; i++){
    int u, v; ll w; cin >> u >> v >> w; u--, v--;
    to[u].emplace_back(v, w); swap(u, v);
    to[u].emplace_back(v, w);
  }
  auto judge=[&](ll tar){
    if(p[0]>tar) return (ll)1e18;
    vector<ll> dist(n, 1e18);
    priority_queue<P, vector<P>, greater<P>> pri;
    pri.emplace(0, 0);
    dist[0]=0;
    while(pri.size()){
      auto [d, id]=pri.top(); pri.pop();
      if(dist[id]!=d) continue;
      for(auto [v, w]:to[id]){
        if(p[v]>tar) continue;
        ll nd=d+w;
        if(dist[v]>nd){
          dist[v]=nd;
          pri.emplace(nd, v);
        }
      }
    }
    return dist[n-1];
  };
  ll left=-1, right=1e9+10;
  while(right-left>1){
    ll mid=(left+right)/2;
    if(judge(mid)<=t) right=mid;
    else left=mid;
  }
  cout << right << endl;
  return 0; 
}