#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
void f(P& a, P b){
  if(a.first!=b.first) a=min(a, b);
  a=max(a, b);
}

//Tags: bitDP

int main(void){
  ll n, m; cin >> n >> m;
  vector<ll> w(n);
  for(auto&x:w) cin >> x;
  int mx=(1<<n);
  P inf=P(1e9, 0);
  vector<P> dp(mx, inf);
  dp[0]=P(0, 0);
  for(int i=0; i<mx; i++){
    for(int in=0; in<n; in++)if(!(i>>in&1)){
      auto [c, rem]=dp[i];
      if(rem>=w[in]) f(dp[i|(1<<in)], P(c, rem-w[in]));
      else f(dp[i|(1<<in)], P(c+1, m-w[in]));
    }
  }
  cout << dp[mx-1].first << endl;
  return 0; 
}