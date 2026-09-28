#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using ll = long long;
using tu = tuple<ll, int, int>;

//Tags: Simulation, 実装

int main(void){
  int h, w; cin >> h >> w;
  vector c(h, vector<ll>(w));
  for(auto&x:c)for(auto&y:x) cin >> y;
  vector st(h, vector<int>(w));
  vector ans(h, vector<ll>(w));
  priority_queue<tu, vector<tu>, greater<tu>> pri;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    if(i==0||i==h-1||j==0||j==w-1){
      pri.emplace(c[i][j], i, j);
      st[i][j]=1;
    }
  }
  ll turn=0;
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  while(pri.size()){
    ll tar=get<0>(pri.top());
    turn=tar;
    while(pri.size()){
      auto [hp, i, j]=pri.top();
      if(tar!=hp) break;
      pri.pop();
      ans[i][j]=turn; st[i][j]=2;
      for(int k=0; k<4; k++){
        int ni=i+di[k], nj=j+dj[k];
        if(ni<0||nj<0||ni>=h||nj>=w) continue;
        if(st[ni][nj]) continue;
        pri.emplace(c[ni][nj]+turn, ni, nj);
        st[ni][nj]=1;
      }
    }
  }
  int q; cin >> q;
  while(q--){
    int r, k; cin >> r >> k; r--, k--;
    cout << ans[r][k] << '\n';
  }
  return 0; 
}