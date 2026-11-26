#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 木dp

int main(void){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i] >> b[i];
  vector<vector<P>> to(n);
  for(int i=0; i<n-1; i++){
    int u, v; ll c; cin >> u >> v >> c; u--, v--;
    to[u].emplace_back(v, c); swap(u, v);
    to[u].emplace_back(v, c);
  }
  vector dp(n, vector<ll>(2));
  auto dfs=[&](auto dfs, int now, int par=-1)->void {
    for(auto [p, c]:to[now])if(p!=par){
      dfs(dfs, p, now);
      dp[now][0]+=min(dp[p][0], dp[p][1]+c);
      dp[now][1]+=min(dp[p][0]+c, dp[p][1]);
    }
    dp[now][0]+=a[now], dp[now][1]+=b[now];
  };
  dfs(dfs, 0);
  cout << min(dp[0][0], dp[0][1]) << endl;
  return 0; 
}