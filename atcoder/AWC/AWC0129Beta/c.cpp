#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: イベントソート

int main(void){
  int n, m; cin >> n >> m;
  vector<P> event;
  for(int i=0; i<n; i++){
    int d; cin >> d;
    event.emplace_back(d, 2);
  }
  while(m--){
    int l, r; cin >> l >> r; r++;
    event.emplace_back(l, 1);
    event.emplace_back(r, -1);
  }
  sort(begin(event), end(event));
  ll ans=0, cnt=0, p=event.size(), id=0;
  while(id<p){
    int now=event[id].first;
    while(id<p){
      auto [pos, t]=event[id];
      if(pos!=now) break;
      if(t!=2) cnt+=t;
      else{
        ans+=pos*(cnt?2:1);
      }
      id++;
    }
  }
  cout << ans << endl;
  return 0; 
}