#include<iostream>
#include<vector>
using namespace std;

//Tags: dp, 復元, 辞書順

bool dp[101][1001][11];
int main(void){
  int n, d, k; cin >> n >> d >> k;
  vector<int> p(n);
  for(int i=0; i<n; i++) p[i]=n-i;
  dp[0][0][0]=true;
  for(int i=0; i<n; i++){
    for(int j=0; j<=d; j++)for(int l=0; l<=k; l++){
      dp[i+1][j][l]|=dp[i][j][l];
      if(l+1<=k&&j+p[i]<=d){
        dp[i+1][j+p[i]][l+1]|=dp[i][j][l];
      }
    }
  }
  vector<int> ans;
  int rem=d, pre=n;
  for(int i=k; i>0; i--){
    bool ok=false;
    for(int j=pre; j>=1; j--){
      if(dp[j][rem][i]&&rem-p[j-1]>=0&&dp[j-1][rem-p[j-1]][i-1]){
        ok=true;
        ans.push_back(p[j-1]);
        rem-=p[j-1];
        pre=j-1;
        break;
      }
    }
    if(!ok){
      cout << -1 << endl; return 0;
    }
  }
  for(auto p:ans) cout << p << ' '; cout << endl;
  return 0; 
}