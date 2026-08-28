#include<iostream>
#include<vector>
using namespace std;

//Tags: functional graph

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
  UnionFind uf(n);
  for(int i=0; i<n; i++){
    int t; cin >> t; t--;
    uf.unite(i, t);
  }
  int ans=0;
  for(int i=0; i<n; i++)if(uf.root(i)==i) ans+=uf.size(i)-1;
  cout << ans << endl;
  return 0; 
}