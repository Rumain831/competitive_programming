#include<iostream>
#include<vector>
#include<set>
#include<tuple>
using namespace std;
using ll = long long;
using tu = tuple<ll, int, int>;

//Tags: Simulation

int main(void){
  int n, q; cin >> n >> q;
  set<tu> fire;
  for(int i=0; i<n; i++){
    int x, s; cin >> x >> s;
    fire.emplace(x, s, i+1);
  }
  fire.emplace(-1e18, 0, 0);
  fire.emplace(1e18, 0, 0);
  while(q--){
    int p; cin >> p;
    auto it1=fire.lower_bound(tu(p, -1, -1));
    auto it2=prev(it1);
    auto [x1, s1, i1]=*it1;
    auto [x2, s2, i2]=*it2;
    auto er=it1;
    if(abs(x1-p)!=abs(x2-p)){
      if(abs(x1-p)<abs(x2-p)) cout << i1 << '\n';
      else{
        er=it2;
        cout << i2 << '\n';
      }
    }
    else if(s1!=s2){
      cout << (s1>s2?i1:i2) << '\n';
      if(s2>s1) er=it2;
    }
    else{
      cout << min(i1, i2) << '\n';
      if(i2<i1) er=it2;
    }
    fire.erase(er);
  }
  return 0; 
}