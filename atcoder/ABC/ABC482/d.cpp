#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 最適化

int main(void){
  int n; cin >> n;
  vector<ll> x(n);
  for(auto&y:x) cin >> y;
  x.push_back(x.back());
  x.push_back(x[0]);
  sort(begin(x), end(x));
  ll l=x[0], r=x.back();
  for(int i=1; i<=n; i++){
    ll ans=1e18;
    for(int d=-1; d<=1; d++){
      if(d==0) continue;
      ll L=min(x[i], x[i+d]), R=max(x[i], x[i+d]);
      ll now=max(abs(r-L)/2, abs(l-R)/2);
      ans=min(ans, now);
    }
    cout << ans << '\n';
  }
  return 0; 
}