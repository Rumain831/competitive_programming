#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using qu = tuple<int, int, int, int>;

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
  int n, m, q; cin >> n >> m >> q;
  vector<qu> edge;
  for(int i=0; i<m; i++){
    int a, b, c; cin >> a >> b >> c; a--, b--;
    edge.emplace_back(c, -1, a, b);
  }
  for(int i=0; i<q; i++){
    int u, v, w; cin >> u >> v >> w; u--, v--;
    edge.emplace_back(w, i, u, v);
  }
  sort(begin(edge), end(edge));
  vector<bool> ans(q);
  UnionFind uf(n);
  for(auto [w, id, u, v]:edge){
    if(id==-1){
      if(!uf.same(u, v)) uf.unite(u, v);
    }
    else{
      ans[id]=uf.same(u, v);
    }
  }
  for(int i=0; i<q; i++) cout << (ans[i]?"No":"Yes") << '\n';
  return 0;
}