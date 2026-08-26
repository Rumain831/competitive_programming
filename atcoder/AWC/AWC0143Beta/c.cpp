#include<iostream>
#include<vector>
using namespace std;

//Tags: DFS

int main(void){
  int n, m; cin >> n >> m;
  vector<int> col(n);
  for(auto&x:col) cin >> x;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v);
  }
  vector<int> seen(n);
  auto dfs=[&](auto dfs, int now, int par=-1)->void {
    seen[now]=1;
    for(auto p:to[now])if(p!=par){
      if(seen[p]||col[now]==col[p]) continue;
      dfs(dfs, p, now);
    }
  };
  dfs(dfs, 0);
  int c=0;
  for(int i=0; i<n; i++)if(!seen[i]){
    c++;
    cout << i+1 << ' ';
  }
  if(c==0) cout << "COMPLETE" << endl;
  return 0; 
}