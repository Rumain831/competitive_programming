#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using tu = tuple<int, int, int>;

//Tags: UnionFind, クエリ先読み

struct UnionFind{
  vector<int> par, siz;
  UnionFind(int n) : par(n, -1), siz(n, 1) {}  //メンバ変数をどのように初期化するかを表す
  //根を求める
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
  vector<vector<int>> to(n);
  vector<tu> edge;
  for(int i=0; i<m; i++){
    int a, b, y; cin >> a >> b >> y; a--, b--;
    to[a].push_back(b);
    to[b].push_back(a);
    edge.emplace_back(y, a, b);
  }
  int q; cin >> q;
  vector<tu> query;
  vector<int> ans(q);
  for(int i=0; i<q; i++){
    int v, w; cin >> v >> w; v--;
    query.emplace_back(w, v, i);
  } 
  int now=0;
  UnionFind uf(n);
  sort(rbegin(edge), rend(edge));
  sort(rbegin(query), rend(query));
  for(int i=0; i<q; i++){
    auto [year, st, idx]=query[i];
    while(now<m){
      auto [y, a, b]=edge[now];
      if(y>year){
        uf.unite(a, b);
        now++;
      }
      else break;
    }
    ans[idx]=uf.size(st);
  }
  for(int i=0; i<q; i++) cout << ans[i] << endl;
  return 0;
}