#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
using tu = tuple<int, int, int>;

int main(void){
  int h, w; cin >> h >> w;
  vector<string> s(h);
  for(auto&x:s) cin >> x;
  vector dist(h, vector<int>(w, 1e9));
  deque<tu> bfs;
  bfs.emplace_back(0, 0, 0);
  while(bfs.size()){
    auto [d, i, j]=bfs.front(); bfs.pop_front();
    if(dist[i][j]!=1e9) continue;
    dist[i][j]=d;
    for(int di=-2; di<=2; di++)for(int dj=-2; dj<=2; dj++){
      if(abs(di)==2&&abs(dj)==2) continue;
      int ni=i+di, nj=j+dj;
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      if(abs(di)+abs(dj)==1){
        if(s[ni][nj]=='.') bfs.emplace_front(d, ni, nj);
      }
      bfs.emplace_back(d+1, ni, nj);
    }
  }
  cout << dist[h-1][w-1] << endl;
  return 0; 
}