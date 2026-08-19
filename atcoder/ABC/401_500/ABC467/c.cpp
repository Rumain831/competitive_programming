#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  vector<int> a(n), b(n-1);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  int dp[2]={n+10, n+10};
  dp[a[0]]=0, dp[a[0]^1]=1;
  for(int i=0; i<n-1; i++){
    int old[2]={n+10, n+10};
    swap(old, dp);
    for(int p=0; p<2; p++)for(int q=0; q<2; q++){
      if((p+q)%m!=b[i]) continue;
      int add=(q==a[i+1]?0:1);
      dp[q]=min(dp[q], old[p]+add);
    }
  }
  cout << min(dp[0], dp[1]) << endl;
  return 0; 
}