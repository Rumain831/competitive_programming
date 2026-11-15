#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: イベントソート
//Level: 1.5

int main(void){
  int n; cin >> n;
  vector<P> ele;
  for(int i=0; i<n; i++){
    int a, b; cin >> a >> b;
    ele.emplace_back(a, b);
  }
  sort(begin(ele), end(ele));
  int ans=1, id=0;
  while(id<n){
    auto [a, b]=ele[id];
    if(ans<a) break;
    ans=max(ans, b);
    id++;
  }
  cout << ans << endl;
  return 0; 
}