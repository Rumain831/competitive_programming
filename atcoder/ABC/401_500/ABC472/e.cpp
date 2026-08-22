#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: グラフ, 閉路

void solve(){
  int n, m; cin >> n >> m;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); swap(u, v);
    to[u].push_back(v);
  }
  vector<int> col(n, -1), pa(n, -1);
  vector<P> rem;
  auto dfs=[&](auto dfs, int now, int c=0, int par=-1)->void {
    col[now]=c;
    for(auto p:to[now])if(p!=par){
      if(col[p]!=-1){
        rem.emplace_back(now, p);
      }
      else{
        pa[p]=now;
        dfs(dfs, p, c^1, now);
      }
    }
  };
  dfs(dfs, 0);
  auto path=[&](int st, int to){
    vector<int> ans;
    int now=st;
    ans.push_back(now);
    while(now!=to){
      now=pa[now];
      ans.push_back(now);
    }
    return ans;
  };
  for(auto [u, v]:rem){
    if(col[u]==col[v]){
      //LCA->u->v->LCA
      int lca;
      {
        vector<int> seen(n);
        int now=u;
        while(now!=-1){
          seen[now]=1;
          now=pa[now];
        }
        now=v;
        while(!seen[now]) now=pa[now];
        lca=now;
      }
      vector<int> pu=path(u, lca), pv=path(v, lca);
      reverse(begin(pu), end(pu));
      pv.pop_back();
      pu.insert(end(pu), begin(pv), end(pv));
      cout << pu.size() << '\n';
      for(auto p:pu) cout << p+1 << ' '; cout << '\n';
      return;
    } 
  }
  cout << -1 << '\n';
}


int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}