#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 最大公約数, UnionFind

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
  int n, k; cin >> n >> k;
  vector<ll> w(n), rt(1e6+1, -1);
  UnionFind uf(n);
  for(int i=0; i<n; i++){
    cin >> w[i];
    if(w[i]<k) continue;
    if(rt[w[i]]==-1) rt[w[i]]=i;
    else uf.unite(rt[w[i]], i);
  }
  for(int i=k; i<=1e6; i++){
    int now=i, p=-1;
    while(now<=1e6){
      if(rt[now]!=-1){
        if(p==-1) p=rt[now];
        else uf.unite(p, rt[now]);
      }
      now+=i;
    }
  }
  vector<vector<int>> R(n);
  ll mx=0;
  for(int i=0; i<n; i++) R[uf.root(i)].push_back(i);
  for(int i=0; i<n; i++){
    ll now=0;
    for(auto p:R[i]){
      now+=w[p];
    }
    mx=max(mx, now);
  }
  cout << mx << endl;
  return 0; 
}