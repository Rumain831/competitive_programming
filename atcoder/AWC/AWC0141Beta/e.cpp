#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
void chmin(ll& a, ll b){a=min(a, b);}

//Tags: bitDP

int main(void){
  int n; cin >> n;
  int mx=(1<<n);
  vector<ll> c(n);
  for(auto&x:c) cin >> x;
  vector w(n, vector<ll>(n));
  for(auto&x:w)for(auto&y:x) cin >> y;
  vector<ll> dp(mx, 1e18);
  dp[0]=0;
  for(int i=0; i<mx; i++){
    vector<ll> ad(n);
    for(int j=0; j<n; j++)if(i>>j&1){
      for(int k=0; k<n; k++) ad[k]+=w[j][k];
    }
    for(int j=0; j<n; j++)if(!(i>>j&1)){
      chmin(dp[i|(1<<j)], dp[i]+ad[j]+c[j]);
    }
  }
  cout << dp[mx-1] << endl;
  return 0; 
}