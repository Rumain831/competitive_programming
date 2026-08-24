#include<iostream>
#include<vector>
using namespace std;

//Tags: dp
//Level: 2.5

int main(void){
  int n; cin >> n;
  vector<int> w(n);
  int sum=0;
  for(int i=0; i<n; i++) cin >> w[i], sum+=w[i]; 
  if(sum%2){
    cout << "impossible" << endl; return 0;
  }
  vector<bool> dp(sum+1);
  dp[0]=true;
  for(int i=0; i<n; i++){
    vector<bool> old(sum+1);
    swap(old, dp);
    for(int j=0; j<=sum; j++)if(old[j]){
      dp[j]=true;
      if(j+w[i]<=sum) dp[j+w[i]]=true;
    }
  }
  cout << (dp[sum/2]?"possible":"impossible") << endl;
  return 0;
}