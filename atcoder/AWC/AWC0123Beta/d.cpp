#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Tags: トポロジカルソート

int main(void){
  int n, m; cin >> n >> m;
  vector<vector<int>> to(n);
  vector<int> in(n);
  for(int i=0; i<m; i++){
    int a, b; cin >> a >> b; a--, b--;
    to[a].push_back(b);
    in[b]++;
  }
  vector<int> ans;
  priority_queue<int, vector<int>, greater<int>> pri;
  for(int i=0; i<n; i++)if(in[i]==0) pri.push(i);
  while(pri.size()){
    int now=pri.top(); pri.pop();
    ans.push_back(now);
    for(auto p:to[now]){
      in[p]--;
      if(in[p]==0) pri.push(p);
    }
  }
  if(ans.size()!=n) cout << -1 << endl;
  else{
    for(auto p:ans) cout << p+1 << ' '; cout << endl;
  }
  return 0; 
}