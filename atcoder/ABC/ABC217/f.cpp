#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 区間dp

int main(void){
  int n, m; cin >> n >> m;
  ll mod=998244353;
  vector good(2*n, vector<int>(2*n));
  vector comb(2*n+1, vector<ll>(2*n+1));
  for(int i=1; i<=2*n; i++)for(int j=0; j<=i; j++){
    if(j==0||j==i) comb[i][j]=1;
    else{
      comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
      comb[i][j]%=mod;
    }
  }
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b; a--, b--;
    good[a][b]=good[b][a]=1;
  }
  vector dp(2*n, vector<ll>(2*n));
  for(int i=0; i<2*n-1; i++) dp[i][i+1]=good[i][i+1];
  for(int i=1; i<2*n; i++)for(int j=0; j<i; j++) dp[i][j]=1;
  for(int k=2; k<=n; k++){
    for(int l=0; l+2*k-1<2*n; l++){
      int r=l+2*k-1;
      dp[l][r]+=dp[l+1][r-1]*good[l][r];
      dp[l][r]%=mod;
      for(int mm=l+1; mm+1<r; mm+=2){
        if(good[l][mm]==0) continue;
        ll d1=(mm+1-l)/2, d2=(r+1-mm-1)/2;
        dp[l][r]+=dp[l+1][mm-1]*dp[mm+1][r]%mod*comb[d1+d2][d1]%mod;
        dp[l][r]%=mod;
      }
    }
  }
  cout << dp[0][2*n-1] << endl;
  return 0;
}