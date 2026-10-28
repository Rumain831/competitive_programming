#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: Simulation, セグ木, 二分探索

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
  void ltot(Tr& tr, La la, int l, int r){ //tr+=la*(r-l+1)
    tr+=la*(r-l+1);
  }
  void composition(La& la_old, La la_new){ //lac+=lap
    la_old+=la_new;
  }
  
  //書き方次第ではaの型も気にすべし
  void build(vector<Tr>& a){
    int n=a.size();
    N=pow2(n);
    iden=0, lazyiden=0;
    tree.resize(2*N, iden), lazy.resize(2*N, lazyiden);
    for(int i=0; i<n; i++) tree[N+i]=a[i];
    for(int i=N-1; i>=1; i--) tree[i]=opt(tree[2*i], tree[2*i+1]);
  }

  void apply(int k, La x, int l, int r){
    ltot(tree[k], x, l, r);
    composition(lazy[k], x);
  }

  void push(int k, int l, int r){ //自分に溜まったlazyを子に伝える
    if(lazy[k]==lazyiden||l==r) return;
    int mid=(l+r)/2;
    apply(2*k, lazy[k], l, mid);
    apply(2*k+1, lazy[k], mid+1, r);
    lazy[k]=lazyiden;
  }

  void update(int s, int t, La x, int k=1, int l=1, int r=-1){ //s, tは1-indexed!
    if(r<0) r=N;
    if(t<l||r<s) return;
    if(s<=l&&r<=t){
      apply(k, x, l, r);
      return;
    }
    push(k, l, r);
    int mid=(l+r)/2;
    update(s, t, x, 2*k, l, mid);
    update(s, t, x, 2*k+1, mid+1, r);
    tree[k]=opt(tree[2*k], tree[2*k+1]);
    return;
  }

  Tr query(int s, int t, int k=1, int l=1, int r=-1){ //s, tは1-indexed!
    if(r<0) r=N;
    if(t<l||r<s) return iden;
    if(s<=l&&r<=t) return tree[k];
    push(k, l, r);
    int mid=(l+r)/2;
    Tr A=query(s, t, 2*k, l, mid);
    Tr B=query(s, t, 2*k+1, mid+1, r);
    return opt(A, B);
  }
};


int main(void){
  int n, q; cin >> n >> q;
  vector<ll> v(n), p(n, 1);
  lazytree seg, cl, sum;
  cl.build(p), sum.build(v);
  for(auto&x:v) cin >> x;
  seg.build(v);
  auto find=[&](int x){
    if(cl.query(1, 1)==x) return 1;
    int left=1, right=n;
    while(right-left>1){
      int mid=(left+right)/2;
      if(cl.query(1, mid)<x) left=mid;
      else right=mid;
    }
    return right;
  };
  while(q--){
    int t; cin >> t;
    if(t==1){
      int l, r; ll x; cin >> l >> r >> x;
      seg.update(l, r, x);
    }
    else if(t==2){
      int p; cin >> p;
      ll x=seg.query(p, p);
      sum.update(p, p, x);
      cl.update(p, p, -1);
    }
    else{
      int k; cin >> k;
      int i=find(k);
      cout << sum.query(1, i) << '\n';
    }
  }
  return 0; 
}