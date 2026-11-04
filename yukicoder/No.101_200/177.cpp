#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: フロー, 最大流
//Level: 4

struct Dinic{
  struct Edge{
    int to; //行き先
    ll cap; //容量
    int rev; //逆辺のindex
    Edge(int to, ll cap, int rev):to(to), cap(cap), rev(rev){}
  };
  int n; 
  vector<vector<Edge>> graph;
  vector<int> level, iter;
  Dinic(int n): n(n), graph(n), level(n), iter(n) {} 
  void addEdge(int u, int v, ll cap){
    graph[u].emplace_back(v, cap, graph[v].size());
    graph[v].emplace_back(u, 0, (int)graph[u].size()-1);
  }
  void bfs(int st){
    fill(level.begin(), level.end(), -1);
    queue<int> p;
    p.push(st);
    level[st]=0;
    while(p.size()){
      int idx=p.front(); p.pop();
      for(auto& e:graph[idx]){
        if(e.cap>0&&level[e.to]<0){
          level[e.to]=level[idx]+1;
          p.emplace(e.to);
        }
      }
    }
  }
  ll dfs(int from, int to, ll flow){
    if(from==to) return flow;
    for(int &i=iter[from]; i<graph[from].size(); i++){
      auto& e=graph[from][i];
      if(e.cap>0&&level[e.to]==level[from]+1){
        ll d=dfs(e.to, to, min(flow, e.cap));
        if(d>0){
          e.cap-=d;
          graph[e.to][e.rev].cap+=d;
          return d;
        }
      }
    }
    return 0;
  }
  //O(V^2E) 二部マッチングならO((V+E)sqrt(V))
  ll maxFlow(int st, int to){
    ll flow=0, inf=1e18;
    while(1){
      bfs(st);
      if(level[to]<0) break;
      fill(iter.begin(), iter.end(), 0);
      ll f;
      while(1){
        ll f=dfs(st, to, inf);
        if(f==0) break;
        flow+=f;
      } 
    }
    return flow;
  }
};


int main(void){
  int w, n; cin >> w >> n;
  vector<int> j(n);
  for(auto&x:j) cin >> x;
  int m; cin >> m;
  vector<int> c(m);
  for(auto&x:c) cin >> x;
  vector ng(n, vector<int>(m));
  for(int i=0; i<m; i++){
    int q; cin >> q;
    while(q--){
      int x; cin >> x; x--;
      ng[x][i]=1;
    }
  }
  Dinic din(n+m+2);
  for(int i=0; i<n; i++) din.addEdge(n+m, i, j[i]);
  for(int i=0; i<m; i++) din.addEdge(n+i, n+m+1, c[i]);
  for(int i=0; i<n; i++)for(int j=0; j<m; j++)if(ng[i][j]==0){
    din.addEdge(i, n+j, w);
  }
  int x=din.maxFlow(n+m, n+m+1);
  cout << (x>=w?"SHIROBAKO":"BANSAKUTSUKITA") << endl;
  return 0; 
}