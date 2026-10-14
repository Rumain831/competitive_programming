#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
using qu = tuple<int, int, int, int>;

//Tags: BFS

int main(void){
  int n, m; cin >> n >> m;
  vector<string> a(n);
  for(auto&x:a) cin >> x;
  vector num(n, vector<int>(m));
  int si, sj, gi, gj;
  for(int i=0; i<n; i++)for(int j=0; j<m; j++){
    if(a[i][j]=='S') si=i, sj=j, num[i][j]=0;
    else if(a[i][j]=='G') gi=i, gj=j, num[i][j]=0;
    else num[i][j]=a[i][j]-'0';
  }
  queue<qu> bfs;
  vector dist(n, vector(m, vector<int>(10, 1e9)));
  bfs.emplace(0, si, sj, 0);
  dist[si][sj][0]=0;
  int di[4]={-1, 0, 1, 0};
  int dj[4]={0, 1, 0, -1};
  while(bfs.size()){
    auto [d, i, j, st]=bfs.front(); bfs.pop();
    if(dist[i][j][st]!=d) continue;
    for(int k=0; k<4; k++){
      int ni=i+di[k], nj=j+dj[k];
      if(ni<0||nj<0||ni>=n||nj>=m) continue;
      int nd=d+1, nst=st;
      if(num[ni][nj]==st+1) nst++;
      if(dist[ni][nj][nst]>nd){
        dist[ni][nj][nst]=nd;
        bfs.emplace(nd, ni, nj, nst);
      }
    }
  }

  cout << (dist[gi][gj][9]==1e9?-1:dist[gi][gj][9]) << endl;
  return 0; 
}