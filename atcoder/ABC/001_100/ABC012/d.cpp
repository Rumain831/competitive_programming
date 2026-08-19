#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  vector dist(n, vector<int>(n, 1e8));
  for(int i=0; i<n; i++) dist[i][i]=0;
  for(int i=0; i<m; i++){
    int a, b, t; cin >> a >> b >> t; a--, b--;
    dist[a][b]=dist[b][a]=t;
  }
  for(int k=0; k<n; k++)for(int i=0; i<n; i++)for(int j=0; j<n; j++)
    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
  int ans=1e8;
  for(int i=0; i<n; i++){
    int kari=-1;
    for(int j=0; j<n; j++){
      if(i==j) continue;
      kari=max(kari, dist[i][j]);
    }
    ans=min(ans, kari);
  }
  cout << ans << endl;
  return 0;
}