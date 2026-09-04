#include<iostream>
#include<vector>
using namespace std;

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
  int n, q; cin >> n >> q;
  UnionFind uf(n);
  while(q--){
    int t; cin >> t;
    if(t==1){
      int a, b; cin >> a >> b; a--, b--;
      uf.unite(a, b);
    }
    else{
      int x; cin >> x; x--;
      cout << uf.size(x) << '\n';
    }
  }
  return 0; 
}