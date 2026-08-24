#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: DP

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector<ll> dp(2, -1e18);
  dp[0]=0;
  for(int i=0; i<n; i++){
    vector<ll> old(2, -1e18);
    swap(old, dp);
    for(int j=0; j<2; j++)if(old[j]!=-1e18){
      dp[0]=max(dp[0], old[j]);
      dp[1]=max(dp[1], old[j]+a[i]-j*k);
    }
  }
  cout << max(dp[0], dp[1]) << endl;
  return 0; 
}