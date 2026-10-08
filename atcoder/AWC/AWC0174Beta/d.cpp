#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using tu = tuple<int, ll, int>;

//Tags: ダイクストラ法

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<tu>> to(n);
  for(int i=0; i<m; i++){
    int u, v; ll w; cin >> u >> v >> w; u--, v--;
    to[u].emplace_back(v, w, i); swap(u, v);
    to[u].emplace_back(v, w, i);
  }
  int k; cin >> k;
  vector<int> ng(m);
  for(int i=0; i<k; i++){
    int x; cin >> x; ng[x-1]++;
  }
  auto Dij=[&](int t){
    vector<ll> dist(n, 1e18);
    dist[0]=0;
    priority_queue<P, vector<P>, greater<P>> pri;
    pri.emplace(0, 0);
    while(pri.size()){
      auto [d, now]=pri.top(); pri.pop();
      if(dist[now]!=d) continue;
      for(auto [v, w, ei]:to[now]){
        if(t&&ng[ei]) continue;
        ll nd=d+w;
        if(dist[v]>nd){
          dist[v]=nd;
          pri.emplace(nd, v);
        }
      }
    }
    return dist[n-1];
  };
  ll ans1=Dij(0), ans2=Dij(1);
  cout << (ans1==1e18?-1:ans1) << endl;
  cout << (ans2==1e18?-1:ans2) << endl;
  return 0; 
}