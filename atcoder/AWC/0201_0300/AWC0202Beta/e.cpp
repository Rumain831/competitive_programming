#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: bitDP

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector<int> r(k+2, 1), c(k+2, 1);
  for(int i=0; i<k; i++) cin >> r[i+1] >> c[i+1];
  int mx=(1<<(k+2));
  vector dp(mx, vector<ll>(k+2, 1e18));
  dp[1][0]=0;
  for(int i=0; i<mx; i++)for(int st=0; st<k+2; st++)if(i>>st&1){
    for(int to=0; to<k+2; to++)if(!(i>>to&1)){
      ll d=abs(r[st]-r[to])+abs(c[st]-c[to]);
      int ni=(i|(1<<to));
      dp[ni][to]=min(dp[ni][to], dp[i][st]+d);
    }
  }
  cout << dp[mx-1][k+1] << endl;
  return 0; 
}