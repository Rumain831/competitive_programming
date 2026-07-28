#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Tags: BFS, bit演算

int main(void){
  int n; cin >> n;
  vector<int> ans(n+1, 1e9);
  queue<pair<int, int>> bfs;
  bfs.emplace(1, 0);
  while(bfs.size()){
    auto [now, cnt]=bfs.front(); bfs.pop();
    if(ans[now]!=1e9) continue;
    if(now==n){
      cout << cnt+1 << endl; return 0;
    }
    ans[now]=cnt;
    int copy=now;
    int k=__builtin_popcount(now);
    if(now+k<=n) bfs.emplace(now+k, cnt+1);
    if(now-k>0) bfs.emplace(now-k, cnt+1);
  }
  cout << -1 << endl;
  return 0;
}