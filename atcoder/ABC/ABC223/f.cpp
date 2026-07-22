#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: 括弧列

template<class Tr=P, class La=int>
struct lazytree{
  int N;
  Tr iden;     vector<Tr> tree;
  La lazyiden; vector<La> lazy;
   
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  Tr opt(Tr a, Tr b){
    return Tr(a.first+b.first, min(a.second, b.second));
  }
  void ltot(Tr& tr, La la, int l, int r){
    tr.first+=la*(r-l+1), tr.second+=la;
  }
  void com(La& lac, La lap){
    lac+=lap;
  }
  
  void build(vector<int>& a){
    int n=a.size();
    N=pow2(n);
    iden=P(0, 1e9), lazyiden=0;
    tree.resize(2*N, iden), lazy.resize(2*N, lazyiden);
    for(int i=0; i<n; i++) tree[N+i]=P(a[i], a[i]);
    for(int i=N-1; i>=1; i--) tree[i]=opt(tree[2*i], tree[2*i+1]);
  }

  void eval(int k, int l, int r){
    if(lazy[k]!=lazyiden){
      ltot(tree[k], lazy[k], l, r); //lazy[k]の値に強制的に切り替えられるのがquery
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

int main(void){
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<int> a(n), sum(n+1);
  for(int i=0; i<n; i++){
    a[i]=(s[i]=='('?1:-1);
    sum[i+1]=sum[i]+a[i];
  }
  lazytree seg;
  seg.build(sum);
  while(q--){
    int t, l, r; cin >> t >> l >> r; l++, r++;
    if(t==1){
      swap(a[l-2], a[r-2]);
      seg.update(l, r-1, a[l-2]-a[r-2]);
    }
    else{
      auto [sumr, mr]=seg.query(r, r);
      auto [suml, ml]=seg.query(l-1, l-1);
      if(suml!=sumr){
        cout << "No" << '\n'; continue;
      }
      cout << (seg.query(l, r).second==mr?"Yes":"No") << '\n';
    }
  }
  return 0;
}
