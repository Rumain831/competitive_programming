#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: Simulation
//添字まで求める必要はないのでmultisetで十分だった模様

struct info{
  ll max=-1e18, min=1e18, min_id=1e9, max_id=1e9, sum=0;
  info(){}
  info(ll x, int i):max(x), min(x), min_id(i), max_id(i), sum(x){}
};

template<class Tr=info>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){
    info ans;
    if(a.max==b.max){
      ans.max=a.max, ans.max_id=min(a.max_id, b.max_id);
    }
    else{
      if(a.max>b.max) ans.max=a.max, ans.max_id=a.max_id;
      else ans.max=b.max, ans.max_id=b.max_id;
    }
    if(a.min==b.min){
      ans.min=a.min, ans.min_id=min(a.min_id, b.min_id);
    }
    else{
      if(a.min<b.min) ans.min=a.min, ans.min_id=a.min_id;
      else ans.min=b.min, ans.min_id=b.min_id;
    }
    ans.sum=a.sum+b.sum;
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
    iden=info();
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]=info(a[i], i);
    for(int i=N-1; i>=1; i--) tree[i]=op(tree[2*i], tree[2*i+1]);
  }

  void update(int node, ll x){  //0-indexed
    int i=node+N;
    tree[i]=info(x, node); i/=2;
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
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  segtree seg;
  seg.build(a);
  while(q--){
    int t, r; ll x; cin >> t >> x >> r; 
    if(r==1) continue;
    auto p=seg.query(0, n-1);
    int id=(t==1?p.max_id:p.min_id);
    seg.update(id, x);
  }
  cout << seg.query(0, n-1).sum << endl;
  return 0; 
}