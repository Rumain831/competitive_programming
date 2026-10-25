#include<iostream>
#include<vector>
using namespace std;

//Tags: 木dp

int main(void){
  int n; cin >> n;
  vector<vector<int>> to(n);
  for(int i=0; i<n-1; i++){
    int b; cin >> b; b--;
    to[i+1].push_back(b);
    to[b].push_back(i+1);
  }
  vector<int> ans(n);
  auto dfs=[&](auto dfs, int u, int par=-1)->int {
    int mini=1e9, maxi=-1;
    for(auto p:to[u])if(p!=par){
      int k=dfs(dfs, p, u);
      mini=min(mini, k);
      maxi=max(maxi, k);
    }
    if(maxi==-1) return ans[u]=1;
    else return ans[u]=mini+maxi+1;
  };
  cout << dfs(dfs, 0) << endl;
  return 0;
}