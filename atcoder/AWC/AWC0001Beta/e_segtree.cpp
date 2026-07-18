#include<iostream>
#include<vector>
using namespace std;
using P = pair<int, int>;

//セグ木を用いた解法
template<class Tr=P>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){
    auto [amin, amax]=a;
    auto [bmin, bmax]=b;
    return P(min(amin, bmin), max(amax, bmax));
  }
  
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //aの型に注意
  void build(vector<int> &a){
    int n=a.size();
    N=pow2(n);
    iden=P(2e9, -2e9);
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
  int n, k; cin >> n >> k;
  vector<int> h(n);
  for(auto&x:h) cin >> x;
  segtree seg;
  seg.build(h);
  int ans=-2e9;
  for(int i=0; i<n-k+1; i++){
    auto [mi, mx]=seg.query(i, i+k-1);
    ans=max(ans, mx-mi);
  }
  cout << ans << endl;
  return 0;
}