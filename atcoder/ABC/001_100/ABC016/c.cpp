#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<int>> to(n), dist(n, vector<int>(n, -1));
  vector<int> ans(n);
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b; a--, b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  for(int i=0; i<n; i++){
    int cnt=0;
    queue<pair<int, int>> q;
    q.emplace(i, 0);
    while(q.size()){
      auto [now, di]=q.front(); q.pop();
      if(dist[i][now]!=-1) continue;
      if(di==3) break;
      dist[i][now]=di;
      if(di==2) cnt++;
      for(auto p:to[now]){
        q.emplace(p, di+1);
      }
    }
    ans[i]=cnt;
  }
  for(int i=0; i<n; i++) cout << ans[i] << endl;
  return 0;
}