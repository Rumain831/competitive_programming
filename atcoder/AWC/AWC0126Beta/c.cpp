#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int, int>;

//Tags: BFS

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int u, v, s; cin >> u >> v >> s; u--, v--;
    if(s==0) continue;
    to[u].push_back(v); swap(u, v);
    to[u].push_back(v);
  }
  queue<P> bfs;
  vector<int> dist(n, 1e9);
  bfs.emplace(0, 0);
  while(bfs.size()){
    auto [d, id]=bfs.front(); bfs.pop();
    if(dist[id]!=1e9) continue;
    dist[id]=d;
    for(auto p:to[id]){
      bfs.emplace(d+1, p);
    }
  }
  cout << (dist[n-1]==1e9?-1:dist[n-1]) << endl;
  return 0; 
}