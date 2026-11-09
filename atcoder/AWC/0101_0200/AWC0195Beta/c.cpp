#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation, grid

char f(char x){
  return (x=='0'?'1':'0');
}

int main(void){
  int h, w; cin >> h >> w;
  vector<string> s(h);
  for(auto&x:s) cin >> x;
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  int q; cin >> q;
  while(q--){
    int r, c; cin >> r >> c; r--, c--;
    s[r][c]=f(s[r][c]);
    for(int k=0; k<4; k++){
      int ni=r+di[k], nj=c+dj[k];
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      s[ni][nj]=f(s[ni][nj]); 
    }
  }
  for(auto x:s) cout << x << '\n';
  return 0; 
}