#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using tu = tuple<int, int, int>;

//Tags: 二分探索, BFS, grid
//Level: 2

int main(void){
  int n, m, k; cin >> n >> m >> k;
  vector a(n, vector<int>(m));
  for(auto&x:a)for(auto&y:x) cin >> y;
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  auto f=[&](int x){
    vector dist(n, vector<int>(m, 1e9));
    int ini=(a[0][0]>=x?0:1);
    queue<tu> bfs;
    bfs.emplace(ini, 0, 0);
    dist[0][0]=ini;
    while(bfs.size()){
      auto [d, i, j]=bfs.front(); bfs.pop();
      if(dist[i][j]!=d) continue;
      for(int k=0; k<4; k++){
        int ni=i+di[k], nj=j+dj[k];
        if(ni<0||nj<0||ni>=n||nj>=m) continue;
        int add=(a[ni][nj]<x);
        int nd=d+add;
        if(dist[ni][nj]>nd){
          dist[ni][nj]=nd;
          bfs.emplace(nd, ni, nj);
        }
      }
    }
    return dist[n-1][m-1]<=k;
  };
  if(f(1e9)){
    cout << (int)1e9 << endl; return 0;
  }
  int left=1, right=1e9;
  while(right-left>1){
    int mid=(left+right)/2;
    if(f(mid)) left=mid;
    else right=mid;
  }
  cout << left << endl;
  return 0; 
}