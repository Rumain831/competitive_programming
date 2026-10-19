#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: グラフ, BFS, 数え上げ

int main(void){
  int n, m; cin >> n;
  int a, b; cin >> a >> b; a--, b--;
  cin >> m;
  ll mod=1e9+7;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int x, y; cin >> x >> y; x--, y--;
    to[x].push_back(y);
    to[y].push_back(x);
  }
  vector<int> dist(n, 1e9);
  vector<ll> cnt(n);
  dist[a]=0; cnt[a]=1;
  queue<P> bfs;
  bfs.emplace(0, a);
  while(bfs.size()){
    auto [d, id]=bfs.front(); bfs.pop();
    if(dist[id]!=d) continue;
    for(auto p:to[id]){
      int nd=d+1;
      if(dist[p]>=nd){
        cnt[p]+=cnt[id], cnt[p]%=mod;
        if(dist[p]>nd) bfs.emplace(nd, p), dist[p]=nd;
      }
    }
  }
  cout << cnt[b] << endl;
  return 0;
}