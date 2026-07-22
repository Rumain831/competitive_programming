#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<map>
using namespace std;
using tu = tuple<string, int, int>;

//Tags: BFS

int main(void){
  int m; cin >> m;
  vector<vector<int>> to(9);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  map<string, int> ans;
  string now=".........";
  queue<tu> bfs;
  int emp=36;
  for(int i=0; i<8; i++){int p; cin >> p; p--; now[p]=(char)('0'+i); emp-=p;}
  bfs.emplace(now, 0, emp);
  while(bfs.size()){
    auto [s, cnt, idx]=bfs.front(); bfs.pop();
    if(ans.count(s)) continue;
    ans[s]=cnt;
    for(auto p:to[idx]){
      string t=s;
      swap(t[idx], t[p]);
      bfs.emplace(t, cnt+1, p);
    }
  }
  string tar="01234567.";
  if(ans.count(tar)) cout << ans[tar] << endl;
  else cout << -1 << endl;
  return 0;
}