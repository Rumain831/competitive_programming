#include<iostream>
#include<vector>
using namespace std;

//Tags: 累積和, 愚直

struct UnionFind{
  vector<int> par, siz, rank, maxi, mini, maxj, minj;
  UnionFind(int n) : par(n, -1), siz(n, 1), rank(n, 1), maxi(n, -1), maxj(n, -1), mini(n, 1e9), minj(n, 1e9) {}  //コンストラクタ
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
    maxj[x]=max(maxj[x], maxj[y]);
    mini[x]=min(mini[x], mini[y]);
    minj[x]=min(minj[x], minj[y]);
    return true;
  }

  int size(int x){
    return siz[root(x)];
  }

  bool same(int u, int v){
    return root(u)==root(v);
  }

};

int h, w, n;

int id(int i, int j){
  return i*(w+2)+j;
}

int main(void){
  cin >> h >> w >> n;
  vector imos(h+2, vector<int>(w+2));
  for(int i=0; i<n; i++){
    int a, b, c, d; cin >> a >> b >> c >> d;
    imos[a][c]++, imos[a][d+1]--;
    imos[b+1][c]--, imos[b+1][d+1]++;
  }
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  UnionFind uf((h+2)*(w+2));
  for(int i=0; i<h+2; i++)for(int j=1; j<w+2; j++) imos[i][j]+=imos[i][j-1];
  for(int j=0; j<w+2; j++)for(int i=1; i<h+2; i++) imos[i][j]+=imos[i-1][j];
  for(int i=1; i<=h; i++)for(int j=1; j<=w; j++){
    int x=id(i, j);
    uf.mini[x]=uf.maxi[x]=i;
    uf.minj[x]=uf.maxj[x]=j;
    imos[i][j]%=2;
  }
  for(int i=1; i<=h; i++)for(int j=1; j<=w; j++)if(imos[i][j]){
    for(int k=0; k<4; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(ni<1||nj<1||ni>h||nj>w) continue;
      if(imos[ni][nj]==0) continue;
      uf.unite(id(i, j), id(ni, nj));
    }
  }
  int m; cin >> m;
  while(m--){
    int p, q, r, s; cin >> p >> q >> r >> s;
    int sum=0, cnt=0;
    for(int i=p; i<=q; i++)for(int j=r; j<=s; j++)if(imos[i][j]){
      sum++;
      int x=id(i, j);
      if(uf.root(x)==x){
        if(p<=uf.mini[x]&&uf.maxi[x]<=q&&r<=uf.minj[x]&&uf.maxj[x]<=s) cnt++;
      }
    }
    cout << sum << ' ' << cnt << '\n';
  }
  return 0; 
}