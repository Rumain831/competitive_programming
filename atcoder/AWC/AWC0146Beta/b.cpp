#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 全探索, grid

int main(void){
  int h, w; cin >> h >> w;
  vector g(h, vector<ll>(w));
  vector<ll> sh(h), sw(w);
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    cin >> g[i][j];
    sh[i]+=g[i][j], sw[j]+=g[i][j];
  }
  ll mx=-1e18;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    mx=max(mx, sh[i]+sw[j]-g[i][j]);
  }
  cout << mx << endl;
  return 0; 
}