#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: Simulation
//Level: 2.5

int main(void){
  int n, m; cin >> n >> m;
  priority_queue<P, vector<P>, greater<P>> pri;
  for(int i=0; i<m; i++) pri.emplace(0, i);
  while(n--){
    ll t; cin >> t;
    auto [nt, id]=pri.top(); pri.pop();
    pri.emplace(nt+t, id);
  }
  ll ans=0;
  while(pri.size()){
    ans=max(ans, pri.top().first);
    pri.pop();
  }
  cout << ans << endl;
  return 0; 
}