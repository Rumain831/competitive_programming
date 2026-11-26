#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp, 平均値

int main(void){
  int n, a; cin >> n >> a;
  vector<int> x(n);
  for(auto&y:x) cin >> y;
  vector dp(n+1, vector<ll>(n*a+1));
  dp[0][0]=1;
  for(int i=0; i<n; i++){
    vector old(n+1, vector<ll>(n*a+1));
    swap(old, dp);
    for(int j=0; j<=n; j++)for(int k=0; k<=n*a; k++)if(old[j][k]){
      dp[j][k]+=old[j][k];
      if(k+x[i]<=n*a) dp[j+1][k+x[i]]+=old[j][k];  
    }
  }
  ll ans=0;
  for(int i=1; i<=n; i++) ans+=dp[i][i*a];
  cout << ans << endl;
  return 0; 
}