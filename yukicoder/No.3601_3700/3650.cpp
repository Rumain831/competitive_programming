#include<iostream>
#include<vector>
using namespace std;

//Tags: functional graph, サイクル検出
//Level: 2
//連結成分数が答え。UnionFindでも可。

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x, x--;;
  vector<int> col(n);
  int ans=0;
  auto dfs=[&](auto dfs, int now, vector<int>& path)->void {
    path.push_back(now);
    if(col[now]==0){
      col[now]=1;
      dfs(dfs, a[now], path);
    }
    else{
      if(col[now]==1) ans++;
      for(auto p:path) col[p]=2; return;
    }
  };
  for(int i=0; i<n; i++){
    if(col[i]) continue;
    vector<int> p;
    dfs(dfs, i, p);
  }
  cout << ans << endl;
  return 0; 
}