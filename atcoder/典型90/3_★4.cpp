#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int, int>;

//Tags: 木の直径
//解説URL: https://twitter.com/e869120/status/1377752658149175299

int main(void){
  int n; cin >> n;
  vector<vector<int>> to(n);
  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b; a--, b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  auto BFS=[&](int st){
    vector<int> dist(n, 1e9);
    queue<P> bfs;
    bfs.emplace(0, st);
    dist[st]=0;
    while(bfs.size()){
      auto [d, id]=bfs.front(); bfs.pop();
      if(dist[id]!=d) continue;
      for(auto p:to[id]){
        int nd=dist[id]+1;
        if(dist[p]>nd){
          dist[p]=nd;
          bfs.emplace(nd, p);
        }
      }
    }
    return dist;
  };
  auto d1=BFS(0);
  int idx, maxi=0;
  for(int i=0; i<n; i++)if(d1[i]>maxi) maxi=d1[i], idx=i;
  auto d2=BFS(idx);
  for(int i=0; i<n; i++) maxi=max(d2[i], maxi);
  cout << maxi+1 << endl;
  return 0;
}