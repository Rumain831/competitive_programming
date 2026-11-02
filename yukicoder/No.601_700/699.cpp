#include<iostream>
#include<vector>
using namespace std;

//Tags: 全探索
//Level: 2.5

int main(void){
  int n; cin >> n;
  vector<int> a(n), used(n);
  for(auto&x:a) cin >> x;
  int ans=0, m=n/2;
  auto dfs=[&](auto dfs, int step, int now)->void {
    if(step==m){
      ans=max(ans, now);
      return;
    }
    for(int i=0; i<n; i++)if(used[i]==0){
      used[i]=1;
      for(int j=i+1; j<n; j++)if(used[j]==0){
        used[j]=1;
        dfs(dfs, step+1, now^(a[i]+a[j]));
        used[j]=0;
      }
      used[i]=0;
      break;
    }
  };
  dfs(dfs, 0, 0);
  cout << ans << endl;
  return 0; 
}