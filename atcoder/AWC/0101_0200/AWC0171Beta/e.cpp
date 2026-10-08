#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: セグ木

struct info{
  int mx1=0, mx2=0;
  int l, r;
  bool e=false;
  info(){}
  info(int l, int r, bool e=false):l(l), r(r), e(e){}
};

template<class Tr=info>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){
    if(a.e) return b;
    if(b.e) return a;
    int x[5]={a.mx1, a.mx2, b.mx1, b.mx2, abs(a.r-b.l)};
    sort(x, x+5);
    info ans=info(a.l, b.r);
    ans.mx1=x[4], ans.mx2=x[3];
    return ans;
  }
  
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //aの型に注意
  void build(vector<int> &a){
    int n=a.size();
    N=pow2(n);
    iden=info(0, 0, true);
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]=info(a[i], a[i]);
    for(int i=N-1; i>=1; i--) tree[i]=op(tree[2*i], tree[2*i+1]);
  }

  void update(int node, int x){  //0-indexed
    int i=node+N;
    tree[i]=info(x, x); i/=2;
    while(i>0){
      tree[i]=op(tree[2*i], tree[2*i+1]); i/=2;
    }
    return;
  }

  Tr query(int s, int t){  //0-indexed
    int left=s+N, right=t+N;
    Tr ansl=iden, ansr=iden;
    while(left<=right){
      if(left%2==1){
        ansl=op(ansl, tree[left]); left++;
      }
      if(right%2==0){
        ansr=op(tree[right], ansr); right--;
      }
      left/=2, right/=2;
    }
    return op(ansl, ansr);
  }
};


int main(void){
  int n, q, k; cin >> n >> q >> k;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  segtree<info> seg;
  seg.build(a);
  while(q--){
    int t; cin >> t;
    if(t==1){
      int p, v; cin >> p >> v; p--;
      seg.update(p, v);
    }
    else{
      int l, r; cin >> l >> r; l--, r--;
      auto p=seg.query(l, r);
      if(p.mx1<=k) cout << p.mx1 << '\n';
      else cout << p.mx2 << '\n';
    }
  }
  return 0; 
}