#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i] >> b[i];
  vector dp(n+1, vector<ll>(m+1, -1e18));
  dp[0][0]=0;
  for(int to=1; to<=n; to++){
    for(int from=0; from<to; from++)if(from==0||abs(from-to)<=k){
      for(int l=0; l+b[to-1]<=m; l++)if(dp[from][l]!=-1e18){
        dp[to][l+b[to-1]]=max(dp[to][l+b[to-1]], dp[from][l]+a[to-1]);
      }
    }
  }
  ll ans=0;
  for(int i=0; i<=m; i++)for(int j=1; j<=n; j++) ans=max(ans, dp[j][i]);
  cout << ans << endl;
  return 0;
}