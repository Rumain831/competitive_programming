#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: dp, 整数
//Level: 3

int main(void){
  int n; cin >> n;
  vector<vector<int>> d(3e5+5);
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  for(int i=1; i<=3e5; i++){
    int now=i+i;
    while(now<=3e5) d[now].push_back(i), now+=i;
  }
  vector<int> dp(3e5+10, -1e9);
  dp[1]=0;
  for(int i=0; i<n; i++){
    int mx=0;
    for(auto x:d[a[i]]) mx=max(mx, dp[x]);
    dp[a[i]]=mx+1;
  }
  cout << *max_element(begin(dp), end(dp)) << endl;
  return 0; 
}