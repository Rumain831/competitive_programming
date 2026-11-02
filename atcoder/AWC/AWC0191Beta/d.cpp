#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector dp(k+1, vector<ll>(2, -1e18));
  dp[0][0]=0;
  for(int i=0; i<n; i++){
    vector old(k+1, vector<ll>(2, -1e18));
    swap(old, dp);
    for(int j=0; j<=k; j++)for(int p=0; p<2; p++)if(old[j][p]>=0){
      dp[j][0]=max(dp[j][0], old[j][p]);
      if(j+1<=k&&p==0) dp[j+1][1]=max(dp[j+1][1], old[j][p]+a[i]);
    }
  }
  ll mx=-1e18;
  mx=max(dp[k][0], dp[k][1]);
  cout << mx << endl;
  return 0; 
}