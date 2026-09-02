#include<iostream>
#include<vector>
using namespace std;

//Tags: dp

int main(void){
  int n, t, s; cin >> n >> t >> s;
  vector<int> c(n), p(n);
  for(int i=0; i<n; i++) cin >> c[i] >> p[i];
  vector<int> dp(t+1);
  for(int i=0; i<n; i++){
    for(int j=t; j>=0; j--){
      if(j+c[i]<=t){
        dp[j+c[i]]=max(dp[j+c[i]], dp[j]+p[i]);
      }
    }
  }
  cout << dp[t-s] << endl;
  return 0; 
}