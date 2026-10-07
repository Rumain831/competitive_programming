#include<iostream>
#include<vector>
#include<set>
#include<tuple>
#include<algorithm>
using namespace std;
using P = pair<int, int>;
using tu = tuple<int, int, int>;

//Tags: イベントソート
//Level: 3
//区間更新, max取得のlazytreeでも解ける

int main(void){
  int n, m; cin >> n >> m;
  vector<tu> event;
  for(int i=0; i<m; i++){
    int l, r; char t; cin >> l >> r >> t; l--;
    int x=(t=='Y'?0:t=='K'?1:2);
    event.emplace_back(l, i+1, x); 
    event.emplace_back(r, -(i+1), x); 
  }
  sort(begin(event), end(event));
  int ans[3]={};
  int id=0, p=event.size();
  set<P> let;
  for(int i=0; i<n; i++){
    while(id<p){
      auto [pos, ei, li]=event[id];
      if(i!=pos) break;
      if(ei>0) let.emplace(ei, li);
      else let.erase(P(-ei, li));
      id++;
    }
    auto it=let.begin();
    if(it==end(let)) continue;
    ans[(*it).second]++;
  }
  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
  return 0; 
}