#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<int, int, ll>;
void chmin(ll& a, ll b){a=min(a, b);}

//Tags: ワーシャルフロイド法

int main(void){
  int n, m; cin >> n >> m;
  vector dist(n, vector<ll>(n, 1e18));
  for(int i=0; i<n; i++) dist[i][i]=0;
  vector<tu> edge;
  for(int i=0; i<m; i++){
    int a, b; ll c; cin >> a >> b >> c; a--, b--;
    edge.emplace_back(a, b, c);
    chmin(dist[a][b], c);
    chmin(dist[b][a], c);
  }
  for(int k=0; k<n; k++)for(int i=0; i<n; i++)for(int j=0; j<n; j++){
    chmin(dist[i][j], dist[i][k]+dist[k][j]);
  }
  int ans=0;
  for(int i=0; i<m; i++){
    auto [a, b, c]=edge[i];
    bool use=false;
    for(int p=0; p<n-1; p++)for(int q=p+1; q<n; q++){
      if(dist[p][q]==dist[p][a]+c+dist[b][q]){use=true; break;}
      if(dist[p][q]==dist[q][a]+c+dist[b][p]){use=true; break;}
    }
    if(!use) ans++;
  }
  cout << ans << endl;
  return 0;
}