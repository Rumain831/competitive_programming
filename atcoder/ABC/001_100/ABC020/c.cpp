#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using ll = long long;
using tu = tuple<ll, int, int>;

//Tags: grid, ダイクストラ法, 二分探索

int main(void){
  int h, w, t; cin >> h >> w >> t;
  vector<string> s(h);
  int si, sj, ti, tj;
  for(int i=0; i<h; i++){
    cin >> s[i];
    for(int j=0; j<w; j++){
      if(s[i][j]=='S') si=i, sj=j, s[i][j]='.';
      if(s[i][j]=='G') ti=i, tj=j, s[i][j]='.';
    }
  }
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  ll left=1, right=1e10;
  while(right-left>1){
    ll mid=(left+right)/2;
    priority_queue<tu, vector<tu>, greater<tu>> pri;
    vector dist(h, vector<ll>(w, 1e18));
    pri.emplace(0, si, sj);
    while(pri.size()){
      auto [d, i, j]=pri.top(); pri.pop();
      if(dist[i][j]!=1e18) continue;
      dist[i][j]=d;
      if(i==ti&&j==tj) break;
      for(int k=0; k<4; k++){
        int ni=i+di[k], nj=j+dj[k];
        if(ni<0||nj<0||ni>=h||nj>=w) continue;
        if(s[ni][nj]=='.') pri.emplace(d+1, ni, nj);
        else pri.emplace(d+mid, ni, nj);
      }
    }
    if(dist[ti][tj]<=t) left=mid;
    else right=mid;
  }
  cout << left << endl;
  return 0;
}