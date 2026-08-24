#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  int n, m; cin >> n >> m;
  vector po(n, vector<ll>(m));
  for(auto&x:po)for(auto&y:x) cin >> y;
  vector dp(m, vector<ll>(3));
  for(int i=0; i<m; i++) dp[i][1]=po[0][i];
  for(int i=0; i<n-1; i++){
    vector old(m, vector<ll>(3, -1e18));
    swap(old, dp);
    for(int j=0; j<m; j++)for(int d=0; d<3; d++)if(old[j][d]>=0){
      for(int k=-1; k<=1; k++){
        int nd=k+1, nj=j+k;
        if(d!=1&&nd==d) continue;
        if(nj<0||nj>=m) continue;
        dp[nj][nd]=max(dp[nj][nd], old[j][d]+po[i+1][nj]);
      }
    }
  }
  ll ans=0;
  for(int i=0; i<m; i++)for(int j=0; j<3; j++) ans=max(ans, dp[i][j]);
  cout << ans << endl;
  return 0; 
}