#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using ll = long long;
using tu = tuple<int, int, int>;

int main(void){
  int r, c; cin >> r >> c;
  int sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx;
  sy--, sx--, gy--, gx--;
  vector<string> grid(r);
  vector ans(r, vector<int>(c, -1));
  for(int i=0; i<r; i++) cin >> grid[i];
  queue<tu> bfs;
  bfs.emplace(0, sx, sy);
  int di[4]={0, 1, 0, -1};
  int dj[4]={-1, 0, 1, 0};
  while(!bfs.empty()){
    auto [d, i, j]=bfs.front(); bfs.pop();
    if(ans[i][j]!=-1) continue;
    ans[i][j]=d;
    for(int k=0; k<4; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(grid[ni][nj]!='#') bfs.emplace(d+1, ni, nj);
    }
  }
  cout << ans[gy][gx] << endl;
  return 0;
}