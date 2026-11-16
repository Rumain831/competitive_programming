#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: Simulation

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> skill(n);
  for(auto&x:skill) cin >> x;
  vector<P> pro;
  vector<int> r(m);
  for(int i=0; i<m; i++){
    ll p; cin >> p >> r[i];
    pro.emplace_back(-p, i);
  }
  sort(begin(pro), end(pro));
  sort(rbegin(skill), rend(skill));
  int id=0;
  vector<ll> ans(m);
  for(int i=0; i<m; i++){
    auto [_, pi]=pro[i];
    int R=r[pi];
    while(R){
      if(id>=n) break;
      ans[pi]+=skill[id];
      id++;
      R--;
    }
    if(R){
      cout << -1 << endl; return 0;
    }
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}