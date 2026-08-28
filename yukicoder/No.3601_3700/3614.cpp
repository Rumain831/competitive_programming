#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using vc = vector<ll>;

//Tags: segtree, merge-sort tree
//Level: 2.5

template<class Tr=vc>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){
    int ia=0, ib=0, na=a.size(), nb=b.size();
    vc ans;
    while(ia<na||ib<nb){
      ll la=(ia==na?1e18:a[ia]);
      ll lb=(ib==nb?1e18:b[ib]);
      if(la<lb) ans.push_back(a[ia++]);
      else ans.push_back(b[ib++]);
      if(ans.size()==10) break;
    }
    return ans;
  }
  
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //aの型に注意
  void build(vector<ll> &a){
    int n=a.size();
    N=pow2(n);
    iden={};
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]={a[i]};
    for(int i=N-1; i>=1; i--) tree[i]=op(tree[2*i], tree[2*i+1]);
  }

  void update(int node, Tr x){  //0-indexed
    int i=node+N;
    tree[i]=op(tree[i], x); i/=2;
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
  vector<ll> s(n);
  for(auto&x:s) cin >> x;
  segtree seg;
  seg.build(s);
  while(q--){
    int l, r, k; cin >> l >> r >> k; l--, r--;
    auto v=seg.query(l, r);
    ll ans=0;
    for(int i=0; i<k; i++) ans+=v[i];
    cout << ans << '\n'; 
  }
  return 0; 
}