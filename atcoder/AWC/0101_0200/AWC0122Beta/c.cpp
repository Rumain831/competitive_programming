#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: BFS, 二分探索

int main(void){
  int n, m, q; cin >> n >> m >> q;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); 
  }
  auto BFS=[&](int st){
    queue<P> bfs;
    vector<int> dist(n, 1e9);
    bfs.emplace(0, st);
    while(bfs.size()){
      auto [d, id]=bfs.front(); bfs.pop();
      if(dist[id]!=1e9) continue;
      dist[id]=d;
      for(auto p:to[id]){
        bfs.emplace(d+1, p);
      }
    }
    return *max_element(begin(dist), end(dist));
  };
  vector<int> mx(n);
  for(int i=0; i<n; i++){
    mx[i]=BFS(i);
  }
  sort(begin(mx), end(mx));
  while(q--){
    int k; cin >> k;
    int ans=upper_bound(begin(mx), end(mx), k)-begin(mx);
    cout << ans << '\n';
  }
  return 0; 
}