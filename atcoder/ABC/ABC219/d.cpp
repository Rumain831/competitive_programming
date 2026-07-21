#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void chmin(int& a, int b){a=min(a, b);}

int main(){
  int n, x, y; cin >> n >> x >> y;
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i] >> b[i];
  vector dp(x+1, vector<int>(y+1, 1e9));
  dp[0][0]=0;
  for(int i=0; i<n; i++){
    vector old(x+1, vector<int>(y+1, 1e9));
    swap(old, dp);
    for(int j=0; j<=x; j++){
      for(int k=0; k<=y; k++){
        chmin(dp[j][k], old[j][k]);
        chmin(dp[min(x, j+a[i])][min(y, k+b[i])], old[j][k]+1);
      }
    }
  }
  cout << (dp[x][y]==1e9?-1:dp[x][y]) << endl;
  return 0;
}