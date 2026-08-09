#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using qu = tuple<int, int, int, int>;

//Tags: BFS

int main(void){
  int n, v, sx, sy, gx, gy; 
  cin >> n >> v >> sx >> sy >> gx >> gy; sx--, sy--, gx--, gy--;
  vector l(n, vector<int>(n));
  vector dist(n, vector(n, vector<int>(v+1, 1e9)));
  for(auto&x:l)for(auto&y:x) cin >> y;
  queue<qu> bfs;
  bfs.emplace(v, 0, sy, sx);
  dist[sy][sx][v]=0;
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  while(bfs.size()){
    auto [hp, d, i, j]=bfs.front(); bfs.pop();
    if(dist[i][j][hp]!=d) continue;
    if(i==gy&&j==gx){
      cout << d << endl; return 0;
    }
    for(int k=0; k<4; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(ni<0||nj<0||ni>=n||nj>=n) continue;
      int nv=hp-l[ni][nj];
      if(nv<=0) continue;
      if(dist[ni][nj][nv]>d+1){
        dist[ni][nj][nv]=d+1;
        bfs.emplace(nv, d+1, ni, nj);
      }
    }
  }
  cout << -1 << endl;
  return 0; 
}