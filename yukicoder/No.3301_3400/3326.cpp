#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: ダイクストラ法, BFS
//Level: 2.5

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  priority_queue<P> pri;
  vector<int> ng(n);
  int l; cin >> l;
  for(int i=0; i<l; i++){
    int j, k; cin >> j >> k; j--;
    pri.emplace(k+1, j);
    ng[j]=max(ng[j], k+1);
  }
  while(pri.size()){
    auto [d, id]=pri.top(); pri.pop();
    if(ng[id]>d) continue;
    if(d==1) continue;
    for(auto p:to[id]){
      if(ng[p]<d-1){
        ng[p]=d-1;
        pri.emplace(d-1, p);
      }
    }
  }
  queue<P> bfs;
  vector<int> dist(n, 1e9);
  bfs.emplace(0, 0);
  while(bfs.size()){
    auto [id, d]=bfs.front(); bfs.pop();
    if(dist[id]!=1e9) continue;
    if(ng[id]) continue;
    dist[id]=d;
    for(auto p:to[id]){
      bfs.emplace(p, d+1);
    }
  }
  if(dist[n-1]==1e9) cout << "No" << endl;
  else cout << "Yes" << endl << dist[n-1] << endl;
  return 0;
}