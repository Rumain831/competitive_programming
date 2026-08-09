#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: ワーシャルフロイド法

int main(void){
  int n; cin >> n;
  vector<int> s(n);
  for(int i=0; i<n; i++) cin >> s[i];
  int m; cin >> m;
  vector dist(n, vector<int>(n, 1e9));
  for(int i=0; i<n; i++) dist[i][i]=0;
  for(int i=0; i<m; i++){
    int a, b, c; cin >> a >> b >> c; 
    dist[a][b]=dist[b][a]=c;
  }
  for(int k=0; k<n; k++)for(int i=0; i<n; i++)for(int j=0; j<n; j++){
    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
  }
  ll ans=1e18;
  for(int i=1; i<n-1; i++){
    for(int j=1; j<n-1; j++){
      if(i==j) continue;
      ans=min(ans, (ll)dist[0][i]+s[i]+dist[i][j]+s[j]+dist[j][n-1]);
    }
  }
  cout << ans << endl;
  return 0;
}