#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void chmax(ll& a, ll b){a=max(a, b);}

//Tags: dp

int main(void){
  int n, k, w; cin >> n >> k >> w;
  vector<vector<P>> good(k);
  for(int i=0; i<n; i++){
    int w, v, d; cin >> w >> v >> d; d--;
    good[d].emplace_back(v, w);
  }
  auto DP=[&](vector<P> a){
    vector<ll> dp(w+1, -1e18);
    dp[0]=0;
    int m=a.size();
    for(int i=0; i<m; i++){
      auto [nv, nw]=a[i];
      vector<ll> old(w+1, -1e18);
      swap(old, dp);
      for(int j=0; j<=w; j++)if(old[j]>=0){
        chmax(dp[j], old[j]);
        if(j+nw<=w) chmax(dp[j+nw], old[j]+nv);
      }
    }
    return dp;
  };
  vector<vector<ll>> dps(k);
  for(int i=0; i<k; i++) dps[i]=DP(good[i]);
  vector dp(k+1, vector<ll>(w+1, -1e18));
  dp[0][0]=0;
  for(int i=0; i<k; i++){
    vector old(k+1, vector<ll>(w+1, -1e18));
    swap(old, dp);
    for(int pk=0; pk<=k; pk++)for(int pj=0; pj<=w; pj++)if(old[pk][pj]>-1e18){
      chmax(dp[pk][pj], old[pk][pj]);
      for(int nj=1; nj<=w; nj++){
        if(pk+1<=k&&pj+nj<=w&&dps[i][nj]>=0) chmax(dp[pk+1][pj+nj], old[pk][pj]+dps[i][nj]);
      }
    }
  }
  ll ans=0;
  for(int i=0; i<=k; i++)for(int j=0; j<=w; j++) chmax(ans, dp[i][j]-i*i);
  cout << ans << endl;
  return 0; 
}