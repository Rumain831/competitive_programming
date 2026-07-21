#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp, 木

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(m);
  for(int i=0; i<m; i++) cin >> a[i], a[i]--;
  vector<vector<pair<int, int>>> to(n);
  for(int i=0; i<n-1; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].emplace_back(v, i);
    to[v].emplace_back(u, i);
  }
  vector<int> cnt(n-1);
  auto dfs=[&](auto dfs, int tar, int now, vector<int>& edges, int par=-1){
    if(now==tar){
      for(auto p:edges) cnt[p]++;
      return;
    }
    for(auto [next, e]:to[now]){
      if(next==par) continue;
      edges.push_back(e);
      dfs(dfs, tar, next, edges, now);
      edges.pop_back();
    }
    return;
  };
  for(int i=0; i<m-1; i++){
    vector<int> emp;
    dfs(dfs, a[i+1], a[i], emp);
  }
  ll sum=0, mod=998244353;
  for(int i=0; i<n-1; i++) sum+=cnt[i];
  if(k+sum<0||sum-k<0||(k+sum)%2){
    cout << 0 << endl; return 0;
  }
  vector<ll> dp(2e5);
  dp[0]=1;
  for(int i=0; i<n-1; i++){
    vector<ll> old(2e5);
    swap(old, dp);
    for(int j=0; j<2e5; j++){
      if(old[j]) dp[j+cnt[i]]+=old[j], dp[j+cnt[i]]%=mod;
      dp[j]+=old[j]; dp[j]%=mod;
    }
  }
  cout << dp[(k+sum)/2]%mod << endl;
  return 0;
}