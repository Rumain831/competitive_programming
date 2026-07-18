#include<iostream>
#include<vector>
using namespace std;

void chmax(int& a, int b){a=max(a, b);}

int main(void){
  int w, n, k; cin >> w >> n >> k;
  vector<int> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i] >> b[i];
  vector dp(k+1, vector<int>(w+1, -1));
  dp[0][0]=0;
  for(int i=0; i<n; i++){
    vector old(k+1, vector<int>(w+1));
    swap(old, dp);
    for(int j=0; j<=k; j++){
      for(int l=0; l<=w; l++){
        if(old[j][l]!=-1) chmax(dp[j][l], old[j][l]);
        if(j>=1&&l-a[i]>=0&&old[j-1][l-a[i]]!=-1) chmax(dp[j][l], old[j-1][l-a[i]]+b[i]);
      }
    }
  }
  int ans=0;
  for(int i=0; i<=k; i++)for(int j=0; j<=w; j++) chmax(ans, dp[i][j]);
  cout << ans << endl;
  return 0;
}