#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp, 部分列
//Level: 2

int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector<ll> dp(2, -1e18);
  for(int i=0; i<n; i++){
    vector<ll> old(2, -1e18);
    swap(old, dp);
    dp[0]=max(old[0], -a[i]);
    for(int j=0; j<2; j++)if(old[j]!=-1e18){
      dp[j]=max(dp[j], old[j]);
      dp[j^1]=max(dp[j^1], old[j]+(j==0?1ll:-1ll)*a[i]);
    }
  }
  cout << max(dp[0], dp[1]) << endl;
  return 0; 
}