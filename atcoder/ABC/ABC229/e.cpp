#include<iostream>
#include<vector>
using namespace std;

//Tags: UnionFind

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

};

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<int>> to(n+1);
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b; a--, b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector<int> ans(n);
  int now=0;
  UnionFind uf(n);
  for(int i=n; i>=1; i--){
    for(auto p:to[i]){
      if(p>i){
        if(uf.root(p)!=uf.root(i)){
          uf.unite(p, i);
          now--;
        }
      }
    }
    ans[i-1]=now;
    now++;
  }
  for(auto p:ans) cout << p << endl;
  return 0;
}