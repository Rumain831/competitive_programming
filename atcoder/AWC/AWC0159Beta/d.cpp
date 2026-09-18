#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 木dp

int main(void){
  int n; cin >> n;
  vector<ll> v(n), dp(n);
  ll sum=0;
  for(auto&x:v) cin >> x, sum+=x;
  vector<vector<int>> to(n);
  for(int i=1; i<n; i++){
    int p; cin >> p; p--;
    to[p].push_back(i);
  }
  auto dfs=[&](auto dfs, int now)->ll {
    for(auto p:to[now]){
      dp[now]+=dfs(dfs, p);
    }
    dp[now]+=v[now];
    return dp[now];
  };
  dfs(dfs, 0);
  ll mx=0;
  for(int i=1; i<n; i++) mx=max(mx, dp[i]);
  cout << sum-mx << endl;
  return 0; 
}