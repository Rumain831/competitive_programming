#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 最適化

struct UnionFind{
  vector<int> par, siz, rank;
  vector<ll> sum;
  UnionFind(int n, vector<ll>& p) : par(n, -1), siz(n, 1), rank(n, 1), sum(n) {
    for(int i=0; i<n; i++) sum[i]=p[i];
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
    sum[x]+=sum[y];
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
  vector<ll> p(n);
  for(auto&x:p) cin >> x;
  UnionFind uf(n, p);
  while(m--){
    int u, v; cin >> u >> v; u--, v--;
    uf.unite(u, v);
  }
  ll mi=1e18, mx=-1;
  for(int i=0; i<n; i++)if(uf.root(i)==i){
    ll sum=uf.sum[i], c=uf.size(i);
    ll l=sum/c, r=l+(sum%c>0);
    mi=min(mi, l), mx=max(mx, r);
  }
  cout << mx-mi << endl;
  return 0; 
}