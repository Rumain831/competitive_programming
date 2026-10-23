#include<iostream>
#include<vector>
using namespace std;

//Tags: 確率, dp
//Level: 2.5

int main(void){
  int n; cin >> n;
  vector<double> dp(7);
  dp[0]=1;
  for(int i=0; i<n; i++){
    vector<double> old(7);
    swap(old, dp);
    for(int j=0; j<7; j++){
      double p=(6-j)/6.0, q=1-p;
      dp[j]+=old[j]*q;
      if(j+1<=6) dp[j+1]+=old[j]*p;
    }
  }
  printf("%.10f\n", dp[6]);
  return 0; 
}