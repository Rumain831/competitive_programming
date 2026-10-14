#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;

struct Cow{
  using Pa = pair<ll, ll>;
  struct Edge{
    int from, to;
    ll cost;
    Edge(int f, int t, ll c):from(f), to(t), cost(c){}
  };
  int n;
  vector<vector<Pa>> to;
  ll inf=9e18;
  vector<Edge> e;

  Cow(int n):n(n){
    to.resize(n);
  }

  // 辺 p->q 重み w
  // xq <= xp+w
  // xq-xp <= w 
  void add_leq(int p, int q, ll w){
    to[p].emplace_back(q, w);
    e.emplace_back(p, q, w);
  }
  // 辺 q->p 重み -w
  // xq-xp >= w
  void add_geq(int p, int q, ll w){
    to[q].emplace_back(p, -w);
    e.emplace_back(q, p, -w);
  }
  // l <= xq-xp <=r
  void add_range(int p, int q, ll l, ll r){
    add_leq(p, q, r);
    add_geq(p, q, l);
  }
  // w <= xq-xp <= w
  void add_equal(int p, int q, ll w){
    add_range(p, q, w, w);
  }

  pair<bool, vector<ll>> Bellmanford(int st){
    vector<ll> dist(n, inf);
    dist[st]=0;
    for(int i=0; i<n; i++){
      bool update=false;
      for(auto& p:e){
        if(dist[p.from]==inf) continue;
        ll nd=dist[p.from]+p.cost;
        if(dist[p.to]>nd){
          dist[p.to]=nd;
          update=true;
        }
      }
      if(i==n-1&&update){
        return make_pair(false, dist);
      }
      if(!update) break;
    }
    return make_pair(true, dist);
  };

  //maximize xi-xst
  vector<ll> dij(int st){
    vector<ll> dist(n, inf);
    priority_queue<Pa, vector<Pa>, greater<Pa>> pri;
    pri.emplace(0, st);
    dist[st]=0;
    while(pri.size()){
      auto [d, id]=pri.top(); pri.pop();
      if(dist[id]!=d) continue;
      for(auto [v, cost]:to[id]){
        ll nd=d+cost;
        if(dist[v]>nd){
          dist[v]=nd;
          pri.emplace(nd, v);
        }
      }
    }
    return dist;
  };
};

int main(void){
  return 0;
}