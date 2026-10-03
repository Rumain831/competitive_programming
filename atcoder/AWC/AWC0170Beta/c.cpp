#include<iostream>
#include<vector>
using namespace std;

//Tags: dp

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  int sum=0;
  for(auto&x:a) cin >> x, sum+=x;
  vector<bool> dp(sum+1);
  dp[0]=true;
  for(int i=0; i<n; i++){
    vector<bool> old(sum+1);
    swap(old, dp);
    for(int j=0; j<=sum; j++)if(old[j]){
      dp[j]=true;
      if(j+a[i]<=sum) dp[j+a[i]]=true;
    }
  }
  int ans=1e9;
  for(int i=1; i<sum; i++)if(dp[i]) ans=min(ans, abs(i-(sum-i)));
  cout << ans << endl;
  return 0; 
}