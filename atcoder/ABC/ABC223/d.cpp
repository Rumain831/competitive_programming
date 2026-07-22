#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

//Tags: DAG, トポロジカルソート, 順列

int main(void){
  int n, m; cin >> n >> m;
  vector<set<int>> to(n);
  vector<int> deg(n);
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b; a--, b--;
    if(to[a].count(b)==0) deg[b]++, to[a].insert(b);
  }
  priority_queue<int, vector<int>, greater<int>> pri;
  vector<int> ans;
  for(int i=0; i<n; i++){
    if(deg[i]==0) pri.push(i);
  }
  while(pri.size()){
    int p=pri.top(); pri.pop();
    ans.push_back(p);
    for(auto q:to[p]){
      deg[q]--;
      if(deg[q]==0) pri.push(q);
    }
  }
  if(ans.size()!=n) cout << -1 << endl;
  else for(auto p:ans) cout << p+1 << ' ';
  return 0;
}