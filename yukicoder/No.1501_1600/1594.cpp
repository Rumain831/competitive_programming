#include<iostream>
#include<vector>
using namespace std;

//Tags: 全探索, DFS
//Level: 2

int main(void){
  int n; cin >> n;
  vector<int> e(n);
  for(auto&x:e) cin >> x;
  auto dfs=[&](auto dfs, int step, vector<int>& cl){
    if(step==n){
      if(cl[0]==cl[1]&&cl[1]==cl[2]) return true;
      else return false;
    }
    for(int i=0; i<3; i++){
      cl[i]+=e[step];
      if(dfs(dfs, step+1, cl)) return true;
      cl[i]-=e[step];
    }
    return false;
  };
  vector<int> p(3);
  cout << (dfs(dfs, 0, p)?"Yes":"No") << endl;
  return 0; 
}