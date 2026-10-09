#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 二分探索, 累積和
//Level: 2.5

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> sum(n+1);
  for(int i=0; i<n; i++){
    ll x; cin >> x;
    sum[i+1]=sum[i]+x;
  }
  while(q--){
    ll x; cin >> x;
    int ans=upper_bound(begin(sum), end(sum), x)-begin(sum)-1;
    cout << ans << '\n';
  }
  return 0; 
}