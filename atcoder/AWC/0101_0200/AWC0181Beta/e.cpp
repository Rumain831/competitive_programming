#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: Simulation, セグ木

template<class Tr=P>
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
  void build(int n){
    N=pow2(n);
    iden=P(1e9, 1e9);
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]=P(0, i);
    for(int i=N-1; i>=1; i--) tree[i]=op(tree[2*i], tree[2*i+1]);
  }

  void update(int node, int x){  //0-indexed
    int i=node+N;
    tree[i].first+=x; i/=2;
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
  ll n, m, t; cin >> n >> m >> t;
  vector<vector<ll>> put(n);
  segtree seg;
  seg.build(n);
  while(m--){
    int s, l, r; cin >> s >> l >> r; l--, r--;
    auto [mi, id]=seg.query(l, r);
    put[id].push_back(s);
    seg.update(id, 1);
  }
  for(int i=0; i<n; i++){
    ll ans=0;
    for(auto x:put[i]) ans+=max(100-(t-x), 0ll);
    cout << ans << ' ';
  }
  return 0; 
}