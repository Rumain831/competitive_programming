#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  ll mod=998244353;
  vector dp(n, vector<ll>(10));
  dp[0][a[0]%10]=1;
  for(int i=0; i<n-1; i++){
    for(int j=0; j<10; j++){
      dp[i+1][(a[i+1]+j)%10]+=dp[i][j];
      dp[i+1][(a[i+1]+j)%10]%=mod;
      dp[i+1][(a[i+1]*j)%10]+=dp[i][j];
      dp[i+1][(a[i+1]*j)%10]%=mod;
    }
  }
  for(int i=0; i<10; i++) cout << dp[n-1][i] << endl;
  return 0;
}