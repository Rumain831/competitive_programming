#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
void chmax(ll& a, ll b){a=max(a, b);}

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> a(n+2), b(n+2);
  for(int i=0; i<n; i++) cin >> a[i+1] >> b[i+1];
  vector dp(n+2, vector(k+1, vector<ll>(2, -1e18)));
  dp[0][0][0]=0;
  for(int i=0; i<n+1; i++){
    for(int j=0; j<=k; j++)for(int p=0; p<2; p++)for(int q=0; q<2; q++){
      if(dp[i][j][p]<0) continue;
      int nk=j+((p==0)&&q);
      if(nk>k) continue;
      chmax(dp[i+1][nk][q], dp[i][j][p]+(q?b[i+1]:a[i+1]));
    }
  }
  ll ans=-1;
  for(int i=0; i<=k; i++){
    chmax(ans, dp[n+1][i][0]);
  }
  cout << ans << endl;
  return 0; 
}