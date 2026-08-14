#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 実装

template<class Tr=ll>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){return min(a, b);}
  
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //aの型に注意
  void build(vector<ll>& a){
    int n=a.size();
    N=pow2(n);
    iden=1e18;
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]=a[i];
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
    if(s>t) return iden;
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
  ll n, d; cin >> n >> d;
  vector<P> cand;
  for(int i=0; i<n; i++){
    ll x, c; cin >> x >> c;
    cand.emplace_back(x, c);
  }
  sort(begin(cand), end(cand));
  vector<ll> x(n), c(n);
  for(int i=0; i<n; i++){
    auto [p, q]=cand[i];
    x[i]=p, c[i]=q;
  }
  segtree seg;
  seg.build(c);
  ll ans=1e18;
  for(int i=1; i<n; i++){
    int k=lower_bound(begin(x), end(x), x[i]-d)-begin(x);
    ans=min(ans, c[i]+seg.query(k, i-1));
  }
  cout << (ans==1e18?-1:ans) << endl;
  return 0; 
}