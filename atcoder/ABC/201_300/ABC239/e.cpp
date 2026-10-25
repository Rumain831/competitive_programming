#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Tags: Simulation, 木dp

void merge(multiset<int>& a, multiset<int>& b){
  for(auto q:b) a.insert(q);
  while(a.size()>20) a.erase(begin(a));
}

int main(void){
  int n, q; cin >> n >> q;
  vector<int> x(n);
  for(int i=0; i<n; i++) cin >> x[i];
  vector<vector<int>> to(n);
  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b; a--, b--;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector<multiset<int>> large(n);
  auto dfs=[&](auto dfs, int now, int p=-1)->void {
    large[now].insert(x[now]);
    for(auto q:to[now])if(q!=p){
      dfs(dfs, q, now);
      merge(large[now], large[q]);
    }
  };
  dfs(dfs, 0);
  while(q--){
    int v, k; cin >> v >> k; v--;
    auto p=end(large[v]);
    advance(p, -k);
    cout << *p << '\n';
  }
  return 0;
}