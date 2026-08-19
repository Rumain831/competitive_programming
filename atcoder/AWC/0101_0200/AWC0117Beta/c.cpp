#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

int main(void){
  int n, k; cin >> n >> k;
  vector<P> event;
  for(int i=0; i<n; i++){
    int s, e; cin >> s >> e;
    event.emplace_back(s, 1);
    event.emplace_back(e, -1);
  }
  sort(begin(event), end(event));
  int now=0, id=0, m=event.size();
  while(id<m){
    int t=event[id].first;
    while(id<m){
      auto [ti, d]=event[id];
      if(ti!=t) break;
      now+=d; id++;
    }
    if(now>=k){
      cout << "Yes" << endl; return 0;
    }
  }
  cout << "No" << endl;
  return 0; 
}