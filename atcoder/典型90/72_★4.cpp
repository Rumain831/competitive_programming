#include<iostream>
#include<vector>
using namespace std;

//Tags: grid, 全探索, DFS
//解説URL: https://twitter.com/e869120/status/1407109731546636289

int main(void){
  int h, w; cin >> h >> w;
  vector<string> c(h);
  for(auto& x:c) cin >> x;
  int ans=-1;
  vector seen(h, vector<int>(w));
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  auto dfs=[&](auto dfs, int si, int sj, int nowi, int nowj, int path)->void {
    seen[nowi][nowj]=1;
    for(int k=0; k<4; k++){
      int ni=nowi+di[k], nj=nowj+dj[k];
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      if(ni==si&&nj==sj&&path>2){
        ans=max(ans, path);
        continue;
      }
      if(c[ni][nj]=='#'||seen[ni][nj]) continue;
      dfs(dfs, si, sj, ni, nj, path+1);
    }
    seen[nowi][nowj]=0;
    return;
  };
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    if(c[i][j]=='.') dfs(dfs, i, j, i, j, 1);
  }
  cout << ans << endl;
  return 0;
}