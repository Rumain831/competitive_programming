#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: BFS

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<P>> to(n);
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b; a--, b--;
    to[a].emplace_back(b, i);
  }
  vector<int> dist(n, 1e9);
  vector<P> pre(n, P(-1, -1));

  auto BFS=[&](int ng){
    queue<P> bfs;
    vector<int> count(n, 1e9);
    bfs.emplace(0, 0);
    count[0]=0;
    while(bfs.size()){
      auto [idx, cnt]=bfs.front(); bfs.pop();
      if(count[idx]!=cnt) continue;
      for(auto [nxt, ei]:to[idx]){
        if(ei==ng) continue;
        if(count[nxt]>cnt+1){
          bfs.emplace(nxt, cnt+1);
          count[nxt]=cnt+1;
          pre[nxt]=P(ei, idx);
        }
      }
    }
    return count;
  };

  dist=BFS(-1);
  set<int> usedei;
  int now=n-1;
  while(pre[now]!=P(-1, -1)){
    auto [ei, pi]=pre[now];
    usedei.insert(ei);
    now=pi;
  }
  int ans0=dist[n-1];
  for(int i=0; i<m; i++){
    if(usedei.count(i)){
      dist=BFS(i);
      cout << (dist[n-1]==1e9?-1:dist[n-1]) << endl;
    }
    else{
      cout << (ans0==1e9?-1:ans0) << endl;
    }
  }
  return 0;
}