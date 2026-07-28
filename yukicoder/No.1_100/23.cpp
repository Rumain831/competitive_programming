#include<iostream>
#include<vector>
using namespace std;

//Tags: 期待値dp

int main(void){
  int h, a, d; cin >> h >> a >> d;
  vector<double> dp(h+1);
  for(int i=1; i<=h; i++){
    //x=2/3*(dp[i-d]+1)+1/3*(x+1)
    dp[i]=min(1.0+dp[max(0, i-a)], 1.5+dp[max(0, i-d)]);
  }
  printf("%.10f\n", dp[h]);
  return 0;
}