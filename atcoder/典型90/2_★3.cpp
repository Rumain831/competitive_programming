#include<iostream>
using namespace std;

//Tags: 全探索, 辞書順, 括弧列
//解説URL: https://twitter.com/e869120/status/1377391097836544001

int main(void){
  int n; cin >> n;
  string ans;
  auto dfs=[&](auto dfs, int step, int sum){
    if(step==n){
      if(sum==0) cout << ans << '\n';
      return;
    }
    if(sum<n/2){
      ans+='(';
      dfs(dfs, step+1, sum+1);
      ans.pop_back();
    }
    if(sum){
      ans+=')';
      dfs(dfs, step+1, sum-1);
      ans.pop_back();
    }
    return;
  };
  dfs(dfs, 0, 0);
  return 0; 
}