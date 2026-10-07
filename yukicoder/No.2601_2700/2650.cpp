#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Tags: 座標圧縮, 遅延伝播セグ木
//Level: 2.5
//イベントソートでも可能

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
    return max(a, b);
  }
  void ltot(Tr& tr, La la, int l, int r){ //tr+=la*(r-l+1)
    tr=max(tr, la);
  }
  void composition(La& la_old, La la_new){ //lac+=lap
    la_old=max(la_old, la_new);
  }
  
  //書き方次第ではaの型も気にすべし
  void build(int n){
    N=pow2(n);
    iden=-1, lazyiden=0;
    tree.resize(2*N, iden), lazy.resize(2*N, lazyiden);
    for(int i=0; i<n; i++) tree[N+i]=-1;
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
  int n, a; cin >> n >> a;
  map<int, int> pos, dict;
  vector<int> x(n);
  for(auto&y:x) cin >> y, pos[y]++;
  int t; cin >> t;
  vector<int> l(t), r(t);
  for(int i=0; i<t; i++){
    cin >> l[i] >> r[i];
    pos[l[i]]++;
    pos[r[i]]++;
  }
  {
    int c=1;
    for(auto [y, _]:pos) dict[y]=c++;
  }
  int m=dict.size();
  lazytree seg;
  seg.build(m);
  for(int i=0; i<t; i++){
    int li=dict[l[i]];
    int ri=dict[r[i]];
    seg.update(li, ri, i+1);
  }
  for(int i=0; i<n; i++){
    int xi=dict[x[i]];
    cout << seg.query(xi, xi) << '\n';
  }
  return 0; 
}