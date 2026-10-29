#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
void chmax(ll& a, ll b){a=max(a, b);}

//Tags: dp

int main(void){
  int n, k, d; cin >> n >> k >> d;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector dp(n+1, vector<ll>(k+1, -1e18));
  vector mx(n+1, vector<ll>(k+1, -1e18));
  dp[0][0]=0;
  for(int i=0; i<=n; i++) mx[i][0]=0;
  for(int i=0; i<n; i++){
    for(int j=0; j<=min(i+1, k); j++){
      if(mx[i][j]>=0)chmax(dp[i+1][j], mx[i][j]);
      int r=max(0, i-d);
      if(j&&mx[r][j-1]>=0) chmax(dp[i+1][j], mx[r][j-1]+a[i]);
    }
    for(int j=0; j<=min(i+1, k); j++){
      chmax(mx[i+1][j], dp[i+1][j]);
      chmax(mx[i+1][j], mx[i][j]);
    }
  }
  cout << *max_element(begin(mx[n]), end(mx[n])) << endl;
  return 0; 
}