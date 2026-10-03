#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: SCC

struct SCC{
  int n;
  vector<vector<P>> to, revto;
  vector<vector<int>> group;
  vector<int> used, order, id;

  SCC(int n=0):n(n), to(n), revto(n), used(n), id(n, -1){}

  void add_edge(int u, int v, int t){
    to[u].emplace_back(v, t);
    revto[v].emplace_back(u, t);
  }

  void dfs1(int u){
    used[u]=1;
    for(auto p:to[u])if(!used[p.first]) dfs1(p.first);
    order.push_back(u);
  }
  void dfs2(int u, int i){
    id[u]=i;
    group[i].push_back(u);
    for(auto p:revto[u])if(id[p.first]==-1) dfs2(p.first, i);
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


  vector<vector<P>> contra(){ //build後に呼ぶ
    int c=group.size();
    vector<vector<P>> ans(c);
    vector<set<P>> seen(c);
    for(int i=0; i<n; i++){
      int idx=id[i];
      for(auto [p, t]:to[i]){
        int nxid=id[p];
        if(idx==nxid) continue;
        if(seen[idx].insert(P(p, t)).second) ans[idx].push_back(P(nxid, t));
      }
    }
    return ans;
  }

  //false：トポロジカル順　true：その逆
  pair<vector<int>, vector<vector<P>>> topo(bool rev=false){
    int c=group.size();
    auto cont=contra();
    vector<int> degin(c);
    for(int i=0; i<c; i++)for(auto [p, t]:cont[i]) degin[p]++;
    queue<int> q;
    for(int i=0; i<c; i++)if(degin[i]==0) q.push(i);
    vector<int> ans;
    while(!q.empty()){
      int now=q.front(); q.pop();
      ans.push_back(now);
      for(auto [p, t]:cont[now]){
        degin[p]--;
        if(degin[p]==0) q.push(p);
      }
    }
    if(rev){
      reverse(ans.begin(), ans.end());
      vector<vector<P>> revto(c);
      for(int i=0; i<c; i++)for(auto [p, t]:cont[i]) revto[p].emplace_back(i, t);
      return {ans, revto};
    }
    return {ans, cont};
  }
};


int main(void){
  int n, q; cin >> n >> q;
  SCC scc(n);
  vector<vector<P>> to(n);
  for(int i=0; i<q; i++){
    int t, u, v; cin >> t >> u >> v; u--, v--;
    to[u].emplace_back(v, t);
    scc.add_edge(u, v, t);
  }
  scc.build();
  auto [dp, cont]=scc.topo();
  int g=dp.size();
  vector<int> ans(n, -1);
  for(int i=0; i<g; i++){
    if(ans[i]==-1) ans[i]=1;
    for(auto p:scc.group[i])for(auto [v, t]:to[p]){
      if(scc.id[p]==scc.id[v]){
        if(t==1){
          cout << "No" << endl; return 0;
        }
      }
      else{
        int x=(t==0?ans[i]:ans[i]+1);
        ans[scc.id[v]]=max(ans[scc.id[v]], x);
      }
    }
  }
  int x=*max_element(begin(ans), end(ans));
  if(x>n){
    cout << "No" << endl; return 0;
  }
  cout << "Yes" << endl;
  for(int i=0; i<n; i++) cout << ans[scc.id[i]] << ' ';
  return 0; 
}