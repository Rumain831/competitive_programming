#include<iostream>
#include<vector>
using namespace std;

//Tags: grid, UnionFind
//解説URL: https://twitter.com/e869120/status/1381739128291614720

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


int h, w;
int id(int i, int j){
  return i*w+j;
}
int main(void){
  cin >> h >> w;
  int q; cin >> q;
  UnionFind uf(h*w);
  vector col(h, vector<int>(w));
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  while(q--){
    int t; cin >> t;
    if(t==1){
      int r, c; cin >> r >> c; r--, c--;
      col[r][c]=1;
      for(int k=0; k<4; k++){
        int ni=r+di[k], nj=c+dj[k];
        if(ni<0||nj<0||ni>=h||nj>=w) continue;
        if(col[ni][nj]==0) continue;
        uf.unite(id(ni, nj), id(r, c));
      }
    }
    else{
      int ra, ca, rb, cb; 
      cin >> ra >> ca >> rb >> cb; ra--, ca--, rb--, cb--;
      if(col[ra][ca]==0||col[rb][cb]==0) cout << "No" << '\n';
      else{
        cout << (uf.same(id(ra, ca), id(rb, cb))?"Yes":"No") << '\n';
      }
    }
  }
  return 0; 
}