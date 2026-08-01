#include<iostream>
#include<vector>
using namespace std;

//Tags: 全探索, DFS

int main(void){
  int n; cin >> n;
  vector a(2*n, vector<int>(2*n));
  for(int i=0; i<2*n-1; i++){
    for(int j=i+1; j<2*n; j++){
      cin >> a[i][j];
      a[j][i]=a[i][j];
    }
  }
  int ans=-1;
  auto dfs=[&](auto dfs, int step, int now, vector<bool>& seen){
    if(step==n){
      ans=max(ans, now);
      return;
    }
    for(int i=0; i<2*n-1; i++){
      if(seen[i]) continue;
      seen[i]=true;
      for(int j=i+1; j<2*n; j++){
        if(seen[j]) continue;
        seen[j]=true;
        dfs(dfs, step+1, now^a[i][j], seen);
        seen[j]=false;
      }
      seen[i]=false;
      break;
    }
    return;
  };
  vector<bool> p(n);
  dfs(dfs, 0, 0, p);
  cout << ans << endl;
  return 0;
}