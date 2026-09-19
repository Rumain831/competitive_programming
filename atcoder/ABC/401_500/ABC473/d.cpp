#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: DFS

int main(void){
  int n, k; cin >> n >> k;
  vector dp(n+1, vector<int>(k+1));
  dp[n][0]=1;
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<=k; j++){
      dp[i][j]|=dp[i+1][j];
      if(j+i+1<=k) dp[i][j+i+1]|=dp[i][j];
    }
  }
  vector<vector<int>> ok(n+1);
  for(int i=0; i<=n; i++){
    for(int j=0; j<=k; j++)if(dp[i][j]) ok[i].push_back(j);
  }
  vector<vector<int>> ans;
  auto dfs=[&](auto dfs, int step, int sum, vector<int>& now){
    if(step==n){
      if(sum==k) ans.push_back(now);
      return;
    }
    for(auto p:ok[step+1]){
      if(sum+p>k) break;
      int dif=k-sum-p;
      if(dif%(step+1)) continue;
      int i=dif/(step+1);
      now.push_back(i);
      int rem=k-(sum+i*(step+1));
      if(dp[step+1][rem]) dfs(dfs, step+1, sum+i*(step+1), now);
      now.pop_back();
    }
    return;
  };
  vector<int> emp;
  dfs(dfs, 0, 0, emp);
  reverse(begin(ans), end(ans));
  for(auto&x:ans){
    for(auto&y:x) cout << y << ' '; cout << '\n';
  }
  return 0; 
}