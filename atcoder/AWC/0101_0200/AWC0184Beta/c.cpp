#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 二分探索

int main(void){
  int n, m; cin >> n >> m;
  vector<int> d(m);
  for(auto&x:d) cin >> x;
  sort(begin(d), end(d));
  while(n--){
    int s; cin >> s;
    int ans=upper_bound(begin(d), end(d), s)-begin(d);
    cout << ans << '\n';
  }
  return 0; 
}