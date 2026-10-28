#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  ll n, c; cin >> n >> c;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector dp(n+1, vector<ll>(2, -1e18));
  dp[0][0]=0;
  for(int i=0; i<n; i++){
    for(int p=0; p<2; p++)for(int q=0; q<2; q++){
      ll x=dp[i][p]+(p==1&&q==1?c:0)+(q==1?a[i]:0);
      dp[i+1][q]=max(dp[i+1][q], x);
    }
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
  return 0; 
}