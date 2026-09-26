#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: grid, 長方形領域, 遅延伝播セグ木

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
  void build(int n){
    N=pow2(n);
    iden=0, lazyiden=0;
    tree.resize(2*N, iden), lazy.resize(2*N, lazyiden);
    //for(int i=0; i<n; i++) tree[N+i]=a[i];
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

struct Query{
  int id, i, j, sg;
  Query(int id, int i, int j, int sg):id(id), i(i), j(j), sg(sg){}
  bool operator<(const Query& other)const{
    if(i!=other.i) return i<other.i;
    else return id<other.id;
  } 
};

int main(void){
  int n, m, q; cin >> n >> m >> q;
  vector<int> l(n), r(n);
  for(int i=0; i<n; i++) cin >> l[i] >> r[i];
  vector<ll> ans(q);
  lazytree seg;
  seg.build(m+1);
  vector<Query> qu;
  for(int i=0; i<q; i++){
    int a, b, c, d; cin >> a >> b >> c >> d;
    qu.emplace_back(i, b, d, 1);
    qu.emplace_back(i, a-1, d, -1);
    qu.emplace_back(i, b, c-1, -1);
    qu.emplace_back(i, a-1, c-1, 1);
  }
  sort(begin(qu), end(qu));
  int qs=qu.size(), qi=0;
  for(int i=0; i<=n; i++){
    if(i) seg.update(l[i-1]+1, r[i-1]+1, 1);
    while(qi<qs){
      if(qu[qi].i!=i) break;
      int r=qu[qi].j, sg=qu[qi].sg, ni=qu[qi].id;
      ll x=seg.query(1, r+1);
      ans[ni]+=sg*x;
      qi++;
    }
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}