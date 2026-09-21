#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<ll> h(n), add(n);
  for(auto&x:h) cin >> x;
  while(m--){
    int p, r; cin >> p >> r; p--;
    add[p]=r;
  }
  vector<ll> dp(n, -1e18);
  dp[0]=k-h[0];
  for(int i=0; i<n; i++){
    if(dp[i]<0) continue;
    dp[i]+=add[i];
    for(int j=1; j<=2; j++){
      int ni=i+j;
      if(ni>=n) continue;
      dp[ni]=max(dp[ni], dp[i]-h[ni]);
    }
  }
  cout << (dp[n-1]<0?-1:dp[n-1]) << endl;
  return 0; 
}