#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: 種類数, セグ木

template<class Tr=P>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){
    auto [a1, a2]=a;
    auto [b1, b2]=b;
    if(a1==b1){
      return P(a1, max(a2, b2));
    }
    else{
      if(a1>b1) return P(a1, max(a2, b1));
      else return P(b1, max(a1, b2));
    }
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
    iden=P(-1, -1);
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]=P(a[i], -1);
    for(int i=N-1; i>=1; i--) tree[i]=op(tree[2*i], tree[2*i+1]);
  }

  void update(int node, int x){  //0-indexed
    int i=node+N;
    tree[i]=P(x, -1); i/=2;
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
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  segtree seg;
  seg.build(a);
  while(q--){
    int t; cin >> t;
    if(t==1){
      int i, x; cin >> i >> x; i--;
      seg.update(i, x);
    } 
    else{
      int l, r; cin >> l >> r; l--, r--;
      auto [m1, m2]=seg.query(l, r);
      cout << (m2==-1?"Yes":"No") << '\n';
    }
  }
  return 0; 
}