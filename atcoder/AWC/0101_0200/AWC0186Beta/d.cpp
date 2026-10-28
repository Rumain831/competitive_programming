#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: dp, 二分探索

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> x(n+1), r(m), c(m);
  for(int i=0; i<n; i++) cin >> x[i+1];
  x[0]=-1e18;
  sort(begin(x), end(x));
  for(int i=0; i<m; i++) cin >> r[i] >> c[i];
  vector<ll> dp(n+1, 1e18);
  dp[0]=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      ll y=lower_bound(begin(x), end(x), x[i+1]-r[j]*2)-begin(x); y--;
      dp[i+1]=min(dp[i+1], dp[y]+c[j]);
    }
  }
  cout << dp[n] << endl;
  return 0; 
}