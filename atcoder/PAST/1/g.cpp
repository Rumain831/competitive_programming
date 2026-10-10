#include<iostream>
#include<vector>
using namespace std;

//Tags: 全探索, dfs

int main(void){
  int n; cin >> n;
  vector a(n, vector<int>(n));
  for(int i=0; i<n-1; i++)for(int j=i+1; j<n; j++){
    cin >> a[i][j];
    a[j][i]=a[i][j];
  }
  int ans=-1e9;
  auto dfs=[&](auto dfs, int step, vector<vector<int>>& gr)->void {
    if(step==n){
      int now=0;
      for(int i=0; i<3; i++){
        int m=gr[i].size();
        for(int j=0; j<m-1; j++)for(int k=j+1; k<m; k++) now+=a[gr[i][j]][gr[i][k]];
      }
      ans=max(ans, now);
      return;
    }
    for(int i=0; i<3; i++){
      gr[i].push_back(step);
      dfs(dfs, step+1, gr);
      gr[i].pop_back();
    }
    return;
  };
  vector<vector<int>> gr(3);
  dfs(dfs, 0, gr);
  cout << ans << endl;
  return 0;
}