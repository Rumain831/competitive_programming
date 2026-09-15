#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  vector<ll> dp(n, 1e18);
  dp[0]=0;
  for(auto&x:a) cin >> x;
  for(int i=0; i<n; i++){
    for(int j=1; j<=2; j++){
      if(i+j>=n) continue;
      dp[i+j]=min(dp[i+j], dp[i]+max(a[i+j]-a[i], 0ll));
    }
  }
  cout << dp[n-1] << endl;
  return 0; 
}