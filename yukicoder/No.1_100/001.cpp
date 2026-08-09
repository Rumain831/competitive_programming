#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using tu = tuple<int, int, int>;

//Tags: dp, DAG
//dp[i][x]=町iにコストxを払って辿り着くのにかかる最短時間

int main(void){
  int n, c, v; cin >> n >> c >> v;
  vector<int> s(v), t(v), y(v), m(v);
  for(auto&x:s) cin >> x, x--;
  for(auto&x:t) cin >> x, x--;
  for(auto&x:y) cin >> x;
  for(auto&x:m) cin >> x;
  vector<vector<tu>> to(n);
  for(int i=0; i<v; i++){
    to[s[i]].emplace_back(t[i], y[i], m[i]);
  }
  vector dp(n, vector<int>(c+1, 1e9));
  dp[0][0]=0;
  for(int i=0; i<n-1; i++){
    for(int j=0; j<=c; j++)if(dp[i][j]!=1e9){
      for(auto [v, cost, dt]:to[i]){
        int nc=j+cost;
        if(nc>c) continue;
        dp[v][nc]=min(dp[v][nc], dp[i][j]+dt);
      }
    }
  }
  int ans=*min_element(begin(dp[n-1]), end(dp[n-1]));
  cout << (ans==1e9?-1:ans) << endl;
  return 0; 
}