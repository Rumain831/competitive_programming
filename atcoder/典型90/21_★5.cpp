#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 強連結成分分解
//解説URL: https://twitter.com/e869120/status/1385363292739104775

struct SCC{
  int n;
  vector<vector<int>> to, revto, group;
  vector<int> used, order, id;
  // id[v]  : 頂点vが属する強連結成分の番号
  // group[i] : 強連結成分iに属する頂点の一覧

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

  // build後にid[v], group[i]が利用可能
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

  // ans[i]：成分iから辺が出ている強連結成分番号の一覧
  vector<vector<int>> contra(){ //build後に呼ぶ
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

  //false：トポロジカル順　true：その逆
  // 縮約DAGの (トポロジカル順の成分番号列, 隣接リスト) を返す
  // ※順序列の要素は元の頂点番号ではなく、強連結成分番号
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
  int n, m; cin >> n >> m;
  SCC scc(n);
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b; a--, b--;
    scc.add_edge(a, b);
  }
  int s=scc.build();
  ll ans=0;
  for(int i=0; i<s; i++){
    ll x=scc.group[i].size();
    ans+=x*(x-1)/2;
  }
  cout << ans << endl;
  return 0; 
}