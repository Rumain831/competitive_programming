#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
void chmax(ll& a, ll b){a=max(a, b);}

//Tags: dp

ll dp[301][301][501];
int main(void){
  int n, m, q; cin >> n >> m >> q;
  for(int i=0; i<=n; i++)for(int j=0; j<=n; j++)for(int k=0; k<=m; k++) dp[i][j][k]=-1;
  vector<ll> h(n), v(n);
  for(int i=0; i<n; i++) cin >> h[i] >> v[i];
  auto f=[&](int st){
    dp[st+1][st][0]=0;
    for(int i=st; i<n; i++)for(int j=0; j<=m; j++)if(dp[st+1][i][j]>=0){
      chmax(dp[st+1][i+1][j], dp[st+1][i][j]);
      if(j+h[i]<=m){
        chmax(dp[st+1][i+1][j+h[i]], dp[st+1][i][j]+v[i]);
      }
    }
  };
  for(int i=0; i<n; i++) f(i);
  while(q--){
    int l, r, x; cin >> l >> r >> x;
    ll ans=-1;
    for(int j=0; j<=x; j++) chmax(ans, dp[l][r][j]);
    cout << (ans==-1?0:ans) << '\n';
  }
  return 0; 
}