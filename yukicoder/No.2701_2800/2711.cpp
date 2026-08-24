#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 数え上げ, dp
//Level: 2

int main(void){
  int n, m, k; cin >> n >> m >> k;
  int mx=(1<<n);
  ll mod=998244353;
  vector<ll> dp(mx, 1);
  for(int i=0; i<m-1; i++){
    vector<ll> old(mx);
    swap(old, dp);
    for(int p=0; p<mx; p++)for(int q=0; q<mx; q++){
      int x=__builtin_popcount(p&q);
      if(x>=k) dp[q]+=old[p], dp[q]%=mod;
    }
  }
  ll ans=0;
  for(auto&x:dp) ans+=x, ans%=mod;
  cout << ans << endl;
  return 0;
}