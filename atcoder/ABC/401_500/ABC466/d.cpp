#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  vector<set<int>> tate(n), yoko(n);
  while(m--){
    int r, c; cin >> r >> c; r--, c--;
    for(auto p:tate[r]) yoko[p].erase(r);
    for(auto p:yoko[c]) tate[p].erase(c);
    tate[r].clear(), yoko[c].clear();
    tate[r].insert(c), yoko[c].insert(r);
  }
  int ans=0;
  for(int i=0; i<n; i++) ans+=tate[i].size();
  cout << ans << endl;
  return 0; 
}