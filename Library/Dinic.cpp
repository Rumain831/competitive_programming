#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;

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
  vector<pair<int, Edge>> pos; //元の辺
  Dinic(int n): n(n), graph(n), level(n), iter(n) {} 
  void addEdge(int u, int v, ll cap){
    int x=graph[v].size()+(u==v);
    pos.emplace_back(u, Edge(v, cap, x));
    graph[u].emplace_back(v, cap, x);
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
    if(st==to) return 0ll;
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

  //復元用 (始点, 終点, 流量)
  vector<tuple<int, int, ll>> reconst(){
    vector<tuple<int, int, ll>> ans;
    for(auto&[u, e]:pos){
      ll f=graph[e.to][e.rev].cap;
      ans.emplace_back(u, e.to, f);
    }
    return ans;
  };
};

int main(void){
  return 0;
}