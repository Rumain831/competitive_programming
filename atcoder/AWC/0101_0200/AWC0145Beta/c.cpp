#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int, int>;

//Tags: BFS

int main(void){
  int n, m, s, k; cin >> n >> m >> s >> k; s--;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); swap(u, v);
    to[u].push_back(v);
  }
  vector<int> dist(n, 1e9);
  queue<P> bfs;
  bfs.emplace(0, s);
  dist[s]=0;
  while(bfs.size()){
    auto [d, id]=bfs.front(); bfs.pop();
    if(dist[id]!=d) continue;
    for(auto p:to[id]){
      int nd=d+1;
      if(dist[p]>nd){
        dist[p]=nd;
        bfs.emplace(nd, p);
      }
    }
  }
  int ans=0;
  for(int i=0; i<n; i++) ans+=(dist[i]<=k);
  cout << ans << endl;
  return 0; 
}