#include<iostream>
#include<vector>
using namespace std;

//Tags: 閉路, DFS, BFS

int main(void){
  int w, h; cin >> w >> h;
  vector grid(h, vector<int>(w));
  vector seen(h, vector<bool>(w));
  for(int i=0; i<h; i++)for(int j=0; j<w; j++) cin >> grid[i][j];
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  auto dfs=[&](auto dfs, int nowi, int nowj, int prei=-1, int prej=-1){
    if(seen[nowi][nowj]) return true;
    int num=grid[nowi][nowj];
    seen[nowi][nowj]=true;
    for(int k=0; k<4; k++){
      int ni=nowi+di[k], nj=nowj+dj[k];
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      if(ni==prei&&nj==prej) continue;
      if(grid[ni][nj]==num){
        if(dfs(dfs, ni, nj, nowi, nowj)) return true;
      }
    }
    return false;
  };
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    if(seen[i][j]) continue;
    if(dfs(dfs, i, j)){
      cout << "possible" << endl; return 0;
    }
  }
  cout << "impossible" << endl;
  return 0;
}