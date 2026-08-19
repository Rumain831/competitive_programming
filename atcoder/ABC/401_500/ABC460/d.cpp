#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<int, int, int>;

int main(void){
  int h, w; cin >> h >> w;
  vector<string> s(h), t(h);
  for(auto&x:s) cin >> x;
  t=s;
  int di[8]={-1, -1, -1, 0, 1, 1, 1, 0};
  int dj[8]={-1, 0, 1, 1, 1, 0, -1, -1};
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    if(s[i][j]=='#') t[i][j]='.';
    else{
      int c=0;
      for(int k=0; k<8; k++){
        int ni=i+di[k], nj=j+dj[k];
        if(ni<0||nj<0||ni>=h||nj>=w) continue;
        if(s[ni][nj]=='#'){
          c++; break;
        }
      }
      if(c) t[i][j]='#';
    }
  }
  vector dist(h, vector<int>(w, 1e9));
  queue<tu> bfs;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    if(t[i][j]=='#'){
      dist[i][j]=0;
      bfs.emplace(0, i, j);
    }
  }
  while(bfs.size()){
    auto [d, i, j]=bfs.front(); bfs.pop();
    if(dist[i][j]!=d) continue;
    for(int k=0; k<8; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      if(dist[ni][nj]>d+1){
        dist[ni][nj]=d+1;
        bfs.emplace(d+1, ni, nj);
      }
    }
  }
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++) cout << (dist[i][j]==1e9||dist[i][j]%2==0?'.':'#');
    cout << endl;
  }
  return 0; 
}