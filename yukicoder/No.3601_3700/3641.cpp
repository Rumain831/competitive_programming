#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

//Tags: Simulation
//Level: 1.5

int main(void){
  int n, m, q; cin >> n >> m >> q;
  map<int, deque<int>> row;
  vector<int> ans(m);
  while(q--){
    int t; cin >> t;
    if(t==1){
      int i, g; cin >> i >> g; i--, g--;
      row[g].push_back(i);
    }
    else{
      int s, t; cin >> s >> t; s--, t--;
      int x=row[s].front(); row[s].pop_front();
      ans[x]++;
      row[t].push_back(x);
    }
  }
  for(auto p:ans) cout << p << '\n';
  return 0;
}