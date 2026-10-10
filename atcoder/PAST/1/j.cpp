#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using ll = long long;
using tu = tuple<ll, int, int>;

//Tags: ダイクストラ法, grid

int main(void){
  int h, w; cin >> h >> w;
  vector a(h, vector<int>(w));
  for(auto&x:a)for(auto&y:x) cin >> y;
  auto Dij=[&](int i, int j){
    priority_queue<tu, vector<tu>, greater<tu>> pri;
    vector dist(h, vector<int>(w, 1e9));
    pri.emplace(0, i, j);
    dist[i][j]=0;
    int di[4]={-1, 0, 1, 0};
    int dj[4]={0, 1, 0, -1};
    while(pri.size()){
      auto [d, i, j]=pri.top(); pri.pop();
      if(dist[i][j]!=d) continue;
      for(int k=0; k<4; k++){
        int ni=i+di[k], nj=j+dj[k];
        if(ni<0||nj<0||ni>=h||nj>=w) continue;
        int nd=d+a[ni][nj];
        if(dist[ni][nj]>nd){
          dist[ni][nj]=nd;
          pri.emplace(nd, ni, nj);
        }
      }
    }
    return dist;
  };
  auto dist1=Dij(h-1, 0);
  auto dist2=Dij(h-1, w-1);
  auto dist3=Dij(0, w-1);
  ll ans=1e9;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    ll now=dist1[i][j]+dist2[i][j]+dist3[i][j]-a[i][j]*2;
    ans=min(ans, now);
  }
  cout << ans << endl;
  return 0; 
}