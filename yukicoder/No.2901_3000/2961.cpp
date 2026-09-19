#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 周期性, 二分探索
//Level: 1.5

int main(void){
  int r, n; cin >> r >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  sort(begin(a), end(a));
  int q; cin >> q;
  auto f=[&](int x){
    int p=x/r, s=x%r;
    int ans=n*p, y=upper_bound(begin(a), end(a), s)-begin(a);
    return ans+y;
  };
  while(q--){
    int L, R; cin >> L >> R;
    cout << f(R)-f(L-1) << endl;
  }
  return 0; 
}