#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Tags: UnionFind
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
  int n, q; cin >> n >> q;
  UnionFind uf(n);
  set<int> rs;
  for(int i=0; i<n; i++) rs.insert(i);
  while(q--){
    int t; cin >> t;
    if(t==1){
      int u, v; cin >> u >> v; u--, v--;
      rs.erase(uf.root(u));
      rs.erase(uf.root(v));
      uf.unite(u, v);
      rs.insert(uf.root(u));
    }
    else{
      int v; cin >> v; v--;
      v=uf.root(v);
      if(rs.size()==1){
        cout << -1 << '\n'; continue;
      }
      int x=*begin(rs), y=*rbegin(rs);
      cout << (x==v?y+1:x+1) << '\n';
    }
  }
  return 0;
}