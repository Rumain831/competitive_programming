#include<iostream>
#include<vector>
using namespace std;

//Tags: bitDP
//Level: 3.5

int main(void){
  int n; cin >> n;
  vector a(n, vector<int>(n));
  for(auto&x:a)for(auto&y:x) cin >> y;
  int mx=(1<<n);
  vector<int> dp(mx, -1e9);
  dp[0]=0;
  for(int i=0; i<mx; i++){
    if(dp[i]<0) continue;
    for(int j=0; j<n; j++)if(!(i>>j&1)){
      for(int k=j+1; k<n; k++)if(!(i>>k&1)){
        int ni=(i|(1<<j))|(1<<k);
        dp[ni]=max(dp[ni], dp[i]+a[j][k]);
      }
      break;
    }
  }
  cout << dp[mx-1] << endl;
  return 0; 
}