#include<iostream>
#include<vector>
using namespace std;

//Tags: UnionFind, ループ

struct UnionFind{
  vector<int> par, siz, rank;
  UnionFind(int n) : par(n, -1), siz(n, 1), rank(n, 1) {}  //メンバ変数をどのように初期化するかを表す
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
  vector<int> deg(n), a(m), b(m);
  for(int i=0; i<m; i++){
    cin >> a[i] >> b[i]; a[i]--, b[i]--;
    deg[a[i]]++, deg[b[i]]++;
    if(deg[a[i]]>=3||deg[b[i]]>=3){
      cout << "No" << endl; return 0;
    }
  }
  UnionFind uf(n);
  for(int i=0; i<m; i++){
    if(uf.same(a[i], b[i])){
      cout << "No" << endl; return 0;
    }
    uf.unite(a[i], b[i]);
  }
  cout << "Yes" << endl;
  return 0;
}