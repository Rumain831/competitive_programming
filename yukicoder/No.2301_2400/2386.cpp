#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: dp
//Level: 2

int main(void){
  int n, a, b, c; cin >> n >> a >> b >> c;
  vector<int> dp(n+1, -1e9);
  dp[0]=0;
  for(int i=0; i<n; i++)if(dp[i]>=0){
    if(i+3<=n) dp[i+3]=max(dp[i+3], dp[i]+a);
    if(i+5<=n) dp[i+5]=max(dp[i+5], dp[i]+b);
    if(i+10<=n) dp[i+10]=max(dp[i+10], dp[i]+c);
  }
  cout << *max_element(begin(dp), end(dp)) << endl;
  return 0; 
}