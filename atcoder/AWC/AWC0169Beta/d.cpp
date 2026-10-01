#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
void chmin(int& a, int b){a=min(a, b);}

//Tags: bit全探索, ワーシャルフロイド法

int main(void){
  int n, m, k, q; cin >> n >> m >> k >> q;
  vector<int> u(m), v(m), w(m), s(q), t(q);
  for(int i=0; i<m; i++) cin >> u[i] >> v[i] >> w[i], u[i]--, v[i]--;
  for(int i=0; i<q; i++) cin >> s[i] >> t[i], s[i]--, t[i]--;
  int ans=-1, mx=(1<<m);
  for(int i=0; i<mx; i++){
    int cut=__builtin_popcount(i);
    if(cut!=k) continue;
    vector dist(n, vector<int>(n, 1e9));
    for(int j=0; j<n; j++) dist[j][j]=0;
    for(int j=0; j<m; j++)if(!(i>>j&1)){
      chmin(dist[u[j]][v[j]], w[j]);
      chmin(dist[v[j]][u[j]], w[j]);
    }
    for(int z=0; z<n; z++)for(int x=0; x<n; x++)for(int y=0; y<n; y++){
      chmin(dist[x][y], dist[x][z]+dist[z][y]);
    }
    int now=1e9;
    for(int j=0; j<q; j++){
      chmin(now, dist[s[j]][t[j]]);
    }
    ans=max(ans, now);
  }
  if(ans==1e9) cout << "INF" << endl;
  else cout << ans << endl;
  return 0; 
}