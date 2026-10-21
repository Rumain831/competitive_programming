#include<iostream>
#include<set>
using namespace std;
using P = pair<int, int>;

//Tags: 全探索, チェス
//Level: 1.5

int main(void){
  int x, y; cin >> x >> y;
  int di[9]={-2, -2, -1, -1, 1, 1, 2, 2, 0};
  int dj[9]={-1, 1, -2, 2, -2, 2, -1, 1, 0};
  set<P> co;
  auto dfs=[&](auto dfs, int step, int ni, int nj)->void {
    if(step==3){
      co.emplace(ni, nj); return;
    }
    for(int k=0; k<9; k++){
      dfs(dfs, step+1, ni+di[k], nj+dj[k]);
    }
    return;
  };
  dfs(dfs, 0, 0, 0);
  cout << (co.count(P(x, y))?"YES":"NO") << endl;
  return 0; 
}