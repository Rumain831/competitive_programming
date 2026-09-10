#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
void chmin(ll& a, ll b){a=min(a, b);}

//Tags: ワーシャルフロイド法

int main(void){
  int n, m; cin >> n >> m;
  vector dist(n, vector<ll>(n, 1e18));
  for(int i=0; i<n; i++) dist[i][i]=0;
  while(m--){
    int u, v; ll w; cin >> u >> v >> w; u--, v--;
    chmin(dist[u][v], w); 
  }
  for(int k=0; k<n; k++)for(int i=0; i<n; i++)for(int j=0; j<n; j++){
    chmin(dist[i][j], dist[i][k]+dist[k][j]);
  }
  for(int k=0; k<n; k++){
    int ans=0;
    for(int i=0; i<n; i++)for(int j=0; j<n; j++){
      if(i==j||i==k||j==k) continue;
      if(dist[i][j]==1e18||dist[i][k]==1e18||dist[k][j]==1e18) continue;
      if(dist[i][j]==dist[i][k]+dist[k][j]) ans++;
    }
    cout << ans << '\n';
  }
  return 0; 
}