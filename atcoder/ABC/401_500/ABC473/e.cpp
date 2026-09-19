#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

//Tags: dp, 部分列

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> a(n), sum(n+1);
  for(int i=0; i<n; i++){
    cin >> a[i];
    sum[i+1]=sum[i]+a[i], sum[i+1]%=k;
  }
  map<int, int> dp;
  dp[0]=0;
  int maxi=0;
  for(int i=0; i<n; i++){
    ll r=sum[i+1];
    int mx=0;
    if(dp.count(r)) mx=max(mx, dp[r]+1);
    dp[r]=max(mx, maxi);
    maxi=max(maxi, dp[r]);
  }
  cout << dp[sum[n]] << endl;
  return 0; 
}