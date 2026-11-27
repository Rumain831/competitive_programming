#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: dp

int main(void){
  int n, m, x; cin >> n >> m >> x;
  ll mod=998244353;
  vector<ll> dp(m);
  dp[0]=1;
  for(int i=0; i<n; i++){
    int a, b; cin >> a >> b; a%=m, b%=m;
    vector<ll> old(m);
    swap(old, dp);
    for(int j=0; j<m; j++)if(old[j]){
      {
        int nj=(j+a)%m;
        dp[nj]+=old[j], dp[nj]%=mod;
      }
      {
        int nj=(j+m-b)%m; 
        dp[nj]+=old[j], dp[nj]%=mod;
      }
    }
  }
  cout << dp[x] << endl;
  return 0; 
}