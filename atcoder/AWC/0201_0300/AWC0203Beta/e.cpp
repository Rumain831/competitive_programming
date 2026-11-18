#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 木dp

int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector<vector<int>> to(n);
  for(int i=0; i<n-1; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); swap(u, v);
    to[u].push_back(v);
  }
  vector dp(n, vector<ll>(4, 1e18));
  auto dfs=[&](auto dfs, int now, int par=-1)->void {
    vector<ll> m(3);
    ll sum0=0, mi=1e18;
    for(auto p:to[now])if(p!=par){
      dfs(dfs, p, now);
      m[0]+=min({dp[p][0], dp[p][1], dp[p][2], dp[p][3]});
      m[1]+=dp[p][0];
      m[2]+=min(dp[p][0], dp[p][1]);
      sum0+=dp[p][0];
      mi=min(mi, dp[p][2]-dp[p][0]);
    }
    dp[now][0]=min(dp[now][0], m[0]+a[now]);
    dp[now][1]=min(dp[now][1], m[1]);
    dp[now][2]=min(dp[now][2], m[2]);
    dp[now][3]=min(dp[now][3], sum0+mi);
  };
  dfs(dfs, 0);
  cout << min({dp[0][0], dp[0][1], dp[0][2], dp[0][3]}) << endl;
  return 0; 
}