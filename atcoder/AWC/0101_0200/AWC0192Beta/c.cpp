#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: Simulation

int main(void){
  int n, k; cin >> n >> k;
  vector<P> pl;
  for(int i=0; i<n; i++){
    int a, b; cin >> a >> b;
    pl.emplace_back(a+b, -i);
  }
  sort(rbegin(pl), rend(pl));
  vector<int> ans(n, -1);
  for(int i=0; i<n; i++){
    auto [x, id]=pl[i];
    if(x<k) break;
    ans[-id]=i+1;
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}