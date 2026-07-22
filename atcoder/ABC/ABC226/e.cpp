#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: グラフ, functional graph

struct UnionFind{
  vector<int> par, siz;
  UnionFind(int n) : par(n, -1), siz(n, 1) {}  //メンバ変数をどのように初期化するかを表す
  //根を求めるやつ
  int root(int x){
    if(par[x]==-1) return x;
    else return par[x]=root(par[x]);
  }

  //xを含むグループとyを含むグループとを併合する
  bool unite(int x, int y){
    x=root(x); y=root(y);
    if(x==y) return false;
    if(siz[x]<siz[y]) swap(x, y);
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
  UnionFind uf(n);
  vector<int> deg(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    uf.unite(u, v);
    deg[u]++, deg[v]++;
  }
  vector<vector<int>> func(n);
  for(int i=0; i<n; i++){
    func[uf.root(i)].push_back(i);
  }
  ll ans=1, mod=998244353;
  for(int i=0; i<n; i++)if(func[i].size()){
    ll edge=0;
    for(auto q:func[i]) edge+=deg[q];
    edge/=2;
    if(func[i].size()!=edge){
      cout << 0 << endl; return 0;
    }
    ans*=2; ans%=mod;
  }
  cout << ans << endl;
  return 0;
}