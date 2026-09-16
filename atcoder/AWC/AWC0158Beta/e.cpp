#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> r(n), d(n);
  for(int i=0; i<n; i++) cin >> r[i] >> d[i];
  vector dp(k+1, vector<ll>(2, -1e18));
  dp[0][0]=0;
  for(int i=0; i<n; i++){
    vector old(k+1, vector<ll>(2, -1e18));
    swap(old, dp);
    for(int j=0; j<=k; j++)for(int p=0; p<2; p++)if(old[j][p]!=-1e18){
      dp[j][0]=max(dp[j][0], old[j][p]);
      if(j+1<=k){
        ll add=(p==0?r[i]:r[i]-min(d[i-1], d[i]));
        dp[j+1][1]=max(dp[j+1][1], old[j][p]+add);
      }
    }
  }
  cout << max(dp[k][0], dp[k][1]) << endl;
  return 0; 
}