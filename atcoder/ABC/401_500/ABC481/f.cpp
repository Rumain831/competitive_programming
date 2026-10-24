#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: BFS

struct UnionFind{
  vector<int> par, siz, rank;
  vector<set<P>> to;
  UnionFind(int n) : par(n, -1), siz(n, 1), rank(n, 1), to(n) {}  //コンストラクタ
  //根を求めるやつ
  int root(int x){
    if(par[x]==-1) return x;
    else return par[x]=root(par[x]);
  }

  void addEdge(int u, int v, int c){
    to[u].emplace(c, v);
  }

  //xを含むグループとyを含むグループとを併合する
  bool unite(int x, int y){
    x=root(x); y=root(y);
    if(x==y) return false;
    if(rank[x]<rank[y]) swap(x, y);
    if(rank[x]==rank[y]) rank[x]++;
    if(to[x].size()<to[y].size()) swap(to[x], to[y]);
    par[y]=x;
    siz[x]+=siz[y];
    for(auto p:to[y]) to[x].insert(p);
    return true;
  }

  int size(int x){
    return siz[root(x)];
  }

  bool same(int u, int v){
    return root(u)==root(v);
  }

};


int main(void){
  int n, m; cin >> n >> m;
  UnionFind uf(n);
  for(int i=0; i<m; i++){
    int a, b, c; cin >> a >> b >> c; a--, b--;
    uf.addEdge(a, b, c);
  }
  vector<ll> ans(n), put(n);
  queue<P> bfs;
  bfs.emplace(0, 0);
  ll mod=998244353;
  put[0]=1;
  while(bfs.size()){
    queue<P> old;
    swap(old, bfs);
    while(old.size()){
      auto [d, id]=old.front(); old.pop();
      id=uf.root(id);
      int pc=-1, ro;
      for(auto [c, v]:uf.to[id]){
        if(put[v]) continue;
        ll nd=(d*10+c)%mod;
        ans[v]=nd;
        put[v]=1;
        if(pc==c) uf.unite(ro, v);
        else{
          bfs.emplace(nd, v);
          pc=c, ro=v;
        }
      }
    }
  }
  for(int i=1; i<n; i++) cout << ans[i] << '\n';
  return 0; 
}