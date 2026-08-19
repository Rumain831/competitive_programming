#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: 区間

int main(void){
  int n, T; cin >> n >> T;
  vector<P> seg;
  for(int i=0; i<n; i++){
    int s, t; cin >> s >> t;
    seg.emplace_back(s, t);
  }
  sort(begin(seg), end(seg));
  int pre=0, ans=0;
  for(int i=0; i<n; i++){
    auto [s, t]=seg[i];
    ans=max(ans, s-pre);
    pre=t;
  }
  ans=max(ans, T-pre);
  cout << ans << endl;
  return 0; 
}