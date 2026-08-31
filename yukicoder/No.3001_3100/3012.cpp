#include<iostream>
#include<vector>
using namespace std;
using P = pair<int, int>;

//Tags: 構築, グラフ
//Level: 1.5

int main(void){
  int x, y; cin >> x >> y;
  vector<P> ans;
  int c=x+1;
  for(int i=1; i<=x; i++){
    int pre=i;
    if(i<x) ans.emplace_back(i, i+1);
    else ans.emplace_back(i, 1);
    for(int j=0; j<y-1; j++){
      ans.emplace_back(pre, c);
      pre=c, c++;
    }
  }
  cout << c-1 << ' ' << ans.size() << endl;
  for(auto [u, v]:ans) cout << u << ' ' << v << endl;
  return 0; 
}