#include<iostream>
#include<vector>
using namespace std;

//Tags: 二部グラフ
//Level: 1.5

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<int>> to(n);
  vector<int> col(n, -1);
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b; a--, b--;
    to[a].push_back(b); swap(a, b);
    to[a].push_back(b);
  }
  auto dfs=[&](auto dfs, int now, int c=0)->bool {
    col[now]=c;
    for(auto p:to[now]){
      if(col[p]==-1){
        if(!dfs(dfs, p, c^1)) return false;
      }
      else{
        if(col[p]==c) return false;
      }
    }
    return true;
  };
  for(int i=0; i<n; i++){
    if(col[i]!=-1) continue;
    if(!dfs(dfs, i)){
      cout << "No" << endl; return 0;
    }
  }
  cout << "Yes" << endl;
  return 0; 
}