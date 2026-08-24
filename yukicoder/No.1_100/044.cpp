#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp
//Level: 1.5

int main(void){
  int n; cin >> n;
  vector<ll> dp(n+1);
  dp[0]=1;
  for(int i=0; i<n; i++){
    if(i+1<=n) dp[i+1]+=dp[i];
    if(i+2<=n) dp[i+2]+=dp[i];
  }
  cout << dp[n] << endl;
  return 0; 
}