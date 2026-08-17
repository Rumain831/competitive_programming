#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  int n; cin >> n;
  vector<ll> p(n);
  for(auto&x:p) cin >> x;
  vector<ll> dp(n+1, -1e18);
  dp[0]=0;
  for(int i=0; i<n; i++){
    ll sum=0;
    for(int j=i; j>=0; j--){
      sum+=p[j];
      dp[i+1]=max(dp[i+1], dp[j]+sum*(i-j+1));
    }
  }
  cout << dp[n] << endl;
  return 0; 
}