#include<iostream>
#include<vector>
#include<set>
using namespace std;
using ll = long long;

//Tags: 木, 重心分解

struct CentroidDecomposition{
  int n, root;
  using PP = pair<int, ll>;
  struct PathInfo{
    int c;
    ll d;
    PathInfo(int c=-1, ll d=0):c(c), d(d){}
  };
  vector<vector<PP>> to;
  vector<vector<PathInfo>> path;
  vector<int> sz, cd_par, cd_dep, open;
  vector<multiset<ll>> val;
  vector<bool> remove;
  CentroidDecomposition(int n): 
  n(n), root(-1), to(n), path(n), sz(n), open(n), val(n),
  cd_par(n, -1), cd_dep(n), remove(n, false){}
  
  void addEdge(int u, int v, ll w=1){
    to[u].emplace_back(v, w);
  }

  int sub_size(int u, int par){
    sz[u]=1;
    for(auto [v, w]:to[u]){
      if(v==par||remove[v]) continue;
      sz[u]+=sub_size(v, u);
    }
    return sz[u];
  }

  //remove=trueで区切られた、uを含む連結成分の重心の頂点番号
  int find_centroid(int u, int par, int total){
    for(auto [v, w]:to[u]){
      if(par==v||remove[v]) continue;
      if(sz[v]>total/2){
        return find_centroid(v, u, total);
      }
    }
    return u;
  }

  //c:重心, d:u-c間の距離
  void collect(int u, int par, int c, ll d){
    path[u].emplace_back(c, d);
    for(auto [v, w]:to[u]){
      if(par==v||remove[v]) continue;
      collect(v, u, c, d+w);
    }
  }

  void build(int u, int par=-1, int d=0){
    int total=sub_size(u, -1);
    int c=find_centroid(u, -1, total);
    collect(c, -1, c, 0);
    cd_par[c]=par;
    cd_dep[c]=d;
    if(par==-1) root=c;
    remove[c]=true;
    for(auto [v, nw]:to[c]){
      if(!remove[v]) build(v, c, d+1);
    }
  }

  void update(int u){
    for(auto info:path[u]){
      ll c=info.c, d=info.d;
      if(open[u]) val[c].erase(val[c].find(d));
      else val[c].insert(d);
    }
    open[u]^=1;
  }

  ll query(int u){
    ll ans=1e18;
    for(auto info:path[u]){
      ll c=info.c, d=info.d;
      ll w=((int)val[c].size()?*begin(val[c]):1e18);
      ans=min(ans, w+d);
    }
    return ans;
  }
};

int main(void){
  int n, q; cin >> n >> q;
  CentroidDecomposition cd(n);
  for(int i=0; i<n-1; i++){
    int a, b; ll c; cin >> a >> b >> c; a--, b--;
    cd.addEdge(a, b, c); swap(a, b);
    cd.addEdge(a, b, c); 
  }
  cd.build(0);
  cd.update(0);
  while(q--){
    int t; cin >> t;
    if(t==1){
      int x; cin >> x; x--;
      cd.update(x);
    }
    else{
      int v; ll t; cin >> v >> t; v--;
      ll ans=cd.query(v);
      cout << (ans<=t?"YES":"NO") << '\n';
    }
  }
  return 0; 
}