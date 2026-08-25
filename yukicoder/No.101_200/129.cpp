#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 場合の数
//Level: 2.5

int main(void){
  ll n, m; cin >> n >> m;
  ll rem=n-n/m/1000*m*1000, mod=1e9; rem=rem/1000;
  vector<ll> dp(m+1);
  for(int i=0; i<=m; i++){
    vector<ll> old(m+1);
    swap(old, dp);
    for(int j=0; j<=i; j++){
      if(j==0||j==i) dp[j]=1;
      else dp[j]=old[j-1]+old[j], dp[j]%=mod;
    }
  }
  cout << dp[rem] << endl;
  return 0; 
}