#include<iostream>
using namespace std;

//Tags: 全探索, DFS

int main(void){
  int n; cin >> n;
  string t="abc";
  auto dfs=[&](auto dfs, int step, string s)->void {
    if(step==n){
      cout << s << endl; return;
    }
    for(int i=0; i<3; i++){
      dfs(dfs, step+1, s+t[i]);
    }
    return;
  };
  dfs(dfs, 0, "");
  return 0; 
}