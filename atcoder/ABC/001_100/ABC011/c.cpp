#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//dpでもOK
int main(void){
  int n, ng1, ng2, ng3; cin >> n >> ng1 >> ng2 >> ng3;
  if(n==ng1||n==ng2||n==ng3){
    cout << "NO" << endl; return 0;
  }
  vector<int> dist(n+1, 1e8);
  queue<pair<int, int>> q;
  q.emplace(n, 0);
  while(q.size()){
    auto [now, cnt]=q.front(); q.pop();
    if(dist[now]<=cnt) continue;
    dist[now]=cnt;
    for(int i=1; i<=3; i++){
      int next=now-i;
      if(next>=0&&next!=ng1&&next!=ng2&&next!=ng3){
        q.emplace(now-i, cnt+1);
      }
    }
  }
  if(dist[0]<=100) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}