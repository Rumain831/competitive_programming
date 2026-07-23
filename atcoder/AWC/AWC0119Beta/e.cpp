#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 遅延伝播セグ木

template<class Tr=ll, class La=ll>
struct lazytree{
  int N;
  Tr iden;     vector<Tr> tree;
  La lazyiden; vector<La> lazy;
   
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //単位元を忘れずに書き換えること
  Tr opt(Tr a, Tr b){
    return a+b;
  }
  void ltot(Tr& tr, La la, int l, int r){
    tr+=la*(r-l+1);
  }
  void com(La& lac, La lap){ 
    lac+=lap;
  }
  
  //書き方次第ではaの型も気にすべし
  void build(int n){
    N=pow2(n);
    iden=0, lazyiden=0;
    tree.resize(2*N, iden), lazy.resize(2*N, lazyiden);
    for(int i=0; i<n; i++) tree[N+i]=0;
    for(int i=N-1; i>=1; i--) tree[i]=opt(tree[2*i], tree[2*i+1]);
  }

  void eval(int k, int l, int r){
    if(lazy[k]!=lazyiden){
      ltot(tree[k], lazy[k], l, r); 
      if(l!=r){
        com(lazy[2*k], lazy[k]);
        com(lazy[2*k+1], lazy[k]);
      }
      lazy[k]=lazyiden; 
    }
  }

  void update(int s, int t, La x, int k=1, int l=1, int r=-1){ //s, tは1-indexed!
    if(r<0) r=N;
    eval(k, l, r);
    if(t<l||r<s) return;
    if(s<=l&&r<=t){
      com(lazy[k], x);
      eval(k, l, r);
      return;
    }
    else{
      int mid=(l+r)/2;
      update(s, t, x, 2*k, l, mid);
      update(s, t, x, 2*k+1, mid+1, r);
      tree[k]=opt(tree[2*k], tree[2*k+1]);
    }
    return;
  }

  Tr query(int s, int t, int k=1, int l=1, int r=-1){ //s, tは1-indexed!
    if(r<0) r=N;
    eval(k, l, r);
    if(t<l||r<s) return iden;
    if(s<=l&&r<=t) return tree[k];
    int mid=(l+r)/2;
    Tr A=query(s, t, 2*k, l, mid);
    Tr B=query(s, t, 2*k+1, mid+1, r);
    return opt(A, B);
  }
};


int main(void){
  int n, q; cin >> n >> q;
  lazytree seg;
  seg.build(n);
  while(q--){
    int t; cin >> t;
    if(t==1){
      int l, r; cin >> l >> r;
      seg.update(l, r, 1);
    }
    else if(t==2){
      int p; cin >> p; 
      ll x=seg.query(p, p);
      seg.update(p, p, -x);
    }
    else{
      int l, r; cin >> l >> r;
      cout << seg.query(l, r) << '\n';
    }
  }
  return 0; 
}