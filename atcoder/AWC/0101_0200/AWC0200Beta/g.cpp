#include<iostream>
#include<vector>
using namespace std;

//Tags: UnionFind

struct UnionFind{
  vector<int> par, siz, rank, mx;
  UnionFind(int n, vector<int>& a) : par(n, -1), siz(n, 1), rank(n, 1), mx(n) {
    for(int i=0; i<n; i++) mx[i]=a[i];
  }  //コンストラクタ
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
    mx[x]=max(mx[x], mx[y]);
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
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  UnionFind uf(n, a);
  while(m--){
    int u, v; cin >> u >> v; u--, v--;
    uf.unite(u, v);
  }
  for(int i=0; i<n; i++){
    cout << uf.mx[uf.root(i)] << '\n';
  }
  return 0; 
}