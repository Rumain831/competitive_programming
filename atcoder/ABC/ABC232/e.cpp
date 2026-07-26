#include<iostream>
using namespace std;
using ll = long long;

//Tags: dp, grid

int main(void){
  ll h, w, k; cin >> h >> w >> k;
  ll x1, y1, x2, y2, mod=998244353; cin >> x1 >> y1 >> x2 >> y2;
  ll dp[2][2]={{0, 0}, {0, 0}};
  dp[x1==x2][y1==y2]=1;
  while(k--){
    ll old[2][2]={{0, 0}, {0, 0}};
    swap(old, dp);
    dp[1][1]+=old[1][0]+old[0][1], dp[1][1]%=mod;
    dp[1][0]+=old[1][1]*(w-1)%mod+old[1][0]*(w-2)%mod+old[0][0], dp[1][0]%=mod;
    dp[0][1]+=old[1][1]*(h-1)%mod+old[0][1]*(h-2)%mod+old[0][0], dp[0][1]%=mod;
    dp[0][0]+=old[1][0]*(h-1)%mod+old[0][1]*(w-1)%mod+old[0][0]*(h+w-4)%mod, dp[0][0]%=mod;
  }
  cout << dp[1][1] << endl;
  return 0;
}