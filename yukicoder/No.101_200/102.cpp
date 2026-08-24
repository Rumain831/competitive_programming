#include<iostream>
using namespace std;

//Tags: ゲーム, dp
//Level: 3

int dp[14][14][14][14][53];
int seen[14][14][14][14][53];
int n[5];

int main(void){
  int sum=0;
  for(int i=0; i<4; i++) cin >> n[i], sum+=n[i];
  auto dfs=[&](auto dfs, int x[5]){
    if(seen[x[0]][x[1]][x[2]][x[3]][x[4]]) return dp[x[0]][x[1]][x[2]][x[3]][x[4]];
    seen[x[0]][x[1]][x[2]][x[3]][x[4]]=1;
    if(x[0]==0&&x[1]==0&&x[2]==0&&x[3]==0){
      return dp[x[0]][x[1]][x[2]][x[3]][x[4]]=x[4];
    }
    int ans=-1e9;
    int opp=sum-x[0]-x[1]-x[2]-x[3]-x[4];
    for(int i=0; i<4; i++){
      int nx[5]={x[0], x[1], x[2], x[3], x[4]};
      for(int j=1; j<=3; j++){
        if(nx[i]<j) continue;
        nx[i]-=j;
        int no=opp;
        if(nx[i]==0) no=opp/2;
        nx[4]=no;
        ans=max(ans, sum-dfs(dfs, nx));
        nx[i]+=j;
      }
    }
    return dp[x[0]][x[1]][x[2]][x[3]][x[4]]=ans;
  };
  int taro=dfs(dfs, n), jiro=sum-taro;
  if(taro==jiro) cout << "Draw" << endl;
  else cout << (taro>jiro?"Taro":"Jiro") << endl;
  return 0; 
}