#include<iostream>
#include<vector>
using namespace std;

//Tags: サイクル, グラフ
//https://codeforces.com/contest/977/problem/E
//連結成分がサイクル =　連結成分を構成する頂点の次数が全て2

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<int>> to(n);
  vector<int> deg(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); swap(u, v);
    to[u].push_back(v);
    deg[u]++, deg[v]++;
  }
  vector<int> seen(n);
  auto dfs=[&](auto dfs, int now, int par=-1, vector<int>& vs)->void {
    vs.push_back(now);
    seen[now]=1;
    for(auto p:to[now])if(p!=par&&seen[p]==0){
      dfs(dfs, p, now, vs);
    }
    return;
  };
  int ans=0;
  for(int i=0; i<n; i++){
    if(seen[i]) continue;
    vector<int> v;
    dfs(dfs, i, -1, v);
    bool ok=true;
    for(auto p:v)if(deg[p]!=2){
      ok=false; break;
    }
    if(ok) ans++;
  }
  cout << ans << endl;
  return 0; 
}