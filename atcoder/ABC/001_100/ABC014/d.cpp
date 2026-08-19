#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n; cin >> n;
  vector<vector<int>> to(n), parent(n, vector<int>(18, -1));
  for(int i=0; i<n-1; i++){
    int x, y; cin >> x >> y; x--, y--;
    to[x].push_back(y);
    to[y].push_back(x);
  }
  vector<int> depth(n);
  auto dfs=[&](auto dfs, int now, int par=-1, int d=0)->void {
    depth[now]=d;
    parent[now][0]=par;
    for(auto p:to[now]){
      if(p!=par) dfs(dfs, p, now, d+1);
    }
    return;
  };
  dfs(dfs, 0);
  for(int k=1; k<18; k++){
    for(int i=0; i<n; i++){
      if(parent[i][k-1]!=-1) parent[i][k]=parent[parent[i][k-1]][k-1];
    }
  }
  auto lca=[&](int u, int v){
    if(depth[u]<depth[v]) swap(u, v);
    int dif=depth[u]-depth[v], l=0;
    while(dif>0){
      if(dif%2) u=parent[u][l];
      l++; dif/=2;
    }
    if(u==v) return u;
    for(int k=17; k>=0; k--){
      if(parent[u][k]!=parent[v][k]) u=parent[u][k], v=parent[v][k];
    }
    return parent[u][0];
  };
  int q; cin >> q;
  for(int i=0; i<q; i++){
    int a, b; cin >> a >> b; a--, b--;
    cout << depth[a]+depth[b]-2*depth[lca(a, b)]+1 << endl;
  }
  return 0;
}