#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(void){
  int n, m; cin >> n >> m;
  ll s, t; cin >> s >> t; s--, t--;
  vector<ll> p(m+2);
  p[0]=s, p[m+1]=t;
  for(int i=1; i<=m; i++) cin >> p[i], p[i]--;
  auto ij=[&](ll k){
    ll i=k/n, j=k%n;
    return P(i, j);
  };
  int mx=(1<<(m+2));
  vector dp(mx, vector<ll>(m+2, 1e18));
  dp[1][0]=0;
  for(int i=1; i<mx; i++){
    for(int j=0; j<m+2; j++)if(i>>j&1){
      for(int to=0; to<m+2; to++)if(!(i>>to&1)){
        auto [fi, fj]=ij(p[j]);
        auto [ti, tj]=ij(p[to]);
        ll cost=abs(fi-ti)+abs(fj-tj);
        ll nxt=i|(1<<to);
        dp[nxt][to]=min(dp[nxt][to], dp[i][j]+cost);
      }
    }
  }
  cout << dp[mx-1][m+1] << endl;
  return 0;
}