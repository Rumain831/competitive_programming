#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: グラフ, BFS

int main(void){
  int n, m, p; cin >> n >> m >> p;
  int s, g; cin >> s >> g; s--, g--;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); swap(u, v);
    to[u].push_back(v);
  }
  auto BFS=[&](int st){
    int inf=1e9+10;
    vector dist(n, vector<int>(2, inf));
    dist[st][0]=0;
    queue<P> bfs;
    bfs.emplace(0, st);
    while(bfs.size()){
      auto [d, id]=bfs.front(); bfs.pop();
      if(dist[id][d%2]!=d) continue;
      for(auto v:to[id]){
        int nd=d+1;
        if(dist[v][nd%2]>nd){
          dist[v][nd%2]=nd;
          bfs.emplace(nd, v);
        }
      }
    }
    return dist;
  };
  auto d1=BFS(s);
  auto d2=BFS(g);
  vector<int> ans;
  for(int i=0; i<n; i++){
    bool ok=false;
    int mi=1e9;
    for(int p1=0; p1<2; p1++)for(int p2=0; p2<2; p2++){
      int d=d1[i][p1]+d2[i][p2];
      mi=min(mi, d);
      int pa=d%2;
      if(pa!=(p%2)) continue;
      if(d>p) continue;
      ok=true;
    }
    if(ok) ans.push_back(i+1);
  }
  sort(begin(ans), end(ans));
  if(ans.empty()) cout << -1 << endl;
  else{
    cout << ans.size() << endl;
    for(auto p:ans) cout << p << '\n';
  }
  return 0; 
}