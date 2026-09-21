#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 最適化, セグ木

template<class Tr=P>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){
    return P(max(a.first, b.first), a.second+b.second);
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
    iden=P(-1, 0);
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]=P(a[i], a[i]);
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
  int n, m; cin >> n >> m;
  vector<ll> h(n);
  for(auto&x:h) cin >> x;
  ll w=-1;
  while(m--){
    ll x; cin >> x;
    w=max(w, x);
  }
  segtree seg;
  seg.build(h);
  ll ans=-1, sum=seg.query(0, n-1).second;
  for(int i=0; i+w-1<n; i++){
    int r=i+w-1;
    auto [mx, s]=seg.query(i, r);
    ll now=sum-s+mx*w;
    ans=max(ans, now);
  }
  cout << ans << endl;
  return 0; 
}