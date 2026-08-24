#include<iostream>
#include<vector>
using namespace std;

//Tags: 全探索, dp
//Level: 3

int main(void){
  int v[4];
  for(int i=0; i<4; i++) cin >> v[i];
  int m=30, ans=1e9;
  auto f=[&](int x, int y, int z){
    int inf=100;
    vector dp(m+1, inf);
    int l[3]={x, y, z};
    dp[0]=0;
    for(int i=0; i<3; i++){
      for(int j=0; j<=m; j++){
        if(j+l[i]<=m&&dp[j]!=inf){
          dp[j+l[i]]=min(dp[j+l[i]], dp[j]+1);
        }
      }
    }
    int res=0;
    for(int i=0; i<4; i++) res+=dp[v[i]];
    return res;
  };
  for(int i=1; i<=m-2; i++)for(int j=i+1; j<=m-1; j++)for(int k=j+1; k<=m; k++){
    ans=min(ans, f(i, j, k));
  }
  cout << ans << endl;
  return 0; 
}