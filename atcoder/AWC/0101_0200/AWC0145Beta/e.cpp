#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 最適化

int main(void){
  int n; cin >> n;
  vector<ll> h(n);
  for(auto&x:h) cin >> x;
  vector vec(2, vector<ll>(n));
  for(int t=0; t<2; t++){
    ll now=0, pre=0;
    for(int i=0; i<n; i++){
      now+=max(0ll, pre-h[i]);
      pre=h[i];      
      vec[t][i]=now;
    }
    reverse(begin(h), end(h));
  }
  reverse(begin(vec[1]), end(vec[1]));
  ll ans=1e18;
  for(int i=0; i<n; i++) ans=min(ans, vec[0][i]+vec[1][i]);
  cout << ans << endl;
  return 0; 
}