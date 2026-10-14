#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp, 括弧列

int main(void){
  int n; cin >> n;
  string s; cin >> s;
  vector<ll> c(n), d(n);
  for(auto&x:c) cin >> x;
  for(auto&x:d) cin >> x;
  vector dp(n+1, vector<ll>(n+1, 1e18));
  dp[0][0]=0;
  for(int i=0; i<n; i++)for(int j=0; j<=i; j++){
    dp[i+1][j]=min(dp[i+1][j], dp[i][j]+d[i]);
    if(j+1<=n){//'('
      int nj=j+1;
      ll cost=(s[i]=='('?0:c[i]);
      dp[i+1][nj]=min(dp[i+1][nj], dp[i][j]+cost);
    }
    if(j){//'('
      int nj=j-1;
      ll cost=(s[i]==')'?0:c[i]);
      dp[i+1][nj]=min(dp[i+1][nj], dp[i][j]+cost);
    } 
  }
  cout << dp[n][0] << endl;
  return 0; 
}