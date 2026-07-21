#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 全方位木dp

template<
  class vinfo=ll,
  class einfo=ll
>
struct Rerooting{ 
  struct Edge{
    int from, to; einfo w;
    Edge(int from, int to, einfo w=1):from(from), to(to), w(w){}
  };
  struct ansData{
    int cnt;
    ll sum;
    ansData(int cnt=0, ll sum=0):cnt(cnt), sum(sum){}
  };
  int n;
  ansData iden;
  vector<ansData> subans;
  vector<ansData> ans;
  vector<vector<Edge>> to;
  vector<vector<ansData>> left, right;
  Rerooting(int n):n(n){
    iden=ansData(0, 0);
    to.resize(n);
    subans.resize(n, iden);
    ans.resize(n, iden);
    left.resize(n);
    right.resize(n);
  }
  void addEdge(int u, int v, einfo x){
    to[u].emplace_back(u, v, x);
  }

  void vertex(ansData& tar, int id){
    tar.cnt+=1;
  };
  void edge(ansData& tar, int from, int to, einfo w){
    tar.sum+=tar.cnt*w;
  };
  void merge(ansData& tar, ansData& x){
    tar.cnt+=x.cnt;
    tar.sum+=x.sum;
  };

  void dfs1(int now, int par=-1){
    int m=to[now].size(); 
    if(par!=-1) m--;
    left[now].resize(m+2, iden);
    right[now].resize(m+2, iden);
    int id=1;
    for(auto p:to[now])if(p.to!=par){
      dfs1(p.to, now);
      ansData x=subans[p.to];
      edge(x, p.to, now, p.w);
      left[now][id]=right[now][id]=x; id++;
      merge(subans[now], x);
    }
    for(int i=1; i<=m; i++) merge(left[now][i], left[now][i-1]);
    for(int i=m; i>=1; i--) merge(right[now][i], right[now][i+1]);
    vertex(subans[now], now);
  };
  void dfs2(int now, int par, ansData up){
    ans[now]=subans[now];
    merge(ans[now], up);
    int m=to[now].size(); 
    if(par!=-1) m--;
    int id=1;
    for(auto p:to[now])if(p.to!=par){
      ansData x=up;
      merge(x, left[now][id-1]);
      merge(x, right[now][id+1]);
      vertex(x, now);
      edge(x, now, p.to, p.w); id++;
      dfs2(p.to, now, x);
    }
  };
  
  void build(int root=0){
    dfs1(root);
    dfs2(root, -1, iden);
  };
};

int main(void){
  int n; cin >> n;
  Rerooting<ll, ll> dp(n);
  for(int i=0; i<n-1; i++){
    int u, v; cin >> u >> v; u--, v--;
    dp.addEdge(u, v, 1);
    dp.addEdge(v, u, 1);
  }
  dp.build(0);
  for(int i=0; i<n; i++) cout << dp.ans[i].sum << '\n';
  return 0; 
}