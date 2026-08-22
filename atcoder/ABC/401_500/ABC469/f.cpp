#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 最小全域木, 最大公約数

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
  int mx=1e6;
  vector<ll> a(n), idx(mx+1, -1);
  vector<vector<int>> bai(mx+1);
  for(int i=0; i<n; i++){
    cin >> a[i];
    idx[a[i]]=i;
  }
  for(int i=1; i<=mx; i++){
    int now=i;
    while(now<=mx){
      if(idx[now]!=-1){
        bai[i].push_back(idx[now]);
      }
      now+=i;
    }
  }
  UnionFind uf(n);
  ll ans=0;
  for(int i=mx; i>=1; i--){
    if(bai[i].empty()) continue;
    int p=bai[i][0];
    for(auto q:bai[i]){
      if(!uf.same(p, q)){
        uf.unite(p, q); ans+=i;
      }
    }
  }
  cout << ans << endl;
  return 0; 
}