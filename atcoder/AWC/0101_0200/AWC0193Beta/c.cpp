#include<iostream>
#include<vector>
using namespace std;

//Tags: grid, Simulation

int main(void){
  int h, w; cin >> h >> w;
  vector<string> c(h);
  for(auto&x:c) cin >> x;
  int ni=0, nj=0;
  vector vis(h, vector<int>(w));
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  int ans=0;
  while(1){
    if(vis[ni][nj]){
      cout << -1 << endl; return 0;
    }
    vis[ni][nj]=1;
    int dir;
    if(c[ni][nj]=='U') dir=0;
    else if(c[ni][nj]=='R') dir=1;
    else if(c[ni][nj]=='D') dir=2;
    else if(c[ni][nj]=='L') dir=3;
    int nni=ni+di[dir], nnj=nj+dj[dir];
    if(nni<0||nnj<0||nni>=h||nnj>=w) break;
    ni=nni, nj=nnj, ans++;
  }
  cout << ans << endl;
  return 0; 
}