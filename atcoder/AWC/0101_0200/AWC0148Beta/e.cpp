#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
void chmin(ll& a, ll b){a=min(a, b);}

//Tags: bitDP

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<int> t(n);
  for(auto&x:t) cin >> x, x--;
  vector c(n+2, vector<ll>(n+2));
  for(int i=0; i<=n; i++){
    for(int j=i+1; j<=n+1; j++){
      cin >> c[i][j];
      c[j][i]=c[i][j];
    }
  }
  int mx=(1<<m);
  vector dp(n+1, vector(n+1, vector<ll>(mx, 1e18)));
  dp[0][0][0]=0;
  for(int i=0; i<n; i++)for(int j=1; j<=i+1; j++){
    for(int pre=0; pre<=i; pre++)for(int b=0; b<mx; b++){
      if(dp[pre][j-1][b]==1e18) continue;
      chmin(dp[i+1][j][b^(1<<t[i])], dp[pre][j-1][b]+c[pre][i+1]);
    }
  }
  ll ans=1e18;
  for(int i=0; i<=n; i++)for(int j=k; j<=n; j++){
    if(dp[i][j][0]==1e18) continue;
    chmin(ans, dp[i][j][0]+c[i][n+1]);
  }
  cout << (ans==1e18?-1:ans) << endl;
  return 0; 
}