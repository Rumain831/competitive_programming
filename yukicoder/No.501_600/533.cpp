#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp
//Level: 2.5

int main(void){
  int n; cin >> n;
  vector dp(n+3, vector<ll>(3));
  ll mod=1e9+7;
  for(int i=1; i<=3; i++) dp[i][i-1]=1;
  for(int i=1; i<=n; i++){
    for(int p=0; p<3; p++)for(int q=0; q<3; q++)if(p!=q){
      int ni=i+q+1;
      if(ni<=n){
        dp[ni][q]+=dp[i][p];
        dp[ni][q]%=mod;
      }
    }
  }
  ll ans=0;
  for(int i=0; i<3; i++) ans+=dp[n][i], ans%=mod;
  cout << ans << endl;
  return 0; 
}