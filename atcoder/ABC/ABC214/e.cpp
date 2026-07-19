#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

void solve(){
  int n; cin >> n;
  vector<P> seg;
  for(int i=0; i<n; i++){
    int l, r; cin >> l >> r;
    seg.emplace_back(l, r);
  }
  sort(seg.begin(), seg.end());
  priority_queue<int, vector<int>, greater<int>> pri;
  int idx=0, ans=0;
  int x=seg[0].first;
  auto put=[&](){
    auto r=pri.top();
    if(r<x){
      cout << "No" << '\n'; return false;
    }
    pri.pop(); x++;
    return true;
  };
  while(idx<n){
    auto [l, r]=seg[idx];
    while(x<l&&pri.size()){
      if(!put()) return;
    } 
    x=l;
    while(idx<n){
      auto [ll, rr]=seg[idx];
      if(ll==x){
        pri.push(rr); idx++;
      }
      else break;
    }
  }
  while(pri.size()){
    if(!put()) return;
  }
  cout << "Yes" << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}