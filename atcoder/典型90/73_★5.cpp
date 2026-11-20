#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 木dp
//解説URL: https://twitter.com/e869120/status/1407510677934149635

int main(void){
  int n; cin >> n;
  ll mod=1e9+7;
  vector<int> c(n);
  for(int i=0; i<n; i++){
    char a; cin >> a;
    c[i]=a-'a'+1;
  }
  vector<vector<int>> to(n);
  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b; a--, b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector dp(n, vector<ll>(4));
  auto dfs=[&](auto dfs, int now, int par=-1)->void {
    dp[now][c[now]]=1;
    for(auto p:to[now])if(p!=par){
      dfs(dfs, p, now);
      vector<ll> nxt(4);
      for(int i=1; i<4; i++)for(int j=1; j<4; j++){
        nxt[i|j]+=(dp[now][i]*dp[p][j])%mod;
        nxt[i|j]%=mod;
      }
      for(int i=1; i<4; i++) nxt[i]+=dp[now][i]*dp[p][3], nxt[i]%=mod; 
      swap(nxt, dp[now]);
    }
  };
  dfs(dfs, 0);
  cout << dp[0][3] << endl;
  return 0;
}
