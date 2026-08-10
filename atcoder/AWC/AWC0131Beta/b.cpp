#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Tags: 二分探索

int main(void){
  int n, q; cin >> n >> q;
  map<string, vector<int>> pos;
  for(int i=0; i<n; i++){
    string s; cin >> s;
    pos[s].push_back(i);
  }
  while(q--){
    int l, r; string t; cin >> l >> r >> t; l--, r--;
    if(pos.count(t)==0){
      cout << 0 << '\n'; continue;
    }
    auto& now=pos[t];
    int ans=upper_bound(begin(now), end(now), r)-lower_bound(begin(now), end(now), l);
    cout << ans << '\n';
  }
  return 0; 
}