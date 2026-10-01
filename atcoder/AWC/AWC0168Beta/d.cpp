#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int, int>;

//Tags: BFS, 最短距離

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); swap(u, v);
    to[u].push_back(v);
  }
  vector<int> ng(n);
  for(int i=0; i<k; i++){
    int b; cin >> b; b--;
    ng[b]=1;
  }
  queue<P> bfs;
  vector<int> dist(n, 1e9);
  dist[n-1]=0;
  bfs.emplace(0, n-1);
  while(bfs.size()){
    auto [d, id]=bfs.front(); bfs.pop();
    if(dist[id]!=d) continue;
    for(auto p:to[id])if(!ng[p]){
      int nd=d+1;
      if(dist[p]>nd){
        dist[p]=nd;
        bfs.emplace(nd, p);
      }
    }
  }
  cout << (dist[0]==1e9?-1:dist[0]) << endl;
  return 0; 
}