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

template<class Tr=ll, class La=ll>
struct lazytree{
  int N;
  Tr iden;     vector<Tr> tree;
  La lazyiden; vector<La> lazy;
   
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //単位元を忘れずに書き換えること
  Tr opt(Tr a, Tr b){
    return a+b;
  }
  void ltot(Tr& tr, La la, int l, int r){ //tr+=la*(r-l+1)
    tr+=la*(r-l+1);
  }
  void com(La& lac, La lap){ //lac=lap
    lac+=lap;
  }
  
  //書き方次第ではaの型も気にすべし
  void build(vector<Tr>& a){
    int n=a.size();
    N=pow2(n);
    iden=0, lazyiden=0;
    tree.resize(2*N, iden), lazy.resize(2*N, lazyiden);
    for(int i=0; i<n; i++) tree[N+i]=a[i];
    for(int i=N-1; i>=1; i--) tree[i]=opt(tree[2*i], tree[2*i+1]);
  }

  void eval(int k, int l, int r){
    if(lazy[k]!=lazyiden){
      ltot(tree[k], lazy[k], l, r); 
      if(l!=r){
        com(lazy[2*k], lazy[k]);
        com(lazy[2*k+1], lazy[k]);
      }
      lazy[k]=lazyiden; 
    }
  }

  void update(int s, int t, La x, int k=1, int l=1, int r=-1){ //s, tは1-indexed!
    if(r<0) r=N;
    eval(k, l, r);
    if(t<l||r<s) return;
    if(s<=l&&r<=t){
      com(lazy[k], x);
      eval(k, l, r);
      return;
    }
    else{
      int mid=(l+r)/2;
      update(s, t, x, 2*k, l, mid);
      update(s, t, x, 2*k+1, mid+1, r);
      tree[k]=opt(tree[2*k], tree[2*k+1]);
    }
    return;
  }

  Tr query(int s, int t, int k=1, int l=1, int r=-1){ //s, tは1-indexed!
    if(r<0) r=N;
    eval(k, l, r);
    if(t<l||r<s) return iden;
    if(s<=l&&r<=t) return tree[k];
    int mid=(l+r)/2;
    Tr A=query(s, t, 2*k, l, mid);
    Tr B=query(s, t, 2*k+1, mid+1, r);
    return opt(A, B);
  }
};


void solve(){
  int n; cin >> n;
  vector<ll> a(n), emp(n);
  for(int i=0; i<n; i++) cin >> a[i];
  reverse(a.begin(), a.end());
  ll base=0, ans;
  {
    lazytree cnt;
    cnt.build(emp);
    for(ll i=0; i<n; i++){
      ll under=cnt.query(1, a[i]);
      base+=i*a[i]-under;
      cnt.update(1, a[i], 1);
    }
    ans=base;
    lazytree right;
    right.build(emp);
    for(ll i=n-1; i>=0; i--){
      cnt.update(1, a[i], -1);
      ll left=i-cnt.query(a[i], a[i]);
      ll same=right.query(a[i], a[i]);
      ans=max(ans, base-left+same);
      right.update(1, a[i], 1);
    }
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
