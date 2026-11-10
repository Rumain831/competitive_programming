#include<iostream>
#include<vector>
using namespace std;

//Tags: dp

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  vector<int> dp(n, 1e9);
  dp[0]=0;
  for(int i=0; i<n-1; i++)for(int j=1; j<=2; j++){
    int ni=i+j;
    if(ni>=n) continue;
    dp[ni]=min(dp[ni], dp[i]+abs(a[i]-a[ni]));
  }
  cout << dp[n-1] << endl;
  return 0;
}