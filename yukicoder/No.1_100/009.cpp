#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int, int>;

//Tags: Simulation
//Level: 3

int main(void){
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  int ans=1e9;
  for(int i=0; i<n; i++){
    priority_queue<P, vector<P>, greater<P>> pri;
    for(auto p:a) pri.emplace(p, 0);
    for(int j=0; j<n; j++){
      int id=(i+j)%n;
      auto [level, cnt]=pri.top(); pri.pop();
      level+=b[id]/2, cnt++;
      pri.emplace(level, cnt);
    }
    int now=-1;
    while(pri.size()){
      auto [_, x]=pri.top(); pri.pop();
      now=max(now, x);
    }
    ans=min(ans, now);
  }
  cout << ans << endl;
  return 0; 
}