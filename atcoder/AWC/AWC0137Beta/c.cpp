#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: イベントソート

int main(void){
  int n, t; cin >> n >> t;
  vector<P> event;
  for(int i=0; i<n; i++){
    int s, e; cin >> s >> e;
    event.emplace_back(s, 1);
    event.emplace_back(e, -1);
  }
  sort(begin(event), end(event));
  int ans=0, now=0, id=0;
  while(id<2*n){
    int nt=event[id].first;
    while(id<2*n&&event[id].first==nt){
      now+=event[id].second;
      id++;
    }
    ans=max(ans, now);
  }
  cout << ans << endl;
  return 0; 
}