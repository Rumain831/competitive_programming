#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 二分探索, 遅延伝播セグ木

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
    return max(a, b);
  }
  void ltot(Tr& tr, La la, int l, int r){ //tr+=la*(r-l+1)
    tr+=la;
  }
  void composition(La& la_old, La la_new){ //lac+=lap
    la_old+=la_new;
  }
  
  //書き方次第ではaの型も気にすべし
  void build(vector<Tr>& a){
    int n=a.size();
    N=pow2(n);
    iden=-1e18, lazyiden=0;
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
    if(t<s) return;
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
  vector<ll> a(n+1), b(n+1), sb(n+1), c(n+1);
  for(int i=0; i<n; i++){
    cin >> a[i+1] >> b[i+1];
    sb[i+1]=sb[i]+b[i+1];
  }
  for(int i=1; i<=n; i++) c[i]=a[i]-sb[i-1];
  lazytree seg;
  seg.build(c);
  while(q--){
    int t; cin >> t;
    if(t==1){
      int i; ll A, B; cin >> i >> A >> B;
      seg.update(i+1, i+1, A-a[i]);
      seg.update(i+2, n+1, b[i]-B);
      a[i]=A, b[i]=B;
    }
    else{
      ll s; cin >> s;
      int left=1, right=n+1;
      {
        ll x=seg.query(1, n+1);
        if(x<=s){
          cout << n << '\n'; continue;
        }
      }
      while(right-left>1){
        int mid=(left+right)/2;
        ll x=seg.query(1, mid);
        if(s<x) right=mid;
        else left=mid;
      }
      cout << left-1 << '\n';
    }
  }
  return 0; 
}