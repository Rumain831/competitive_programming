#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 整数, dp, 桁和
//解説URL: https://twitter.com/e869120/status/1394423616805097477

int main(void){
  int k; cin >> k;
  if(k%9){
    cout << 0 << endl; return 0;
  }
  vector<ll> dp(k+1);
  ll mod=1e9+7;
  dp[0]=1;
  for(int i=1; i<=k; i++){
    for(int j=1; j<=9; j++){
      if(i-j>=0) dp[i]+=dp[i-j], dp[i]%=mod;
    }
  }
  cout << dp[k] << endl;
  return 0;
}