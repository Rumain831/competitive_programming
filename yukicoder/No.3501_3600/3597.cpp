#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: grid, クイーン, dp
//Level: 2.5

bool reach(ll sx, ll sy, ll tx, ll ty){
  ll dx=abs(sx-tx), dy=abs(sy-ty);
  return dx==0||dy==0||dx==dy;
}

int main(void){
  int h, w; cin >> h >> w;
  int sx, sy, n; cin >> sx >> sy >> n;
  vector<ll> x(n+1), y(n+1), c(n+1);
  for(int i=1; i<=n; i++) cin >> x[i] >> y[i] >> c[i];
  x[0]=sx, y[0]=sy;
  ll mx=0;
  vector<ll> dp(n+2, -1e18);
  dp[0]=0;
  for(int i=1; i<=n; i++){
    if(i>=2) dp[i]=mx+c[i];
    if(reach(x[i-1], y[i-1], x[i], y[i])) dp[i]=max(dp[i], dp[i-1]+c[i]);
    mx=max(mx, dp[i-1]);
  }
  cout << *max_element(begin(dp), end(dp)) << endl;
  return 0; 
}