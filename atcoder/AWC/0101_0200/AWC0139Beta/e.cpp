#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 全探索, 候補のしぼり込み

template<class Tr=P>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){
    ll sm=a.first+b.first;
    ll mi=min(a.second, b.second);
    return P(sm, mi);
  }
  
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //aの型に注意
  void build(vector<P> &a){
    int n=a.size();
    N=pow2(n);
    iden=P(0, 1e18);
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]=P(a[i].second, a[i].second);
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
    if(s>t) return P(0ll, 0ll);
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
  ll n, m, k, l, c, r; cin >> n >> m >> k >> l >> c >> r;
  set<ll> lcand;
  vector<P> st;
  auto push=[&](ll x){
    if(x<0) x=0;
    if(x+l>n) x=n-l;
    lcand.insert(x);
  };
  for(int i=0; i<m; i++){
    ll p, d; cin >> p >> d;
    st.emplace_back(p, d);
    for(int d=-1; d<=1; d++){
      push(p+d);
      push(p-l+d);
    }
  }
  lcand.insert(0);
  lcand.insert(n-l);
  sort(begin(st), end(st));
  vector<ll> q;
  for(int i=0; i<k; i++){
    ll x; cin >> x;
    q.push_back(x);
    for(int d=-1; d<=1; d++){
      push(x+d);
      push(x-l+d);
    }
  }
  sort(begin(q), end(q));
  ll ans=-1e18;
  segtree seg;
  seg.build(st);
  for(auto x:lcand){
    int L=lower_bound(begin(st), end(st), P(x, -1e18))-begin(st);
    int R=lower_bound(begin(st), end(st), P(x+l, 1e18))-begin(st);
    R--;
    auto [sm, mi]=seg.query(L, R);
    ll cnt=upper_bound(begin(q), end(q), x+l)-lower_bound(begin(q), end(q), x);
    ans=max(ans, sm-c*cnt);
    ans=max(ans, sm-mi-c*cnt-r);
  }
  cout << ans << endl;
  return 0; 
}