#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: DFS

int main(void){
  int n; cin >> n;
  vector<ll> t(n);
  vector<vector<int>> to(n);
  for(int i=0; i<n; i++){
    cin >> t[i];
    int k; cin >> k;
    for(int j=0; j<k; j++){
      int x; cin >> x; x--;
      to[i].push_back(x);
    }
  } 
  vector<ll> dp(n);
  auto dfs=[&](auto dfs, int now)->void {
    for(auto p:to[now])if(dp[p]==0){
      dfs(dfs, p);
      dp[now]+=dp[p];
    }
    dp[now]+=t[now];
  };
  dfs(dfs, n-1);
  cout << dp[n-1] << endl;
  return 0;
}