#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 桁和, segtree

int dp(ll x){
  string s=to_string(x);
  int d=s.size();
  vector dp(d+1, vector<int>(2, -1e9));
  dp[0][0]=0;
  for(int i=0; i<d; i++){
    int now=s[i]-'0';
    for(int ika=0; ika<2; ika++){
      int r=(ika?9:now);
      for(int p=0; p<=r; p++){
        int nika=(ika||p<now);
        dp[i+1][nika]=max(dp[i+1][nika], dp[i][ika]+p);
      }
    }
  }
  return max(dp[d][0], dp[d][1]);
}

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
  void build(vector<Tr> &a){
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
  int n, q; cin >> n >> q;
  vector<vector<int>> val(n);
  for(int i=0; i<n; i++){
    for(int j=0; j<=i; j++){
      ll x; cin >> x;
      val[i].push_back(dp(x));
    }
  }
  vector<segtree<int>> seg(n);
  for(int i=0; i<n; i++) seg[i].build(val[i]);
  while(q--){
    int l, p; ll t; cin >> l >> p >> t; l--, p--;
    if(p>l){
      cout << "NA" << '\n'; continue;
    } 
    int ans=-1;
    for(int i=0; i<=t&&l+i<n; i++){
      int left=p, right=p+i;
      ans=max(ans, seg[i+l].query(left, right));
    }
    cout << ans << '\n';
  }
  return 0; 
}