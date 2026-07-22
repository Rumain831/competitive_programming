#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 貪欲法

//貪欲法が思いつかなかったのでdpによる解法を書いた
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
    iden=-1;
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
    if(s>t) return -1;
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
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  sort(begin(a), end(a));
  segtree dp0, dp1;
  dp0.build(n);
  dp1.build(n);
  dp0.update(0, 0);
  for(int i=1; i<n; i++){
    dp0.update(i, max(dp0.query(i-1, i-1), dp1.query(i-1, i-1)));
    int t=lower_bound(begin(a), end(a), a[i]-k)-begin(a);
    int x=dp0.query(t, i-1);
    if(x==-1) continue;
    dp1.update(i, x+1);
  }
  cout << max(dp0.query(n-1, n-1), dp1.query(n-1, n-1)) << endl;
  return 0; 
}