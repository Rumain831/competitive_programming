#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<ll, int, int>;

//Tags: 最小全域木

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
  ll n, m, k; cin >> n >> m >> k;
  vector<tu> edge;
  UnionFind uf(n);
  while(m--){
    int u, v; ll c; cin >> u >> v >> c; u--, v--;
    edge.emplace_back(c, u, v);
  }
  sort(begin(edge), end(edge));
  ll ans=0, mx=-1;
  for(auto [c, u, v]:edge){
    if(uf.same(u, v)) continue;
    ans+=c, mx=max(mx, c);
    uf.unite(u, v);
  }
  cout << ans+k*mx << endl;
  return 0; 
}