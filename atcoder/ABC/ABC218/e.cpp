#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<ll, int, int>;

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
  vector<tu> edge;
  UnionFind uf(n);
  ll ans=0;
  for(int i=0; i<m; i++){
    int a, b; ll c; cin >> a >> b >> c; a--, b--;
    if(c<=0) uf.unite(a, b);
    else edge.emplace_back(c, a, b), ans+=c;
  }
  sort(edge.begin(), edge.end());
  for(auto [c, a, b]:edge){
    if(uf.same(a, b));
    else uf.unite(a, b), ans-=c;
  }
  cout << ans << endl;
  return 0;
}