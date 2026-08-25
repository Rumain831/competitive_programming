#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<int, int, int>;

//Tags: イベントソート

int main(void){
  int n, m, d, t; cin >> n >> m >> d >> t;
  vector<tu> event;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    event.emplace_back(a, 1, 0);
    event.emplace_back(min(t+1, a+d), -1, 0);
  }
  for(int i=0; i<m; i++){
    int b; cin >> b;
    event.emplace_back(b, 1, 1);
    event.emplace_back(min(t+1, b+d), -1, 1);
  }
  sort(begin(event), end(event));
  int la=0, lb=0;
  ll ans=0, pre=0;
  int q=event.size(), id=0;
  while(id<q){
    ll now=get<0>(event[id]);
    if(la>lb) ans+=now-pre;
    while(id<q){
      auto [t, add, who]=event[id];
      if(t!=now) break;
      if(who==0) la+=add;
      else lb+=add;
      id++;
    }
    pre=now;
  }
  cout << ans << endl;
  return 0; 
}