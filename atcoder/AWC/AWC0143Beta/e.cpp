#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: LCA, 左右からの累積

struct LCA{
  int n;
  vector<vector<int>> to;
  vector<int> depth;
  vector<vector<int>> parent;
  LCA(int n):n(n){
    depth.resize(n);
    to.resize(n);
    parent.resize(n);
    for(int i=0; i<n; i++){
      parent[i].resize(18, -1);
    }
  }
  void addEdge(int u, int v){
    to[u].push_back(v);
  }
  void build(){
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
  }
  int query(int u, int v){
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

  pair<ll, ll> q(vector<int>& v){
    int k=v.size();
    if(k==1) return {0, -1};
    
    pair<ll, ll> ans={0, 1e9};
    vector l(2, vector<int>(k));
    vector s(2, vector<ll>(k));
    for(int t=0; t<2; t++){
      for(int i=0; i<k; i++){
        if(i==0){
          l[t][i]=v[i];
          s[t][i]=depth[v[i]];
          continue;
        }
        int x=query(l[t][i-1], v[i]);
        l[t][i]=x;
        s[t][i]=s[t][i-1]+depth[v[i]];
      } 
      reverse(begin(v), end(v));
    }
    reverse(begin(l[1]), end(l[1]));
    {//値1
      int x=l[0].back();
      ll y=s[0].back()-(ll)depth[x]*k;
      ans.first=y;
    }
    {//値2
      ll mi=1e18;
      for(int i=0; i<k; i++){
        int L=(i==0?v[1]:l[0][i-1]);
        int R=(i==k-1?v[k-2]:l[1][i+1]);
        int x=query(L, R);
        ll now=s[0].back()-depth[v[i]]-(ll)(k-1)*depth[x];
        mi=min(mi, now);
      }
      ans.second=mi;
    }
    return ans;
  };
  
};

int main(void){
  int n, q; cin >> n >> q;
  LCA lca(n);
  for(int i=1; i<n; i++){
    int p; cin >> p; p--;
    lca.addEdge(p, i);
    lca.addEdge(i, p);
  }
  lca.build();
  while(q--){
    int k; cin >> k;
    vector<int> v(k);
    for(int i=0; i<k; i++) cin >> v[i], v[i]--;  
    auto [x1, x2]=lca.q(v);
    cout << x1 << ' ' << x2 << '\n';
  }
  return 0; 
}