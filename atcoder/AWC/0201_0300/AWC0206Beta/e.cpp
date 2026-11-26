#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp, セグ木

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
    for(int i=0; i<n; i++) tree[N+i]=iden;
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
  int n, k; cin >> n >> k;
  vector<ll> x(n), a(n);
  for(int i=0; i<n; i++) cin >> x[i] >> a[i];
  segtree seg;
  seg.build(n);
  seg.update(0, a[0]);
  int id=0;
  for(int i=1; i<n; i++){
    ll now=x[i];
    while(id<=n){
      ll y=x[id];
      if(now-y>k) id++;
      else break;
    }
    ll mx=seg.query(id, i-1);
    if(mx==-1e18) break;
    seg.update(i, mx+a[i]);
  }
  ll ans=seg.query(n-1, n-1);
  cout << (ans==-1e18?-1:ans) << endl;
  return 0; 
}