#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

struct SqrtDecomposition{
  int n, B, nb;
  vector<ll> a;
  vector<ll> block;
  vector<ll> lazy;

  //Range Sum
  SqrtDecomposition(vector<ll>& v){
    a=v;
    n=a.size();
    B=450;
    //B=max(1, sqrt(n));
    nb=(n+B-1)/B;
    block.assign(nb, 0);
    lazy.assign(nb, 0);
    for(int i=0; i<n; i++){
      block[i/B]+=a[i];
    }
  }

  int L(int bi){ //ブロックの左端
    return bi*B;
  }
  int R(int bi){ //ブロックの右端+1 ブロックbi=[L(bi), R(bi))
    return min(n, (bi+1)*B);
  }

  void eval(int bi){
    if(lazy[bi]==0) return;
    for(int i=L(bi); i<R(bi); i++) a[i]+=lazy[bi];
    lazy[bi]=0;
  }

  void rebuild(int bi){
    block[bi]=0;
    for(int i=L(bi); i<R(bi); i++) block[bi]+=a[i];
  }

  void update(int l, int r, ll x){ //[l, r), 0-indexed
    if(l>=r) return;
    int lb=l/B, rb=(r-1)/B;
    if(lb==rb){
      eval(lb);
      for(int i=l; i<r; i++) a[i]+=x;
      rebuild(lb);
      return;
    }

    //左端
    eval(lb);
    for(int i=l; i<R(lb); i++) a[i]+=x;
    rebuild(lb);
    //ブロック部分
    for(int i=lb+1; i<rb; i++){
      lazy[i]+=x;
      block[i]+=x*(R(i)-L(i));
    }
    //右端
    eval(rb);
    for(int i=L(rb); i<r; i++) a[i]+=x;
    rebuild(rb);

  }

  ll query(int l, int r){ //[l, r), 0-indexed
    if(l>=r) return 0ll;
    ll ans=0;
    int lb=l/B, rb=(r-1)/B;
    if(lb==rb){
      eval(lb);
      for(int i=l; i<r; i++) ans+=a[i];
      rebuild(lb);
      return ans;
    }
    //左端
    eval(lb);
    for(int i=l; i<R(lb); i++) ans+=a[i];
    rebuild(lb);
    //ブロック部分
    for(int i=lb+1; i<rb; i++){
      ans+=block[i];
    }
    //右端
    eval(rb);
    for(int i=L(rb); i<r; i++) ans+=a[i];
    rebuild(rb);
    return ans;
  }
};


int main(void){
  
  return 0;
}