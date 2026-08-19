#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

int main(void){
  int n; cin >> n;
  vector<P> po;
  for(int i=0; i<n; i++){
    int x, y; cin >> x >> y; 
    po.emplace_back(x, y);
  }
  sort(po.begin(), po.end());
  int ans=0, mi=1e9;
  for(auto [x, y]:po){
    if(mi>y) ans++, mi=y;
  }
  cout << ans << endl;
  return 0; 
}