#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

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
  void build(vector<Tr> &a){
    int n=a.size();
    N=pow2(n);
    iden=1e9;
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


void solve(){
  int n; cin >> n;
  vector<ll> a(n+1, 1e9);
  for(int i=0; i<n; i++) cin >> a[i];
  reverse(a.begin(), a.end());
  a.push_back(-1); n++;
  segtree seg;
  seg.build(a);
  ll base=0, ans;
  {
    ll mn=a[0];
    for(int i=1; i<n; i++){
      base+=max(0ll, a[i]-mn);
      mn=min(mn, a[i]);
    }
  }
  ans=base;
  ll mn=a[0];
  for(int i=1; i<n; i++){
    if(mn<a[i]) continue;
    int left=i, right=n;
    ll tar=a[i];
    while(right-left>1){
      ll mid=(left+right)/2;
      if(seg.query(i, mid)>=tar) left=mid;
      else right=mid;
    }
    ll now=base-1+right-i;
    ans=max(ans, now);
    mn=min(mn, a[i]);
  }
  cout << ans << endl;
};

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}
