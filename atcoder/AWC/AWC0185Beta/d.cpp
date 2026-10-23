#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
void chmax(ll& a, ll b){a=max(a, b);}

//Tags: dp

int main(void){
  int n, k, c; cin >> n >> k >> c;
  vector dp(c+1, vector<ll>(k+1, -1e18));
  dp[0][0]=0;
  for(int i=0; i<n; i++){
    ll w, v; cin >> w >> v;
    vector old(c+1, vector<ll>(k+1, -1e18));
    swap(old, dp);
    for(int j=0; j<=c; j++)for(int p=0; p<=k; p++)if(old[j][p]>=0){
      chmax(dp[j][p], old[j][p]);
      int nw=j+w, np=p+1;
      if(nw<=c&&np<=k) chmax(dp[nw][np], old[j][p]+v);
    }
  }
  ll ans=0;
  for(int i=0; i<=c; i++) chmax(ans, *max_element(begin(dp[i]), end(dp[i])));
  cout << ans << endl;
  return 0; 
}