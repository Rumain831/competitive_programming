#include<iostream>
#include<vector>
using namespace std;
using P = pair<int, int>;

//Tags: 木
//LCA(a, b)=bかで判定しても良い

int main(void){
  int n; cin >> n;
  vector<int> p(n);
  vector<vector<int>> to(n);
  vector<vector<P>> query(n);
  int ps;
  for(int i=0; i<n; i++){
    cin >> p[i];
    if(p[i]==-1) ps=i;
    else{
      p[i]--;
      to[p[i]].push_back(i);
    }
  }
  int q; cin >> q;
  for(int i=0; i<q; i++){
    int a, b; cin >> a >> b; a--, b--;
    query[a].emplace_back(b, i);
  }
  vector<int> vis(n), ans(q);
  auto dfs=[&](auto dfs, int now, int par=-1)->void {
    vis[now]=1;
    for(auto [b, qi]:query[now]){
      ans[qi]=vis[b];
    }
    for(auto p:to[now])if(p!=par){
      dfs(dfs, p, now);
    }
    vis[now]=0;
  };
  dfs(dfs, ps);
  for(int i=0; i<q; i++) cout << (ans[i]?"Yes":"No") << '\n';
  return 0; 
}