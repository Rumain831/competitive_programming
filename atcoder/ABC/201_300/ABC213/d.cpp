#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Tags: DFS

int main(void){
  int n; cin >> n;
  vector<set<int>> to(n);
  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b; a--, b--;
    to[a].insert(b);
    to[b].insert(a);
  }
  vector<bool> visit(n, false);
  auto dfs=[&](auto dfs, int now, int par=-1)->void {
    cout << now+1 << ' ';
    visit[now]=true;
    for(auto q:to[now])if(q!=par){
      if(visit[q]) continue;
      dfs(dfs, q, now);
      cout << now+1 << ' ';
    }
  };
  dfs(dfs, 0);
  return 0;
}