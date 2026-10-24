#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 数え上げ, 木, 順列

template<class Tr=int>
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
    iden=0;
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
  int n; cin >> n;
  vector<int> q(n);
  for(auto&x:q) cin >> x, x--;
  segtree seg;
  seg.build(n+2);
  ll ans=1, mod=998244353;
  seg.update(0, 1);
  for(int i=1; i<n; i++){
    int r=seg.query(q[i]+1, n);
    ll mul=(r==0?i:i-r);
    ans*=mul, ans%=mod;
    seg.update(q[i], i);
  }
  cout << ans << endl;
  return 0; 
}