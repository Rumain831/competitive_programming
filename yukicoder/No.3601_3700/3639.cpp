#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using tu = tuple<int, int, int>;

//Tags: グラフ, クエリ先読み, UnionFind
//Level: 2.5

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
  int n, m; cin >> n >> m;
  vector<tu> edge;
  for(int i=0; i<m; i++){
    int u, v, w; cin >> u >> v >> w; u--, v--;
    edge.emplace_back(w, u, v);
  }
  sort(begin(edge), end(edge));
  int q; cin >> q;
  vector<tu> query;
  for(int i=0; i<q; i++){
    int p, t; cin >> p >> t; t--;
    query.emplace_back(p, t, i);
  } 
  sort(begin(query), end(query));
  int ei=0;
  vector<int> ans(q);
  UnionFind uf(n);
  for(int i=0; i<q; i++){
    auto [e, t, qi]=query[i];
    while(ei<m){
      auto [l, u, v]=edge[ei];
      if(l<=e) uf.unite(u, v);
      else break;
      ei++;
    }
    ans[qi]=uf.size(t);
  }
  for(auto p:ans) cout << p << '\n';
  return 0;
}