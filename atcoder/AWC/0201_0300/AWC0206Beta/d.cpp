#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: Simulation

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> b(n);
  for(auto&x:b) cin >> x;
  vector<vector<P>> to(n);
  for(int i=0; i<m; i++){
    int u, v; ll w; cin >> u >> v >> w; u--, v--;
    to[u].emplace_back(v, w);
    b[v]-=w;
  }
  vector<int> ans(n);
  queue<P> qu;
  for(int i=0; i<n; i++)if(b[i]>0) qu.emplace(i, 1);
  while(qu.size()){
    auto [id, day]=qu.front(); qu.pop();
    if(ans[id]) continue;
    ans[id]=day;
    for(auto [v, w]:to[id]){
      b[v]+=w;
      if(b[v]>0&&ans[v]==0) qu.emplace(v, day+1);
    }
  }
  for(auto p:ans) cout << p << ' ';
  return 0; 
}