#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: ポテンシャル付きUnionFind
//解説URL: https://twitter.com/e869120/status/1405298187384999938
//クエリ先読みをしない解法(オンライン)

struct WeightedUnionFind{
  vector<int> par;
  vector<ll> pot;
  WeightedUnionFind(int n) : par(n, -1), pot(n, 0) {}  //メンバ変数をどのように初期化するかを表す
  //根がポテンシャルの基準点
  //pot[x]=U(x)-U(p)
  //pot[p]=U(p)-U(r)
  //xをrに繋ぎかえる
  //->pot[x] should be U(x)-U(r)=pot[x]+pot[p]
  int find(int x){
    if(par[x]<0) return x;
    int p=par[x];
    int r=find(p);
    pot[x]+=pot[p];
    return par[x]=r;
  }
  
  //x, yは同じ集合に属すか？　U(y)-U(x)をdにcopy
  bool issame(int x, int y, ll& d){
    int rx=find(x), ry=find(y);
    if(rx!=ry) return false;
    //pot[x]=U(x)-U(rx)
    //pot[y]=U(y)-U(ry)=U(y)-U(rx) (rx=ry)
    //->U(y)-U(x)=pot[y]-pot[x]
    d=pot[y]-pot[x];
    return true;
  }

  //xを含むグループとyを含むグループとを併合する
  //xの重み+w=yの重み
  bool unite(int x, int y, ll w){
    ll d;
    if(issame(x, y, d)) return d==w;
    int rx=find(x), ry=find(y);
    //pot[x]=U(x)-U(rx)
    //pot[y]=U(y)-U(ry)
    //ryをrxに繋げる->ryの親が変わりpot変更の必要が生じる
    //pot[ry] should be U(ry)-U(rx)
    //->pot[ry]=U(y)-pot[y]+pot[x]-U(x)=w-pot[y]+pot[x]
    ll w2=w-pot[y]+pot[x];
    if(par[rx]>par[ry]) swap(rx, ry), w2=-w2;
    par[rx]+=par[ry];
    par[ry]=rx;
    pot[ry]=w2;
    return true;
  }
};


int main(void){
  int n, q; cin >> n >> q;
  WeightedUnionFind uf(n);
  while(q--){
    int t, x, y; ll v; cin >> t >> x >> y >> v; x--, y--;
    if(t==0){
      v*=(y&1?-1:1);
      uf.unite(x, y, v);
    }
    else{
      ll d;
      if(!uf.issame(x, y, d)) cout << "Ambiguous" << '\n';
      else{
        if(x%2==y%2) cout << v+d*(x%2?-1:1) << '\n';
        else{ 
          ll by=v*(x%2?-1:1)+d;
          if(y%2) by*=-1;
          cout << by << '\n';
        } 
      }
    }
  }
  return 0; 
}