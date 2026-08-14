#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp


ll dp[1001][1001];
int main(void){
  int n, m; cin >> n >> m;
  vector a(n, vector<ll>(m));
  for(auto&x:a)for(auto&y:x) cin >> y;
  dp[0][0]=a[0][0];
  for(int i=0; i<n; i++)for(int j=0; j<m; j++){
    if(i) dp[i][j]=max(dp[i][j], dp[i-1][j]+a[i][j]);
    if(j) dp[i][j]=max(dp[i][j], dp[i][j-1]+a[i][j]);
  }
  cout << dp[n-1][m-1] << endl;
  return 0; 
}