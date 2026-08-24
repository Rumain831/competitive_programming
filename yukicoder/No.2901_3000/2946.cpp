#include<iostream>
#include<vector>
using namespace std;
using P = pair<int, int>;

//Tags: DFS
//Level: 1.5

int main(void){
  int h, w; cin >> h >> w;
  vector<string> s(h);
  for(auto&x:s) cin >> x;
  vector seen(h, vector<int>(w));
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  auto dfs=[&](auto dfs, int i, int j, char& c, vector<P>& p)->void {
    seen[i][j]=1;
    p.emplace_back(i, j);
    for(int k=0; k<4; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      if(seen[ni][nj]) continue;
      if(s[ni][nj]!=c) continue;
      dfs(dfs, ni, nj, c, p);
    }
  };
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    if(seen[i][j]) continue;
    vector<P> pos;
    dfs(dfs, i, j, s[i][j], pos);
    if(pos.size()>=4){
      for(auto [ni, nj]:pos) s[ni][nj]='.';
    }
  }  
  for(int i=0; i<h; i++) cout << s[i] << '\n';
  return 0; 
}