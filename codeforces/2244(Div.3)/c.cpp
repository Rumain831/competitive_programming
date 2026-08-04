#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: UnionFind, ソート
//https://codeforces.com/contest/2244/problem/C

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

void solve(){
  int n, x, y; cin >> n >> x >> y;
  vector<int> p(n), q(n), r(n);
  for(int i=0; i<n; i++) cin >> p[i], p[i]--, r[i]=i;
  UnionFind uf(n);
  for(int i=0; i<n; i++){
    if(i+x<n) uf.unite(i, i+x);
    if(i+y<n) uf.unite(i, i+y);
  }
  vector<vector<int>> index(n), val(n);
  for(int i=0; i<n; i++){
    int x=uf.root(i);
    index[x].push_back(i);
    val[x].push_back(p[i]);
  }
  for(int i=0; i<n; i++){
    sort(begin(val[i]), end(val[i]));
    int m=val[i].size();
    for(int j=0; j<m; j++) q[index[i][j]]=val[i][j];
  }
  cout << (q==r?"YES":"NO") << endl;
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}