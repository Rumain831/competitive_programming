#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
void chmax(ll& a, ll b){a=max(a, b);}

//Tags: dp

int main(void){
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  vector<ll> b(n), c(n);
  for(int i=0; i<n-1; i++) cin >> b[i] >> c[i];
  vector dp(n+1, vector<ll>(m+1, -1e18));
  dp[0][m]=0;
  for(int i=0; i<n; i++)for(int j=0; j<=m; j++)if(dp[i][j]>=0){
    if(j-a[i]<0) continue;
    {
      int nj=min<int>(m, j-a[i]+b[i]);
      chmax(dp[i+1][nj], dp[i][j]);
    }
    {
      int nj=j-a[i];
      chmax(dp[i+1][nj], dp[i][j]+c[i]);
    }
  }
  ll ans=-1e18;
  for(int i=0; i<=m; i++) chmax(ans, dp[n][i]);
  cout << ans << endl;
  return 0; 
}