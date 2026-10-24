#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: ダイクストラ法, 01BFS, 最短距離

int main(void){
  int n, m, s, t; cin >> n >> m >> s >> t; s--, t--;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b; a--, b--;
    to[a].push_back(b);
  }
  for(int i=0; i<n; i++) sort(begin(to[i]), end(to[i]));
  vector<int> dist(n, 1e9);
  deque<P> bfs;
  bfs.emplace_back(0, s);
  dist[s]=0;
  while(bfs.size()){
    auto [d, id]=bfs.front(); bfs.pop_front();
    if(dist[id]!=d) continue;
    int p=to[id].size();
    for(int i=0; i<p; i++){
      int nd=d+(i==0?0:1), v=to[id][i];
      if(dist[v]>nd){
        dist[v]=nd;
        if(i==0) bfs.emplace_front(nd, v);
        else bfs.emplace_back(nd, v);
      }
    }
  }
  cout << (dist[t]==1e9?-1:dist[t]) << endl;
  return 0; 
}