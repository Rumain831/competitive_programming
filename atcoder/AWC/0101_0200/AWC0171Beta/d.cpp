#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using qu = tuple<int, int, int, int>;

//Tags: BFS

int main(void){
  int h, w; cin >> h >> w;
  vector a(h, vector<int>(w));
  for(auto&x:a)for(auto&y:x) cin >> y;
  queue<qu> bfs;
  vector dist(2, vector(h, vector<int>(w, 1e9)));
  int di[2][2]={{0, 0}, {-1, 1}};
  int dj[2][2]={{-1, 1}, {0, 0}};
  bfs.emplace(0, 0, 0, 0);
  bfs.emplace(0, 0, 0, 1);
  dist[0][0][0]=dist[1][0][0]=0;
  while(bfs.size()){
    auto [d, i, j, t]=bfs.front(); bfs.pop();
    if(dist[t][i][j]!=d) continue;
    int nt=t^1;
    for(int k=0; k<2; k++){
      int ni=i+di[nt][k], nj=j+dj[nt][k];
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      if(a[ni][nj]) continue;
      int nd=d+1;
      if(dist[nt][ni][nj]>nd){
        dist[nt][ni][nj]=nd;
        bfs.emplace(nd, ni, nj, nt);
      }
    }
  }
  int ans=min(dist[0][h-1][w-1], dist[1][h-1][w-1]);
  if(ans==1e9) cout << "NONE" << endl;
  else cout << ans << endl;
  return 0; 
}