#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using tu = tuple<int, int, int>;

//Tags: BFS

int main(void){
  int h, w, K; cin >> h >> w >> K;
  vector<string> s(h);
  vector<int> bt(h), bw(w);
  for(int i=0; i<h; i++){
    cin >> s[i];
    for(int j=0; j<w; j++)if(s[i][j]=='#'){
      bt[i]++, bw[j]++;
    }
  }
  vector dist(h, vector<int>(w, 1e9));
  queue<tu> bfs;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    if(bt[i]==0&&bw[j]==0) bfs.emplace(0, i, j);
  }
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  while(bfs.size()){
    auto [d, i, j]=bfs.front(); bfs.pop();
    if(dist[i][j]!=1e9) continue;
    dist[i][j]=d;
    for(int k=0; k<4; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(ni<0|nj<0||ni>=h||nj>=w) continue;
      if(s[ni][nj]=='#') continue;
      bfs.emplace(d+1, ni, nj);
    }
  }
  int ans=0;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++) ans+=(dist[i][j]<=K);
  cout << ans << endl;
  return 0; 
}