#include<iostream>
using namespace std;

//Tags: dp, 期待値
//Level: 2

double dp[21];
int main(void){
  int k; cin >> k;
  for(int i=k-1; i>=0; i--){
    for(int j=1; j<=6; j++){
      int ni=min(k, i+j);
      dp[i]+=(dp[ni]+1)/6.0;
    }
  }
  printf("%.10f\n", dp[0]);
  return 0; 
}