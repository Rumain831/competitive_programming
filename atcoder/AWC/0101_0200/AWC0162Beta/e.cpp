#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void chmin(ll& a, ll b){a=min(a, b);}

//Tags: bitDP

int main(void){
  ll n, m, t; cin >> n >> m >> t;
  vector<ll> s(n);
  for(auto&x:s) cin >> x;
  vector<vector<P>> to(n);
  for(int i=0; i<m; i++){
    int u, v; ll w; cin >> u >> v >> w;
    to[u].emplace_back(v, w);
  }
  int mx=(1<<n);
  vector dp(mx, vector<ll>(n, 1e18));
  dp[1][0]=0;
  for(int i=1; i<mx; i++){
    for(int j=0; j<n; j++)if(i>>j&1){
      for(auto [v, w]:to[j])if(!(i>>v&1)){
        chmin(dp[i|(1<<v)][v], dp[i][j]+w);
      }
    }
  }
  ll ans=1e18;
  for(int i=1; i<mx; i++)if((i&1)&&((i>>(n-1))&1)){
    ll now=1;
    bool zero=false;
    for(int j=0; j<n; j++)if(i>>j&1){
      if(s[j]==0){zero=true; break;}
    }
    if(zero) continue;
    for(int j=0; j<n; j++)if(i>>j&1){
      if(now>t/s[j]){
        now=t+1; break;
      }
      now*=s[j];
      if(now>=t) break;
    }
    if(now>=t) ans=min(ans, dp[i][n-1]);
  }
  cout << (ans==1e18?-1:ans) << endl;
  return 0; 
}