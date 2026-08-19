#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: Simulation, UnionFind

struct UnionFind{
  vector<int> par, siz, rank, maxi;
  UnionFind(int n) : par(n, -1), siz(n, 1), rank(n, 1), maxi(n) {
    for(int i=0; i<n; i++) maxi[i]=i;
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
    maxi[x]=max(maxi[x], maxi[y]);
    return true;
  }

  int size(int x){
    return siz[root(x)];
  }

  bool same(int u, int v){
    return root(u)==root(v);
  }

  int last(int u){
    return maxi[root(u)];
  }

};


int main(void){
  int n=(1<<20), m=2*n, q; cin >> q;
  vector<ll> a(m, -1);
  UnionFind uf(m);
  auto f=[&](ll x){
    return uf.last(x%n);
  };
  auto con=[&](int x){
    if(x&&a[x]!=-1) uf.unite(x, x-1);
    if(x+1<m&&a[x+1]!=-1) uf.unite(x, x+1);
    return;
  };
  while(q--){
    int t; ll x; cin >> t >> x;
    if(t==1){
      int p, q;
      if(a[x%n]==-1){
        a[x%n]=a[x%n+n]=x;
        p=x%n, q=p+n;
      }
      else{
        p=f(x%n); p%=n; p++, p%=n; q=p+n;
        a[p]=a[p+n]=x;
      }
      con(p);
      con(q);
    }
    else{
      cout << a[x%n] << '\n';
    }
  }
  return 0;
}
