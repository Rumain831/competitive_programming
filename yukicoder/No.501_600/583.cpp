#include<iostream>
#include<vector>
using namespace std;

//Tags: 一筆書き
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
  vector<int> deg(n);
  UnionFind uf(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v;
    deg[u]++, deg[v]++;
    uf.unite(u, v);
  }
  int r=-1;
  int odd=0;
  for(int i=0; i<n; i++)if(deg[i]){
    if(r==-1) r=uf.root(i);
    else{
      int x=uf.root(i);
      if(r!=x){
        cout << "NO" << endl; return 0;
      }
    }
    if(deg[i]&1) odd++;
  }
  cout << (odd==0||odd==2?"YES":"NO") << endl;
  return 0; 
}