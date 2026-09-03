#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation, grid

int main(void){
  int h, w; cin >> h >> w;
  int R, C; cin >> R >> C;
  vector<string> stp(R), ans(h, string(w, '.'));
  for(auto&x:stp) cin >> x;
  int n; cin >> n;
  while(n--){
    int r, c; cin >> r >> c; r--, c--;
    for(int i=0; i<R; i++)for(int j=0; j<C; j++){
      int ni=r+i, nj=c+j;
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      if(stp[i][j]=='.') continue;
      ans[ni][nj]='#';
    }
  }
  for(int i=0; i<h; i++) cout << ans[i] << endl;
  return 0; 
}