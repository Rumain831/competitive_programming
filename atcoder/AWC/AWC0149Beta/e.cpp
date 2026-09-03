#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void chmin(ll& a, ll b){a=min(a, b);}

//Tags: bitDP, ダイクストラ法

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<vector<P>> to(n);
  for(int i=0; i<m; i++){
    int u, v; ll w; cin >> u >> v >> w; u--, v--;
    to[u].emplace_back(v, w); swap(u, v);
    to[u].emplace_back(v, w);
  }
  vector<int> c(k+1);
  for(int i=0; i<k; i++) cin >> c[i+1], c[i+1]--;
  vector<vector<ll>> dist;
  auto Dij=[&](int st){
    vector<ll> ans(n, 1e18);
    priority_queue<P, vector<P>, greater<P>> pri;
    pri.emplace(0, st);
    ans[st]=0;
    while(pri.size()){
      auto [d, id]=pri.top(); pri.pop();
      if(ans[id]!=d) continue;
      for(auto [v, w]:to[id]){
        ll nd=d+w;
        if(ans[v]>nd){
          ans[v]=nd;
          pri.emplace(nd, v);
        }
      }
    }
    dist.push_back(ans);
  };
  for(int i=0; i<k+1; i++) Dij(c[i]);
  int mx=(1<<(k+1)), kk=k+1;
  vector dp(mx, vector<ll>(kk, 1e18));
  dp[1][0]=0;
  for(int i=1; i<mx; i++)for(int j=0; j<kk; j++)if(i>>j&1){
    for(int to=0; to<kk; to++)if(!(i>>to&1)){
      chmin(dp[i|(1<<to)][to], dp[i][j]+dist[j][c[to]]);
    }
  }
  ll ans=1e18;
  for(int i=1; i<kk; i++) chmin(ans, dp[mx-1][i]+dist[i][n-1]);
  cout << ans << endl;
  return 0; 
}