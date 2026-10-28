#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp, 文字列, 数え上げ

int main(void){
  int n; string s; cin >> n >> s;
  ll mod=998244353;
  vector dp(n+1, vector<ll>(2));
  dp[0][1]=1;
  for(int i=0; i<n; i++){
    int x=s[i]-'A';
    for(int pre=0; pre<2; pre++)for(int now=0; now<2; now++){
      if(pre==0&&now==0) continue;
      if(x!=2&&x!=now) continue;
      dp[i+1][now]+=dp[i][pre];
      dp[i+1][now]%=mod;
    }
  }
  cout << (dp[n][0]+dp[n][1])%mod << endl;
  return 0; 
}