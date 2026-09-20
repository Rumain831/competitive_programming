#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using tu = tuple<int, int, int>;

//Tags: 01BFS, BFS
//Level: 2

int main(void){
  int w, h; cin >> w >> h;
  vector<string> s(h);
  for(auto&x:s) cin >> x;
  deque<tu> bfs;
  vector dist(h, vector<int>(w, 1e9));
  for(int i=0; i<h; i++)for(int j=0; j<w; j++)if(bfs.empty()&&s[i][j]=='.'){
    bfs.emplace_front(0, i, j);
    dist[i][j]=0; break;
  }
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  while(bfs.size()){
    auto [d, i, j]=bfs.front(); bfs.pop_front();
    if(dist[i][j]!=d) continue;
    for(int k=0; k<4; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      int nd=d+(s[ni][nj]=='.'?0:1);
      if(dist[ni][nj]<=nd) continue;
      dist[ni][nj]=nd;
      if(s[ni][nj]=='.') bfs.emplace_front(nd, ni, nj);
      else bfs.emplace_back(nd, ni, nj);
    }
  }
  int ans=1e9;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    if(s[i][j]=='.'&&dist[i][j]>0) ans=min(ans, dist[i][j]);
  }
  cout << ans << endl;
  return 0; 
}