#include<iostream>
#include<vector>
using namespace std;

//Tags: dp, grid

int main(void){
  int h, w; cin >> h >> w;
  vector<string> c(h);
  for(auto&x:c) cin >> x;
  vector dp(h, vector<int>(w, -1));
  dp[0][0]=1;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++)if(c[i][j]=='.'){
    if(i&&c[i-1][j]=='.'&&dp[i-1][j]>0) dp[i][j]=max(dp[i][j], dp[i-1][j]+1);
    if(j&&c[i][j-1]=='.'&&dp[i][j-1]>0) dp[i][j]=max(dp[i][j], dp[i][j-1]+1);
  }
  int ans=0;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++) ans=max(ans, dp[i][j]);
  cout << ans << endl;
  return 0;
}