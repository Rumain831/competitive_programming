#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: bitDP
//Level: 3

int main(void){
  int n; cin >> n;
  vector<int> d(n);
  for(auto&x:d) cin >> x;
  int mx=(1<<n);
  vector dp(mx, vector<int>(n+1, -1));
  dp[0][0]=100;
  for(int i=0; i<mx; i++)for(int j=0; j<n; j++)if(dp[i][j]>=0){
    for(int k=0; k<n; k++)if(!(i>>k&1)){
      int hp=dp[i][j], nj=j;
      if(d[k]>0) hp=min(100*(j+1), hp+d[k]);
      else{
        if(hp+d[k]<=0) continue;
        hp+=d[k]; nj++;
      }
      dp[i|(1<<k)][nj]=max(dp[i|(1<<k)][nj], hp);
    }
  }
  int ans=*max_element(begin(dp[mx-1]), end(dp[mx-1]));
  cout << max(0, ans) << endl;
  return 0; 
}