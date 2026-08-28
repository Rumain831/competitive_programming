#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  ll n, m, k; cin >> n >> m >> k;
  vector<ll> c(n), t(n), p(n);
  for(int i=0; i<n; i++) cin >> c[i] >> t[i] >> p[i];
  vector<ll> dp(k+1, -1e18);
  dp[0]=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<=k; j++){
      if(j+t[i]<=k&&dp[j]>=0) dp[j+t[i]]=max(dp[j+t[i]], dp[j]+p[i]-c[i]);
    }
  }
  ll mx=*max_element(begin(dp), end(dp));
  cout << mx*m << endl;
  return 0; 
}