#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: functional graph

struct FunctionalGraph{
  int n;
  vector<int> to;
  vector<vector<int>> rev;

  vector<vector<int>> cycle;
  vector<int> topo; //木部分のトポロジカル順
  //所属する閉路の番号, 最初に到達する閉路の頂点, 閉路までの距離, 閉路内の添字(木上では-1)
  vector<int> id, root, dep, pos;

  FunctionalGraph(int n): n(n), to(n, -1), rev(n),
    id(n, -1), root(n, -1), dep(n, -1), pos(n, -1) {}

  void addEdge(int i, int p){
    to[i]=p;
    rev[p].push_back(i);
  }

  void build(){
    vector<int> deg(n);
    for(int i=0; i<n; i++) deg[i]=rev[i].size();
    for(int i=0; i<n; i++)if(deg[i]==0) topo.push_back(i);
    for(int i=0; i<(int)topo.size(); i++){
      int u=topo[i], v=to[u];
      deg[v]--;
      if(deg[v]==0) topo.push_back(v);
    }
    for(int i=0; i<n; i++)if(deg[i]&&id[i]==-1){
      int c=cycle.size();
      cycle.emplace_back();
      int now=i;
      do{
        id[now]=c, root[now]=now, dep[now]=0;
        pos[now]=cycle[c].size();
        cycle[c].push_back(now);
        now=to[now];
      }while(now!=i);
    }
    for(int i=(int)topo.size()-1; i>=0; i--){
      int u=topo[i], v=to[u];
      id[u]=id[v], root[u]=root[v], dep[u]=dep[v]+1;

    }
  }

};

int main(void){
  int n; cin >> n;
  FunctionalGraph fg(n);
  vector<int> to(n);
  for(int i=0; i<n; i++){
    int p; cin >> p; p--;
    to[i]=p;
    fg.addEdge(i, p);
  }
  fg.build();
  auto topo=fg.topo;
  vector<ll> point(n), a(n);
  for(auto&x:a) cin >> x;
  for(auto p:topo){
    int nxt=to[p];
    point[nxt]+=point[p]+a[p];
    a[nxt]+=a[p];
  }
  ll ans=0;
  for(auto&cyc:fg.cycle){
    ll s=cyc.size();
    ll now=0, sp=0, sa=0;
    for(int i=s-1; i>=0; i--) now+=a[cyc[i]]*(s-i), sp+=point[cyc[i]], sa+=a[cyc[i]];
    for(int i=0; i<s; i++){
      int u=cyc[i];
      now-=s*a[u];
      ans=max(ans, sp+now);
      now+=sa;
    }
  }
  cout << ans << endl;
  return 0; 
}