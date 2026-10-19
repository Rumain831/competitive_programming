#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp, セグ木

const ll mod=1e9+7;
template<class Tr=ll>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){return (a+b)%mod;}
  
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //aの型に注意
  void build(int n){
    N=pow2(n);
    iden=0;
    tree.resize(2*N, iden);
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
  vector<int> f(n), last(m);
  for(auto&x:f) cin >> x, x--;
  segtree seg;
  seg.build(n+1);
  seg.update(0, 1);
  int l=0;
  for(int i=0; i<n; i++){
    l=max(l, last[f[i]]);
    ll add=seg.query(l, i);
    seg.update(i+1, add);
    last[f[i]]=i+1;
  }
  cout << seg.query(n, n) << endl;
  return 0; 
}