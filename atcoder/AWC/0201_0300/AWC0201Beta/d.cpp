#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  int n, k, x; cin >> n >> k >> x;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  vector dp(n+1, vector<ll>(x+1));
  ll mod=998244353;
  dp[0][0]=1;
  for(int i=0; i<n; i++){
    vector old(n+1, vector<ll>(x+1));
    swap(old, dp);
    for(int j=0; j<=i; j++)for(int p=0; p<=x; p++){
      dp[j][p]+=old[j][p], dp[j][p]%=mod;
      if(j+1<=n){
        dp[j+1][min(p+a[i], x)]+=old[j][p];
        dp[j+1][min(p+a[i], x)]%=mod;
      }
    }
  }
  cout << dp[n-k][x] << endl;
  return 0; 
}