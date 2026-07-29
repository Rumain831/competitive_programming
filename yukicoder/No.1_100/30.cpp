#include<iostream>
#include<vector>
using namespace std;
using P = pair<int, int>;

//Tags: DFS, 木

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<P>> to(n);
  while(m--){
    int p, q, r; cin >> p >> q >> r; p--, r--;
    to[r].emplace_back(p, q);
  }
  vector<int> ans(n);
  ans[n-1]=1;
  auto dfs=[&](auto dfs, int now, int par=-1)->void {
    bool leaf=true;
    for(auto [v, per]:to[now])if(v!=par){
      ans[v]+=ans[now]*per;
      dfs(dfs, v, now);
      leaf=false;
    }
    if(!leaf) ans[now]=0;
  };
  dfs(dfs, n-1);
  for(int i=0; i<n-1; i++) cout << ans[i] << '\n';
  return 0; 
}