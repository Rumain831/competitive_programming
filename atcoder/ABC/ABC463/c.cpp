#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<int, int>;
using tu = tuple<int, int, int>;

//イベントソートによる解法
int main(void){
  int n; cin >> n;
  vector<int> h(n), l(n);
  vector<tu> event;
  priority_queue<P> pri;
  for(int i=0; i<n; i++){
    cin >> h[i] >> l[i];
    event.emplace_back(l[i], 0, i);
    pri.emplace(h[i], i);
  }
  int q; cin >> q;
  vector<int> ans(q), erase(n);
  vector<P> query;
  for(int i=0; i<q; i++){
    int t; cin >> t;
    event.emplace_back(t, 1, i); 
  }
  sort(event.begin(), event.end());
  int ei=0, mx=event.size();
  while(ei<mx){
    auto [x, t, id]=event[ei];
    if(t==0){
      erase[id]=1;
    }
    else{
      while(pri.size()){
        auto [H, ti]=pri.top();
        if(erase[ti]){
          pri.pop(); continue;
        }
        else{
          ans[id]=H;
          break;
        }
      }
    }
    ei++;
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}