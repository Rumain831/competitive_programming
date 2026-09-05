#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
void chmax(ll& a, ll b){a=max(a, b);}

//Tags: dp
//Level: 2

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector dp(k+1, vector<ll>(2, -1e18));
  dp[0][0]=0;
  for(int i=0; i<n; i++){
    vector old(k+1, vector<ll>(2, -1e18));
    swap(old, dp);
    for(int j=0; j<=k; j++)for(int p=0; p<2; p++)if(old[j][p]!=-1e18){
      if(p==0){
        chmax(dp[j][0], old[j][p]);  
        if(j<k) chmax(dp[j+1][1], old[j][p]+a[i]);  
      }
      else chmax(dp[j][0], old[j][p]);
    }
  }
  ll ans=max(dp[k][0], dp[k][1]);
  if(ans==-1e18) cout << "Impossible" << endl;
  else cout << ans << endl;
  return 0; 
}