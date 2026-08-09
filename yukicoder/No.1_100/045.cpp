#include<iostream>
#include<vector>
using namespace std;

//Tags: dp

int main(void){
  int n; cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  vector dp(n+1, vector<int>(2));
  for(int i=0; i<n; i++){
    dp[i+1][0]=max(dp[i][0], dp[i][1]);
    dp[i+1][1]=dp[i][0]+v[i];
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
  return 0;
}