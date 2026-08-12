#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<int, int, ll>;

//Tags: dp, in-place

template<class Tr=ll>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){return max(a, b);}
  
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //aの型に注意
  void build(int n){
    N=pow2(n);
    iden=-1e18;
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]=0;
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
  int n, t; cin >> n >> t;
  segtree seg;
  seg.build(t+1);
  vector<tu> meet;
  for(int i=0; i<n; i++){
    int l, r; ll v; cin >> l >> r >> v;
    meet.emplace_back(r, l, v);
  }
  sort(begin(meet), end(meet));
  seg.update(0, 0);
  for(int i=0; i<n; i++){
    auto [r, l, v]=meet[i];
    ll mx=seg.query(0, l-1);
    seg.update(r, mx+v);
  }
  cout << seg.query(0, t) << endl;
  return 0; 
}