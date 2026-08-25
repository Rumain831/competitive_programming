#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
void chmin(double& a, double b){a=min(a, b);}

//Tags: bitDP
//Level: 3

int main(void){
  ll x0, y0; cin >> x0 >> y0;
  int n; cin >> n;
  int mx=(1<<(n+1));
  vector<ll> x(n+1), y(n+1);
  vector<double> w(n+1);
  x[0]=x0, y[0]=y0;
  for(int i=1; i<=n; i++) cin >> x[i] >> y[i] >> w[i];
  vector dp(mx, vector<double>(n+1, 1e18));
  dp[1][0]=0;
  auto dist=[&](int s, int t){
    ll ans=abs(x[s]-x[t])+abs(y[s]-y[t]);
    return ans;
  };
  for(int i=1; i<mx; i++){
    double sw=0;
    for(int j=0; j<=n; j++)if(!(i>>j&1)) sw+=w[j];
    for(int st=0; st<=n; st++)if(i>>st&1){
      for(int to=0; to<=n; to++)if(!(i>>to&1)){
        chmin(dp[i|(1<<to)][to], dp[i][st]+(sw+100.0)/120.0*dist(st, to)+w[to]);
      }
    }
  }
  double ans=1e18;
  for(int i=1; i<=n; i++) chmin(ans, dp[mx-1][i]+dist(i, 0)*100/120.0);
  printf("%.10f\n", ans);
  return 0; 
}