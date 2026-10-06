#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
void chmin(ll& a, ll b){a=min(a, b);}

//Tags: dp

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> x(n+1), l(n), r(n), a(n), b(n);
  for(int i=0; i<n; i++) cin >> x[i+1];
  for(int i=0; i<n; i++) cin >> l[i] >> r[i] >> a[i] >> b[i];
  vector dp(n+1, vector<ll>(n+1, 1e18));
  dp[0][0]=0;
  for(int i=1; i<=n; i++){
    for(int k=1; k<=i; k++)for(int j=0; j<=i; j++){
      int p=i-j;
      if(p<l[j]||r[j]<p) continue;
      chmin(dp[i][k], dp[j][k-1]+a[j]*(x[i]-x[j])+b[j]);
    }
  }
  while(q--){
    ll c; cin >> c;
    ll ans=1e18;
    for(int i=1; i<=n; i++)if(dp[n][i]!=1e18) chmin(ans, dp[n][i]+c*i);
    if(ans==1e18) cout << -1 << '\n';
    else cout << ans << '\n';
  }
  return 0; 
}