#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int, int>;

//Tags: BFS
//Level: 2.5

void solve(){
  int n, m; cin >> n >> m;
  vector<P> dif;
  vector<vector<int>> to(n);
  while(m--){
    int a, b, c; cin >> a >> b >> c; a--, b--;
    if(c==1){
      to[a].push_back(b); swap(a, b);
      to[a].push_back(b);
    }
    else dif.emplace_back(a, b);
  }
  auto BFS=[&](int st){
    vector<int> ans(n, 1e9);
    queue<P> bfs;
    bfs.emplace(0, st);
    ans[st]=0;
    while(bfs.size()){
      auto [d, now]=bfs.front(); bfs.pop();
      if(ans[now]!=d) continue;
      for(auto p:to[now]){
        int nd=d+1;
        if(ans[p]>nd){
          ans[p]=nd;
          bfs.emplace(nd, p);
        }
      }
    }
    return ans;
  };
  vector<int> dist1=BFS(0), dist2=BFS(n-1);
  if(dist1[n-1]!=1e9){
    cout << "Same" << '\n' << dist1[n-1] << '\n';
  }
  else{
    int ans=1e9;
    for(auto [u, v]:dif)for(int t=0; t<2; t++){
      int now=dist1[u]+dist2[v]+1;
      ans=min(ans, now);
      swap(u, v);
    }
    if(ans!=1e9) cout << "Different" << '\n' << ans << '\n';
    else cout << "Unknown" << '\n';
  }
}

int main(void){
  int t; cin >> t;
  while(t--) solve();
  return 0; 
}