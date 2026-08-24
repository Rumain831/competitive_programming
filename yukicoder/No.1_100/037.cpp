#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: dp
//Level: 3

int main(void){
  int t, n; cin >> t >> n;
  vector<int> c(n), v(n);
  for(auto&x:c) cin >> x;
  for(auto&x:v) cin >> x;
  for(int i=0; i<n; i++){
    int nv=v[i]; nv/=2;
    while(nv){
      c.push_back(c[i]);
      v.push_back(nv);
      nv/=2;
    }
  }
  int m=c.size();
  vector<int> dp(t+1, -1e9);
  dp[0]=0;
  for(int i=0; i<m; i++){
    vector<int> old(t+1, -1e9);
    swap(old, dp);
    for(int j=0; j<=t; j++){
      dp[j]=max(dp[j], old[j]);
      if(old[j]>=0&&j+c[i]<=t){
        dp[j+c[i]]=max(dp[j+c[i]], old[j]+v[i]);
      }
    }
  }
  cout << *max_element(begin(dp), end(dp)) << endl;
  return 0; 
}