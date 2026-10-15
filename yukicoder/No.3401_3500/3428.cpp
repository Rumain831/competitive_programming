#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: grid, 回文, 全探索
//Level: 2

int main(void){
  int n; cin >> n;
  vector<string> c(n);
  for(auto&x:c) cin >> x;
  string emp;
  int di[2]={0, 1};
  int dj[2]={1, 0};
  int ans=0;
  auto dfs=[&](auto dfs, int i, int j, string& s){
    s+=c[i][j];
    if(i==n-1&&j==n-1){
      string t=s;
      reverse(begin(t), end(t));
      if(s==t) ans++;
      s.pop_back();
      return;
    }
    for(int k=0; k<2; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(ni>=n||nj>=n) continue;
      dfs(dfs, ni, nj, s);
    }
    s.pop_back();
    return;
  };
  dfs(dfs, 0, 0, emp);
  cout << ans << endl;
  return 0; 
}