#include<iostream>
#include<vector>
using namespace std;

//Tags: 区間反転
//https://codeforces.com/contest/2244/problem/E
//区間に対する操作は差分列を見るのは定石
//隣り合う文字が異なれば1, 同じなら0とする列を作る
//1回のflipで差分列における0を高々2回、1にできる

void solve(){
  int n, q; cin >> n >> q;
  string s; cin >> s;
  vector<int> adj(n-1), sum(n);
  for(int i=0; i<n-1; i++){
    sum[i+1]=(s[i]==s[i+1]?0:1);
  }
  for(int i=1; i<n; i++) sum[i]+=sum[i-1];
  while(q--){
    int l, r, k; cin >> l >> r >> k; l--, r--;
    int adnum=r-l, x=sum[r]-sum[l];
    int kk=(adnum-x+1)/2;
    cout << (kk<=k?"YES":"NO") << '\n';
  }
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}