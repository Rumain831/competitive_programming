#include<iostream>
#include<vector>
using namespace std;

//Tags: 累積和, grid
//解説URL: https://twitter.com/e869120/status/1388262816101007363

int sum[1002][1002];
int main(void){
  int n; cin >> n;
  int m=1000;
  for(int i=0; i<n; i++){
    int lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
    sum[ly][lx]++, sum[ly][rx]--, sum[ry][lx]--, sum[ry][rx]++;
  }
  for(int i=0; i<=m; i++)for(int j=1; j<=m; j++) sum[i][j]+=sum[i][j-1];
  for(int j=0; j<=m; j++)for(int i=1; i<=m; i++) sum[i][j]+=sum[i-1][j];
  vector<int> ans(n+1);
  for(int i=0; i<=m; i++)for(int j=0; j<=m; j++) ans[sum[i][j]]++;
  for(int i=1; i<=n; i++) cout << ans[i] << '\n';
  return 0; 
}