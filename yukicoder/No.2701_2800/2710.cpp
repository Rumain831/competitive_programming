#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 二分探索 
//Level: 1.5

int main(void){
  int n, q; cin >> n >> q;
  vector<int> a(n), b;
  for(auto&x:a) cin >> x;
  b=a;
  sort(begin(b), end(b));
  while(q--){
    int x, y; cin >> x >> y; x--, y--;
    if(a[y]>=a[x]){
      cout << 0 << '\n'; continue;
    }
    int ans=lower_bound(begin(b), end(b), a[x])-upper_bound(begin(b), end(b), a[y]);
    cout << ans << '\n';
  }
  return 0; 
}