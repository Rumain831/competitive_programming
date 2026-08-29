#include<iostream>
#include<vector>
using namespace std;
void chmax(int& a, int b){a=max(a, b);}

//Tags: dp, 復元, 辞書順
//Level: 3

int main(void){
  int n, W; cin >> n >> W;
  vector<int> v(n), w(n);
  for(auto&x:v) cin >> x;
  for(auto&x:w) cin >> x;
  vector dp(n+1, vector<int>(W+1));
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<=W; j++){
      chmax(dp[i][j], dp[i+1][j]);
      if(j>=w[i]&&dp[i+1][j-w[i]]>=0){
        chmax(dp[i][j], dp[i+1][j-w[i]]+v[i]);
      }
    }
  }
  int mv=dp[0][W], nw=W;
  vector<int> ans;
  for(int i=0; i<n; i++){
    if(dp[i][nw]==dp[i+1][nw]) continue;
    ans.push_back(i+1);
    nw-=w[i];
  }
  cout << ans.size() << endl;
  for(auto p:ans) cout << p << ' '; cout << endl;
  return 0; 
}