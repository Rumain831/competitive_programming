#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp
//Level: 1.5

ll dp[10][10][102];
int main(void){
  int h, w; cin >> h >> w;
  vector<string> s(h);
  for(auto&x:s) cin >> x;
  dp[0][0][1]=1;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    if(i==0&&j==0) continue;
    if(s[i][j]=='#') continue;
    for(int d=0; d<=100; d++){
      int nd=d+(s[i][j]=='o'?1:-1);
      if(nd<0) continue;
      if(i&&s[i-1][j]!='#') dp[i][j][nd]+=dp[i-1][j][d];
      if(j&&s[i][j-1]!='#') dp[i][j][nd]+=dp[i][j-1][d];
    }
  }
  ll ans=0;
  for(int i=0; i<=100; i++) ans+=dp[h-1][w-1][i];
  cout << ans << endl;
  return 0; 
}