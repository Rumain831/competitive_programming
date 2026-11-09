#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 貪欲法

int main(void){
  int n, m; cin >> n >> m;
  vector<P> pc;
  for(int i=0; i<n; i++){
    int a, b; cin >> a >> b;
    pc.emplace_back(a, b);
  }
  vector<ll> c(m);
  for(auto&x:c) cin >> x;
  sort(rbegin(pc), rend(pc));
  sort(rbegin(c), rend(c));
  ll ans=0, id=0;
  priority_queue<ll> pri;
  for(auto x:c){
    while(id<n){
      auto [a, b]=pc[id];
      if(a>=x) pri.emplace(b), id++;
      else break;
    }
    if(pri.empty()){
      cout << -1 << endl; return 0;
    }
    ans+=pri.top(); pri.pop();
  }
  cout << ans << endl;
  return 0; 
}