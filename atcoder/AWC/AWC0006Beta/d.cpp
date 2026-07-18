#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  int n, m; cin >> n >> m;
  vector<P> seg;
  for(int i=0; i<m; i++){
    int l, r; cin >> l >> r;
    seg.emplace_back(l, r);
  }
  int ans=0;
  sort(seg.begin(), seg.end());
  priority_queue<int> pri;
  int now=1, idx=0;
  while(now<=n){
    while(idx<m){
      auto [l, r]=seg[idx];
      if(now<l) break;
      pri.emplace(r);
      idx++;
    }
    if(pri.empty()){
      cout << -1 << endl; return 0;
    }
    while(pri.size()){
      auto r=pri.top(); 
      if(now>r){
        cout << -1 << endl; return 0;
      }
      ans++;
      now=r+1;
      pri.pop();
      break;
    }
  }
  cout << ans << endl;
  return 0;
}