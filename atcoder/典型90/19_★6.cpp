#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
void chmin(ll& a, ll b){a=min(a, b);}

//Tags: 区間dp
//解説URL: https://twitter.com/e869120/status/1384638694162780166

int main(void){
  int n; cin >> n;
  vector<ll> a(2*n);
  for(auto&x:a) cin >> x;
  int m=2*n;
  vector dp(m, vector<ll>(m, 1e18));
  for(int i=0; i<m-1; i++) dp[i][i+1]=abs(a[i]-a[i+1]);
  for(int k=2; k<=n; k++){
    for(int l=0; l+2*k-1<m; l++){
      int r=l+2*k-1;
      chmin(dp[l][r], abs(a[l]-a[r])+dp[l+1][r-1]);
      for(int p=l+1; p+2<=r; p+=2){
        chmin(dp[l][r], dp[l][p]+dp[p+1][r]);
      }
    }
  }
  cout << dp[0][2*n-1] << endl;
  return 0;
}