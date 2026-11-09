#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
void chmax(ll& a, ll b){a=max(a, b);}

//Tags: dp

int main(void){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i] >> b[i];
  vector<ll> dp(2, -1e18);
  dp[0]=a[0], dp[1]=b[0];
  for(int i=1; i<n; i++){
    vector<ll> old(2, -1e18);
    swap(old, dp);
    chmax(dp[0], max(old[0], old[1])+a[i]);
    chmax(dp[1], old[0]+b[i]);
  }
  cout << max(dp[0], dp[1]) << endl;
  return 0; 
}