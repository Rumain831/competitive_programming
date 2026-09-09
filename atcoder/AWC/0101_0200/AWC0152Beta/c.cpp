#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for(auto&x:a) cin >> x, x%=k;
  vector<ll> dp(k);
  dp[0]=1;
  ll mod=998244353;
  for(int i=0; i<n; i++){
    vector<ll> old(k);
    swap(old, dp);
    for(int j=0; j<k; j++){
      dp[j]+=old[j], dp[j]%=mod;
      dp[(j+a[i])%k]+=old[j];
      dp[(j+a[i])%k]%=mod;
    }
  }
  cout << dp[0]-1 << endl;
  return 0; 
}