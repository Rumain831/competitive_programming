#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp, セグ木
//解説URL: https://twitter.com/e869120/status/1392248540882116610

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
  void build(vector<Tr>& a){
    int n=a.size();
    N=pow2(n);
    iden=-1;
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
  int w, n; cin >> w >> n;
  vector<int> l(n), r(n);
  vector<ll> v(n);
  for(int i=0; i<n; i++) cin >> l[i] >> r[i] >> v[i];
  vector<ll> dp(w+1, -1);
  dp[0]=0;
  segtree seg;
  seg.build(dp);
  for(int i=0; i<n; i++){
    for(int j=w; j>=0; j--){
      int left=max(0, j-r[i]), right=j-l[i];
      if(right<0) continue;
      ll now=seg.query(left, right);
      if(now<0) continue;
      seg.update(j, now+v[i]);
    }
  }
  ll ans=seg.query(w, w);
  cout << ans << endl;
  return 0;
}