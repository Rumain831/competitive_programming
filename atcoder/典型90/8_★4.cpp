#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp, 文字列
//解説URL: https://twitter.com/e869120/status/1379927227739987972

int main(void){
  int n; cin >> n;
  string s; cin >> s;
  string atc="atcoder";
  ll mod=1e9+7, m=atc.size();
  vector<ll> dp(m+1);
  dp[0]=1;
  for(int i=0; i<n; i++){
    vector<ll> old(m+1);
    swap(old, dp);
    for(int j=0; j<=m; j++){
      dp[j]+=old[j], dp[j]%=mod;
      if(j&&s[i]==atc[j-1]) dp[j]+=old[j-1], dp[j]%=mod;
    }
  }
  cout << dp[m] << endl;
  return 0;
}