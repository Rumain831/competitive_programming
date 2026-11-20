#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using qu = tuple<int, int, int, int>;

//Tags: grid, BFS
//解説URL: https://twitter.com/e869120/status/1394787605099601923

int main(void){
  int h, w; cin >> h >> w;
  int rs, cs, rt, ct; cin >> rs >> cs >> rt >> ct;
  rs--, cs--, rt--, ct--;
  vector<string> s(h);
  for(int i=0; i<h; i++) cin >> s[i];
  int dx[4]={0, 1, 0, -1};
  int dy[4]={-1, 0, 1, 0};
  vector dist(4, vector<vector<int>>(h, vector<int>(w, 1e9)));
  deque<qu> q;
  for(int k=0; k<4; k++){
    q.emplace_back(rs, cs, 0, k);
    dist[k][rs][cs]=0;
  }
  while(q.size()){
    auto [i, j, d, dir]=q.front(); q.pop_front();
    if(dist[dir][i][j]!=d) continue;
    for(int k=0; k<4; k++){
      int ni=i+dy[k], nj=j+dx[k];
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      if(s[ni][nj]=='#') continue;
      int nk=(k+2)%4, nd=d+(nk==dir?0:1);
      if(dist[nk][ni][nj]>nd){
        dist[nk][ni][nj]=nd;
        if(nk==dir) q.emplace_front(ni, nj, nd, nk);
        else q.emplace_back(ni, nj, nd, nk);
      }
    }
  }
  int ans=1e9;
  for(int k=0; k<4; k++) ans=min(ans, dist[k][rt][ct]);
  cout << ans << endl;
  return 0;
}