#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 二分探索

int main(void){
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  sort(a.begin(), a.end());
  while(q--){
    int x; cin >> x;
    int ans=a.end()-lower_bound(a.begin(), a.end(), x);
    cout << ans << '\n';
  }
  return 0;
}