#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void chmin(ll& a, ll b){a=min(a, b);}

//Tags: bitDP, ダイクストラ法

int main(void){
  ll n, m, k, t; cin >> n >> m >> k >> t;
  vector<vector<P>> to(n);
  for(int i=0; i<m; i++){
    int u, v; ll w; cin >> u >> v >> w; u--, v--;
    to[u].emplace_back(v, w);
  }
  vector<int> tar;
  vector<int> s(k), p(k);
  vector<vector<int>> mission(k);
  for(int i=0; i<k; i++){
    cin >> s[i];
    for(int j=0; j<s[i]; j++){
      int x; cin >> x; x--;
      mission[i].push_back(x);
      tar.push_back(x);
    }
    cin >> p[i];
  }
  tar.push_back(0);
  sort(begin(tar), end(tar));
  tar.erase(unique(begin(tar), end(tar)), end(tar));
  vector<int> id(n, -1), bit(k);
  int q=tar.size(), mx=(1<<q);
  for(int i=0; i<q; i++) id[tar[i]]=i;
  for(int i=0; i<k; i++){
    for(auto&x:mission[i]) x=id[x], bit[i]|=(1<<x);
  }
  vector dist(q, vector<ll>(q, 1e18));
  auto Dij=[&](int st){
    vector<ll> Dist(n, 1e18);
    priority_queue<P, vector<P>, greater<P>> pri;
    pri.emplace(0, st);
    Dist[st]=0;
    while(pri.size()){
      auto [d, now]=pri.top(); pri.pop();
      if(Dist[now]!=d) continue;
      for(auto [v, dt]:to[now]){
        ll nd=d+dt;
        if(Dist[v]>nd){
          Dist[v]=nd;
          pri.emplace(nd, v);
        }
      }
    }
    int x=id[st];
    for(int i=0; i<q; i++) dist[x][id[tar[i]]]=Dist[tar[i]];
  };
  for(int i=0; i<q; i++) Dij(tar[i]);
  vector dp(mx, vector<ll>(q, 1e18));
  dp[1<<id[0]][id[0]]=0;
  for(int i=0; i<mx; i++)for(int j=0; j<q; j++)if(i>>j&1){
    for(int r=0; r<q; r++)if(!(i>>r&1)){
      chmin(dp[i|(1<<r)][r], dp[i][j]+dist[j][r]);
    }
  }
  ll ans=0;
  for(int i=0; i<mx; i++)for(int j=0; j<q; j++)if(dp[i][j]<=t){
    ll now=0;
    for(int kk=0; kk<k; kk++)if((i&bit[kk])==bit[kk]){
      now+=p[kk];
    }
    ans=max(ans, now);
  }
  cout << ans << endl;
  return 0; 
}