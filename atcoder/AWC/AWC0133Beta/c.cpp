#include<iostream>
#include<vector>
using namespace std;

//Tags: DFS, 木dp

int main(void){
  int n, k; cin >> n >> k; k--;
  vector<vector<int>> to(n);
  for(int i=1; i<n; i++){
    int p; cin >> p; p--;
    to[p].push_back(i);
  }
  vector<int> tr(n);
  auto dfs=[&](auto dfs, int now, int par=-1)->int {
    tr[now]++;
    for(auto p:to[now])if(p!=par){
      tr[now]+=dfs(dfs, p, now);
    }
    return tr[now];
  };
  dfs(dfs, 0);
  cout << n-tr[k] << endl;
  return 0; 
}