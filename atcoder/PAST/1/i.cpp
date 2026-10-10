#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: bitDP

void chmin(ll& a, ll b){a=min(a, b);}

int main(void){
  int n, m; cin >> n >> m;
  vector<int> sets(m), c(m);
  for(int i=0; i<m; i++){
    string s; cin >> s >> c[i];
    for(int j=0; j<n; j++){
      if(s[j]=='Y') sets[i]+=(1<<j);
    }
  }
  int mx=(1<<n);
  vector<ll> dp(mx, 1e18);
  dp[0]=0;
  for(int i=0; i<m; i++){
    vector<ll> old(mx, 1e18);
    swap(old, dp);
    for(int j=0; j<mx; j++){
      chmin(dp[j], old[j]);
      chmin(dp[(j|sets[i])], old[j]+c[i]);
    }
  }
  cout << (dp[mx]==1e18?-1:dp[mx]) << endl;
  return 0;
}