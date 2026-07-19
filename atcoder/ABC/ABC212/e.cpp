#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> cant(n);
  ll mod=998244353;
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    cant[u].push_back(v);
    cant[v].push_back(u);
  }
  for(int i=0; i<n; i++) cant[i].push_back(i);
  vector dp(k+1, vector<ll>(n));
  dp[0][0]=1;
  for(int i=1; i<=k; i++){
    ll sum=0;
    for(int j=0; j<n; j++){
      sum+=dp[i-1][j]; sum%=mod;
    }
    for(int j=0; j<n; j++){
      dp[i][j]+=sum; dp[i][j]%=mod;
      for(auto p:cant[j]){
        dp[i][j]+=mod-dp[i-1][p];
        dp[i][j]%=mod;
      }
    }
  }
  cout << dp[k][0] << endl;
  return 0;
}