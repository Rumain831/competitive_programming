#include<iostream>
#include<vector>
using namespace std;

//Tags: 実装
//Level: 1.5

int main(void){
  int n, m; cin >> n >> m;
  vector<pair<int, int>> ans;
  vector<int> a(m);
  for(auto&x:a) cin >> x;
  int id=0, st, ed;
  while(id<m){
    st=a[id], ed=a[id];
    while(id+1<m&&a[id+1]==a[id]+1) id++, ed=a[id];
    ans.emplace_back(st, ed-st+1);
    id++;
  }
  cout << ans.size() << endl;
  for(auto [p, q]:ans) cout << p << ' ' << q << endl;
  return 0;
}
