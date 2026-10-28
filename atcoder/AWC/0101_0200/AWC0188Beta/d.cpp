#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using ll = long long;
using tu = tuple<ll, int, int>;

//Tags: ダイクストラ法

int main(void){
  int h, w; cin >> h >> w;
  vector a(h, vector<ll>(w));
  for(auto&x:a)for(auto&y:x) cin >> y;
  priority_queue<tu, vector<tu>, greater<tu>> pri;
  vector dist(h, vector<ll>(w, 1e18));
  pri.emplace(0, 0, 0);
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  dist[0][0]=0;
  while(pri.size()){
    auto [d, i, j]=pri.top(); pri.pop();
    if(dist[i][j]!=d) continue;
    for(int k=0; k<4; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(ni<0||nj<0||ni>=h||nj>=w) continue;
      ll nd=d+a[ni][nj];
      if(dist[ni][nj]>nd){
        dist[ni][nj]=nd;
        pri.emplace(nd, ni, nj);
      }
    }
  }
  cout << dist[h-1][w-1] << endl;
  return 0; 
}