#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<int, int>;

pair<P, P> square(int i1, int j1, int i2, int j2, int h, int w){
  //左上と右下のgridの座標から右上、左下の順に正方形の頂点の座標を返す
  //di=(i2-i1)/2, dj=(j2-j1)/2;
  //midi=(i1+i2)/2, midj=(j1+j2)/2
  int i3=(i1+i2+j1-j2)/2, j3=(-i1+i2+j1+j2)/2;
  int i4=(i1+i2-j1+j2)/2, j4=(i1-i2+j1+j2)/2;
  if((i1+i2+j1-j2)%2||i3<0||j3<0||i3>=h||j3>=w) i3=-1, j3=-1;
  if((i1+i2-j1+j2)%2||i4<0||j4<0||i4>=h||j4>=w) i4=-1, j4=-1;
  return {P(i3, j3), P(i4, j4)};
}

//Union-Find
struct UnionFind{
  vector<int> par, siz, rank;
  UnionFind(int n) : par(n, -1), siz(n, 1), rank(n, 1) {}  //コンストラクタ
  //根を求めるやつ
  int root(int x){
    if(par[x]==-1) return x;
    else return par[x]=root(par[x]);
  }

  //xを含むグループとyを含むグループとを併合する
  bool unite(int x, int y){
    x=root(x); y=root(y);
    if(x==y) return false;
    if(rank[x]<rank[y]) swap(x, y);
    if(rank[x]==rank[y]) rank[x]++;
    par[y]=x;
    siz[x]+=siz[y];
    return true;
  }

  int size(int x){
    return siz[root(x)];
  }

  bool same(int u, int v){
    return root(u)==root(v);
  }

};

struct WeightedUnionFind{
  vector<int> par;
  vector<ll> pot;
  WeightedUnionFind(int n) : par(n, -1), pot(n, 0) {}  //メンバ変数をどのように初期化するかを表す
  //根がポテンシャルの基準点
  //pot[x]=U(x)-U(p)
  //pot[p]=U(p)-U(r)
  //xをrに繋ぎかえる
  //->pot[x] should be U(x)-U(r)=pot[x]+pot[p]
  int find(int x){
    if(par[x]<0) return x;
    int p=par[x];
    int r=find(p);
    pot[x]+=pot[p];
    return par[x]=r;
  }
  
  //x, yは同じ集合に属すか？　U(y)-U(x)をdにcopy
  bool issame(int x, int y, ll& d){
    int rx=find(x), ry=find(y);
    if(rx!=ry) return false;
    //pot[x]=U(x)-U(rx)
    //pot[y]=U(y)-U(ry)=U(y)-U(rx) (rx=ry)
    //->U(y)-U(x)=pot[y]-pot[x]
    d=pot[y]-pot[x];
    return true;
  }

  //xを含むグループとyを含むグループとを併合する
  //xの重み+w=yの重み
  bool unite(int x, int y, ll w){
    ll d;
    if(issame(x, y, d)) return d==w;
    int rx=find(x), ry=find(y);
    //pot[x]=U(x)-U(rx)
    //pot[y]=U(y)-U(ry)
    //ryをrxに繋げる->ryの親が変わりpot変更の必要が生じる
    //pot[ry] should be U(ry)-U(rx)
    //->pot[ry]=U(y)-pot[y]+pot[x]-U(x)=w-pot[y]+pot[x]
    ll w2=w-pot[y]+pot[x];
    if(par[rx]>par[ry]) swap(rx, ry), w2=-w2;
    par[rx]+=par[ry];
    par[ry]=rx;
    pot[ry]=w2;
    return true;
  }
};

struct BellmanFord{
  int n;
  struct edge{
    int u, v; ll co;
    edge(int u, int v, ll co):u(u), v(v), co(co) {}
  };
  vector<edge> es;
  vector<ll> dist;
  vector<bool> neg;
  ll inf=1e18;
  BellmanFord(int n):n(n), dist(n, inf), neg(n, false){}
  void addedeg(int u, int v, ll w){
    es.emplace_back(u, v, w);
  }
  void build(int st){
    dist[st]=0;
    bool update=false;
    for(int i=0; i<n-1; i++){
      update=false;
      for(auto& e:es){
        if(dist[e.u]==inf) continue;
        ll nxt=dist[e.u]+e.co;
        if(dist[e.v]>nxt){
          dist[e.v]=nxt;
          update=true;
        }
      }
      if(!update) break;
    }
    for(auto& e:es){
      if(dist[e.u]==inf) continue;
      if(dist[e.u]+e.co<dist[e.v]) neg[e.v]=true;
    }
    for(int i=0; i<n-1; i++){
      bool any=false;
      for(auto&e:es){
        if(neg[e.u]&&!neg[e.v]){
          neg[e.v]=true; any=true;
        }
      }
      if(!any) break;
    }
  };

  ll operator()(int to)const{
    if(neg[to]) return -inf;
    else return dist[to];
  }
};

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

struct LCA{
  int n;
  vector<vector<int>> to;
  vector<int> depth;
  vector<vector<int>> parent;
  LCA(int n):n(n){
    depth.resize(n);
    to.resize(n);
    parent.resize(n);
    int c=1;
    while((1<<c)<=n) c++;
    for(int i=0; i<n; i++){
      parent[i].resize(c, -1);
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

};



int main(void){
    //ダイクストラ法
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > road(n);
    for(int i=0; i<m; i++){
    //無向グラフでの処理
    int a, b, c;
    cin >> a >> b >> c;
    road[a-1].push_back(make_pair(b-1, c));
    road[b-1].push_back(make_pair(a-1, c));
    }
  
    vector<ll> dist(n, 1e12);  //最大値は問題ごとに変えること！
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > dij;
    dij.push(make_pair(0, 0)); dist[0]=0; 
    
    while(!dij.empty()){
      auto [score, num]=dij.top(); dij.pop();
      if(dist[num]!=score) continue;
      for(auto [at, cost]:road[num]){
        if(dist[at]>score+cost){
          dist[at]=score+cost;
          dij.push(make_pair(dist[at], at));
        }
      }
    }

    for(int i=0; i<1; i++) cout << dist[n-1] << endl;

    //UnionFindの使い方------------
    //頂点数と辺の数
    int N, M;
    cin >> N >> M;

    //UnionFindを要素数Nで初期化
    UnionFind uf(N);

    //各辺に対する処理
    for(int i=0; i<M; i++){
      int a, b;
      cin >> a >> b;
      uf.unite(a, b); //aを含むグループとbを含むグループを併合する
    }

    //集計
    int res=0; //寝付き
    for(int x=0; x<N; ++x){
      if(uf.root(x)==x) ++res;
    }
    cout << res << endl;
    //--------------------

    //LCA 最小共通祖先を求める。
    {
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
    }

    return 0;
}