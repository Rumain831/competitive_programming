#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<int, int, ll>;

//Tags: dp, セグ木

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
    return min(a, b);
  }
  void ltot(Tr& tr, La la, int l, int r){ //tr+=la*(r-l+1)
    tr=min(tr, la);
  }
  void composition(La& la_old, La la_new){ //lac+=lap
    la_old=min(la_old, la_new);
  }
  
  //書き方次第ではaの型も気にすべし
  void build(vector<Tr>& a){
    int n=a.size();
    N=pow2(n);
    iden=1e18, lazyiden=1e18;
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
  int n, m; cin >> n >> m;
  vector<tu> cp;
  for(int i=0; i<m; i++){
    int l, r; ll c; cin >> l >> r >> c; 
    cp.emplace_back(l, r, c);
  }
  sort(begin(cp), end(cp));
  vector<ll> dp(n+1, 1e18);
  dp[0]=0;
  lazytree seg;
  seg.build(dp);
  int ci=0;
  for(int i=1; i<=n; i++){
    ll base=seg.query(i, i+1);
    while(ci<m){
      auto [l, r, c]=cp[ci];
      if(l!=i) break;
      seg.update(l+1, r+1, base+c);
      ci++;
    }
  }
  ll ans=seg.query(n+1, n+1);
  cout << (ans==1e18?-1:ans) << endl;
  return 0; 
}