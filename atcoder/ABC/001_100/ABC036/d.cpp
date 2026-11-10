#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 木dp

int main(void){
  int n; cin >> n;
  vector<vector<int>> to(n);
  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b; a--, b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector dp(n, vector<ll>(2));
  ll mod=1e9+7;
  auto dfs=[&](auto dfs, int now, int par=-1)->void {
    dp[now][0]=dp[now][1]=1;
    for(auto p:to[now])if(p!=par){
      vector<ll> old(2);
      swap(old, dp[now]);
      dfs(dfs, p, now);
      for(int c=0; c<2; c++)for(int nc=0; nc<2; nc++){
        if(c&&nc) continue;
        dp[now][c]+=dp[p][nc]*old[c], dp[now][c]%=mod;
      }
    }
    return;
  };
  dfs(dfs, 0);
  cout << (dp[0][0]+dp[0][1])%mod << endl;
  return 0;
}
