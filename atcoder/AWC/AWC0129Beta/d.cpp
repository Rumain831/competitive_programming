#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using tu = tuple<int, int, int>;

//Tags: 01BFS

int main(void){
  int h, w; cin >> h >> w;
  vector<string> s(h);
  int si, sj, gi, gj;
  for(int i=0; i<h; i++){
    cin >> s[i];
    for(int j=0; j<w; j++){
      if(s[i][j]=='S') si=i, sj=j, s[i][j]='O';
      else if(s[i][j]=='G') gi=i, gj=j, s[i][j]='O';
    }
  }
  vector dist(h, vector<int>(w, 1e9));
  deque<tu> bfs;
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  bfs.emplace_back(si, sj, 0);
  while(bfs.size()){
    auto [i, j, d]=bfs.front(); bfs.pop_front();
    if(dist[i][j]!=1e9) continue;
    dist[i][j]=d;
    for(int k=0; k<4; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      if(s[ni][nj]=='B') continue;
      if(s[ni][nj]=='O') bfs.emplace_front(ni, nj, d);
      else bfs.emplace_back(ni, nj, d+1);
    }
  }
  cout << (dist[gi][gj]==1e9?-1:dist[gi][gj]) << endl;
  return 0; 
}