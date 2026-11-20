#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  int n, m; cin >> n >> m;
  vector c(n, vector<ll>(m+1, 2e9));
  for(int i=0; i<n; i++)for(int j=1; j<=m; j++) cin >> c[i][j];
  vector<ll> dp(m+1);
  for(int i=0; i<n; i++){
    vector<ll> old(m+1, 1e18);
    swap(old, dp);
    ll mi=1e18;
    for(int j=1; j<=m; j++){
      mi=min(mi, old[j]);
      dp[j]=min(dp[j], mi+c[i][j]);
    }
  }
  cout << *min_element(begin(dp), end(dp)) << endl;
  return 0; 
}