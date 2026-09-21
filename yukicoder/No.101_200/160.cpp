#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, ll>;

//Tags: フロイドワーシャル法, 辞書順
//Level: 2.5

int main(void){
  int n, m, s, g; cin >> n >> m >> s >> g; 
  vector dist(n, vector<ll>(n, 1e18));
  vector<vector<P>> to(n);
  for(int i=0; i<n; i++) dist[i][i]=0;
  while(m--){
    int a, b; ll c; cin >> a >> b >> c;
    to[a].emplace_back(b, c); dist[a][b]=c; swap(a, b);
    to[a].emplace_back(b, c); dist[a][b]=c; 
  }
  for(int i=0; i<n; i++) sort(begin(to[i]), end(to[i]));
  for(int k=0; k<n; k++)for(int i=0; i<n; i++)for(int j=0; j<n; j++){
    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
  }
  vector<int> ans;
  int now=s;
  ll d=dist[s][g];
  while(now!=g){
    ans.push_back(now);
    for(auto [p, c]:to[now]){
      if(dist[s][now]+c+dist[p][g]==d){
        now=p; break;
      }
    }
  } 
  ans.push_back(g);
  for(auto p:ans) cout << p << ' '; cout << endl;
  return 0; 
}