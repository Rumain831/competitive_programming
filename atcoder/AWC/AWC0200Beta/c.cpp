#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation, grid

int main(void){
  int h, w; cin >> h >> w;
  vector<string> s(h);
  for(auto&x:s) cin >> x;
  int ni=0, nj=0;
  while(1){
    int nxi=ni+(s[ni][nj]=='v'?1:0);
    int nxj=nj+(s[ni][nj]=='v'?0:1);
    if(nxi>=h||nxj>=w) break;
    ni=nxi, nj=nxj;
  }
  cout << ni+1 << ' ' << nj+1 << endl;
  return 0; 
}