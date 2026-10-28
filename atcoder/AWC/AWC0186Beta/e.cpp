#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: DAG, dp

int main(void){
  int n, m; cin >> n >> m;
  vector<int> a(n), deg(n);
  for(auto&x:a) cin >> x;
  vector<vector<int>> to(n);
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v; u--, v--;
    to[u].push_back(v); 
    deg[v]++;
  }
  queue<int> qu;
  vector<int> dp;
  for(int i=0; i<n; i++)if(deg[i]==0) qu.push(i);
  while(qu.size()){
    int x=qu.front(); qu.pop();
    dp.push_back(x);
    for(auto p:to[x]){
      if(--deg[p]==0) qu.push(p);
    }
  }
  if(dp.size()!=n){
    cout << -1 << endl; return 0;
  }
  vector<ll> ans(n);
  for(auto p:dp){
    ans[p]+=a[p];
    for(auto q:to[p]) ans[q]=max(ans[q], ans[p]);
  }
  cout << *max_element(begin(ans), end(ans)) << endl;
  return 0; 
}