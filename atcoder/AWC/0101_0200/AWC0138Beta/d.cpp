#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
void chmax(ll& a, ll b){a=max(a, b);}

//Tags: dp

int main(void){
  ll n, w, b; cin >> n >> w >> b;
  vector<ll> d(n), c(n);
  for(int i=0; i<n; i++) cin >> d[i] >> c[i];
  vector dp(w+1, vector<ll>(4, -1e18));
  dp[0][0]=0;
  for(int i=0; i<n; i++){
    vector old(w+1, vector<ll>(4, -1e18));
    swap(old, dp);
    for(int j=0; j<=w; j++)for(int k=0; k<4; k++)if(old[j][k]>=0){
      int base=(k<<1)&3;
      chmax(dp[j][base], old[j][k]);
      if(j+c[i]<=w){
        ll add=d[i];
        if(k==1) add+=b*2;
        else if(k&1) add+=b;
        chmax(dp[j+c[i]][base+1], old[j][k]+add);
      }
    }
  }
  ll ans=0;
  for(int i=0; i<=w; i++)for(int k=0; k<4; k++){
    chmax(ans, dp[i][k]);
  }
  cout << ans << endl;
  return 0; 
}