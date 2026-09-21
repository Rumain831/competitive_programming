#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 区間dp

int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector dp(n, vector<ll>(n));
  for(int i=0; i<n; i++) dp[i][i]=a[i];
  for(int k=2; k<=n; k++){
    for(int l=0; l+k-1<n; l++){
      int r=l+k-1, erase=n-k;
      if(erase&1) dp[l][r]=min(dp[l+1][r], dp[l][r-1]);
      else dp[l][r]=max(dp[l+1][r], dp[l][r-1]);
    }
  }
  cout << dp[0][n-1] << endl;
  return 0; 
}