#include<iostream>
#include<vector>
using namespace std;

//Tags: 木, 二部グラフ
//解説URL: https://twitter.com/e869120/status/1387538790017769474

int main(void){
  int n; cin >> n;
  vector<vector<int>> to(n);
  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b; a--, b--;
    to[a].push_back(b); swap(a, b);
    to[a].push_back(b);
  }
  vector<vector<int>> col(2);
  auto dfs=[&](auto dfs, int now, int c, int par=-1)->void {
    col[c].push_back(now+1);
    for(auto p:to[now])if(p!=par){
      dfs(dfs, p, c^1, now);
    }
  };
  dfs(dfs, 0, 0);
  if(col[0].size()<n/2) swap(col[0], col[1]);
  for(int i=0; i<n/2; i++) cout << col[0][i] << ' ';
  return 0; 
}