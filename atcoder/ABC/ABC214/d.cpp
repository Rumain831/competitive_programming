#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<ll, int, int>;

//Tags: UnionFind

struct UnionFind{
  vector<int> par, siz, rank;
  UnionFind(int n) : par(n, -1), siz(n, 1), rank(n, 1) {}  //コンストラクタ
  //根を求めるやつ
  int root(int x){
    if(par[x]==-1) return x;
    else return par[x]=root(par[x]);
  }

  //xを含むグループとyを含むグループとを併合する
  bool unite(int x, int y){
    x=root(x); y=root(y);
    if(x==y) return false;
    if(rank[x]<rank[y]) swap(x, y);
    if(rank[x]==rank[y]) rank[x]++;
    par[y]=x;
    siz[x]+=siz[y];
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
  int n; cin >> n;
  vector<tu> edge;
  for(int i=0; i<n; i++){
    int u, v; ll w; cin >> u >> v >> w; u--, v--;
    edge.emplace_back(w, u, v);
  }
  UnionFind uf(n);
  ll ans=0;
  sort(edge.begin(), edge.end());
  for(auto [w, u, v]:edge){
    ll uu=uf.size(u), vv=uf.size(v);
    ans+=w*uu*vv;
    uf.unite(u, v);
  }
  cout << ans << endl;
  return 0;
}