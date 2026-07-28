#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: SCC

struct SCC{
  int n;
  vector<vector<int>> to, revto, group;
  vector<int> used, order, id;

  SCC(int n=0):n(n), to(n), revto(n), used(n), id(n, -1){}

  void add_edge(int u, int v){
    to[u].push_back(v);
    revto[v].push_back(u);
  }

  void dfs1(int u){
    used[u]=1;
    for(auto p:to[u])if(!used[p]) dfs1(p);
    order.push_back(u);
  }
  void dfs2(int u, int i){
    id[u]=i;
    group[i].push_back(u);
    for(auto p:revto[u])if(id[p]==-1) dfs2(p, i);
  }

  int build(){ //成分数
    for(int i=0; i<n; i++)if(!used[i]) dfs1(i);
    reverse(order.begin(), order.end());
    int gi=0;
    for(auto u:order){
      if(id[u]!=-1) continue;
      group.push_back({});
      dfs2(u, gi); gi++;
    }
    return gi;
  }

  vector<vector<int>> contra(){
    int c=group.size();
    vector<vector<int>> ans(c);
    vector<unordered_set<int>> seen(c);
    for(int i=0; i<n; i++){
      int idx=id[i];
      for(int p:to[i]){
        int nxid=id[p];
        if(idx==nxid) continue;
        if(seen[idx].insert(nxid).second) ans[idx].push_back(nxid);
      }
    }
    return ans;
  }

  pair<vector<int>, vector<vector<int>>> topo(bool rev=false){
    int c=group.size();
    auto cont=contra();
    vector<int> degin(c);
    for(int i=0; i<c; i++)for(auto p:cont[i]) degin[p]++;
    queue<int> q;
    for(int i=0; i<c; i++)if(degin[i]==0) q.push(i);
    vector<int> ans;
    while(!q.empty()){
      int now=q.front(); q.pop();
      ans.push_back(now);
      for(int p:cont[now]){
        degin[p]--;
        if(degin[p]==0) q.push(p);
      }
    }
    if(rev){
      reverse(ans.begin(), ans.end());
      vector<vector<int>> revto(c);
      for(int i=0; i<c; i++)for(auto p:cont[i]) revto[p].push_back(i);
      return {ans, revto};
    }
    return {ans, cont};
  }
};

int main(void){
  int n; cin >> n;
  SCC scc(n);
  vector<int> level(n);
  for(int i=0; i<n; i++){
    int s; cin >> level[i] >> s; s--;
    scc.add_edge(s, i);
  }
  int m=scc.build();
  auto [p, to]=scc.topo();
  vector<int> seen(n);
  auto dfs=[&](auto dfs, int now, int par=-1)->double {
    double sum=0, mi=1e9;
    double ans=0;
    seen[now]=1;
    for(auto q:scc.group[now]){
      sum+=level[q], mi=min<double>(mi, level[q]);
    }
    for(auto ni:to[now]){
      ans+=dfs(dfs, ni, now);
    }
    if(par==-1) sum-=mi, sum/=2.0, sum+=mi;
    else sum/=2.0;
    return ans+sum;
  };
  double ans=0;
  for(int i=0; i<m; i++){
    if(seen[p[i]]) continue;
    double d=dfs(dfs, p[i]);
    ans+=d;
  }
  printf("%.1f\n", ans);
  return 0; 
}