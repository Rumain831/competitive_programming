#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: dp, 二部グラフ

int main(void){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) cin >> b[i];
  vector dp0(2, vector<ll>(n+1, 1e18));
  vector dp1(2, vector<ll>(n+1, 1e18));
  dp0[0][0]=a[0], dp1[1][0]=0;
  for(int i=1; i<n; i++){
    dp0[0][i]=min(dp0[0][i-1]+b[i-1], dp0[1][i-1])+a[i];
    dp0[1][i]=min(dp0[0][i-1], dp0[1][i-1]+b[i-1]);
    dp1[0][i]=min(dp1[0][i-1]+b[i-1], dp1[1][i-1])+a[i];
    dp1[1][i]=min(dp1[0][i-1], dp1[1][i-1]+b[i-1]);
  }
  ll w, x, y, z;
  w=dp0[0][n-1]+b[n-1]; //0-0
  x=dp0[1][n-1]; //1-0
  y=dp1[0][n-1]; //0-1
  z=dp1[1][n-1]+b[n-1]; //1-1
  cout << min({w, x, y, z}) << endl;
  return 0;
}