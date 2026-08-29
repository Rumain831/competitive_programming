#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: segtree,　累積和

template<class Tr=int, class La=int>
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
    return min(a, b);
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
    iden=1e9, lazyiden=0;
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
  int n; cin >> n;
  string s; cin >> s;
  int q; cin >> q;
  vector<int> cnt(n+1);
  for(int i=0; i<n; i++) cnt[i+1]=cnt[i]+(s[i]=='A'?1:-1);
  lazytree seg;
  seg.build(cnt);
  while(q--){
    int t; cin >> t;
    if(t==1){
      int i; char c; cin >> i >> c;
      int add=(s[i-1]=='A'?-1:1);
      seg.update(i+1, n+1, add);
      s[i-1]=c;
      add=(s[i-1]=='A'?1:-1);
      seg.update(i+1, n+1, add);
    }
    else{
      int l, r; cin >> l >> r;
      int base=seg.query(l, l);
      int mi=seg.query(l+1, r+1);
      cout << (mi>=base?"Yes":"No") << '\n';
    }
  }
  return 0; 
}