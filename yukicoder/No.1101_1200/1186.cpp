#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 数え上げ, dp
//Level: 2
//初手に縦長を置くか、横長を敷き詰めるかで漸化式が立つ
//n=1のとき、縦長=横長となることに注意

int main(void){
  int n, m; cin >> n >> m;
  ll mod=998244353;
  vector<ll> dp(m+1);
  dp[0]=1;
  for(int i=1; i<=m; i++){
    dp[i]+=dp[i-1];
    if(n>1&&i-n>=0) dp[i]+=dp[i-n];
    dp[i]%=mod;
  }
  cout << dp[m] << endl;
  return 0; 
}