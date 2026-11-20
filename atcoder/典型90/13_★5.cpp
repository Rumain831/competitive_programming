#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int, int>;

//Tags: ダイクストラ法, 最短距離
//解説URL: https://twitter.com/e869120/status/1382101716066127872

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<P>> to(n);
  for(int i=0; i<m; i++){
    int a, b, c; cin >> a >> b >> c; a--, b--;
    to[a].emplace_back(b, c); swap(a, b);
    to[a].emplace_back(b, c);
  }
  auto Dij=[&](int st){
    vector<int> dist(n, 2e9);
    priority_queue<P, vector<P>, greater<P>> pri;
    pri.emplace(0, st);
    dist[st]=0;
    while(pri.size()){
      auto [d, id]=pri.top(); pri.pop();
      if(dist[id]!=d) continue;
      for(auto [v, c]:to[id]){
        int nd=d+c;
        if(dist[v]>nd){
          dist[v]=nd;
          pri.emplace(nd, v);
        }
      }
    }
    return dist;
  };
  auto d1=Dij(0);
  auto d2=Dij(n-1);
  for(int i=0; i<n; i++) cout << d1[i]+d2[i] << '\n';
  return 0; 
}