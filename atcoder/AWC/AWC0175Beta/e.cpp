#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: セグ木, 区間

template<class Tr=P>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){
    return P(a.first+b.first, a.second+b.second);
  }
  
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //aの型に注意
  void build(int n){
    N=pow2(n);
    iden=P(0, 0);
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]=P(0, 0);
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
    if(right<left) return iden;
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
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<int> cnt(n+1), mul(n+1), st(n);
  segtree seg;
  set<int> pos;
  seg.build(n+2);
  int nl=-n-10, nr=2*n+10;
  {
    int pre=nl;
    for(int i=0; i<n; i++)if(s[i]=='1'){
      st[i]=1;
      pos.insert(i);
      int l=i-pre+1;
      l=min(l, n+1);
      seg.update(l, P(l, 1));
      pre=i;
    }
    int l=nr-pre+1;
    l=min(l, n+1);
    seg.update(l, P(l, 1));
    pos.insert(nl);
    pos.insert(nr);
  }
  while(q--){
    int t; cin >> t;
    if(t==1){
      int x; cin >> x; x--;
      int sg=1;
      if(st[x]) pos.erase(x), sg*=-1;
      auto it=pos.lower_bound(x);
      int l=*prev(it), r=*it;
      int len=min(n+1, r-l+1);
      int len1=min(n+1, x-l+1);
      int len2=min(n+1, r-x+1);
      seg.update(len, P(-len*sg, -sg));
      seg.update(len1, P(len1*sg, sg));
      seg.update(len2, P(len2*sg, sg));
      if(st[x]==0) pos.insert(x);
      st[x]^=1;
    }
    else{
      int d; cin >> d;
      if(d==0||pos.size()==2){
        cout << (int)pos.size()-2 << '\n'; continue;
      }
      auto [sum, cnt]=seg.query(2*d+2, n+1);
      ll dark=sum-(2*d+2)*cnt;
      int l=*next(begin(pos));
      dark-=max(0, n+1-(2*d+2));
      dark+=max(0, l-d);
      int r=*prev(prev(end(pos)));
      dark-=max(0, n+1-(2*d+2));
      int len=n-r+1;
      dark+=max(0, len-(d+2));
      cout << n-dark << '\n';
    }
  }
  return 0; 
}