#include<iostream>
#include<vector>
using namespace std;

//Tags: dp
//Level: 2

int main(void){
  int n, m; cin >> n >> m;
  vector<int> u(n), t(m);
  for(auto&x:u) cin >> x;
  for(auto&x:t) cin >> x;
  int mx=1000*m;
  vector<bool> dp(mx+1);
  dp[0]=true;
  for(int i=0; i<m; i++){
    vector<bool> old(mx+1);
    swap(old, dp);
    for(int j=0; j<=mx; j++)if(old[j]){
      dp[j]=true;
      dp[j+t[i]]=true;
    }
  }
  int mmx=mx+1e5+1;
  vector<bool> all(mmx);
  for(int i=0; i<n; i++){
    for(int j=0; j<=mx; j++)if(dp[j]){
      all[j+u[i]]=true;
    }
  }
  int ans=0;
  for(int i=0; i<mmx; i++) ans+=all[i];
  cout << ans << endl;
  return 0; 
}