#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(void){
  int n; cin >> n;
  ll ans=-1e18;
  vector<P> a;
  for(int i=0; i<n; i++){
    ll x, p; cin >> x >> p;
    a.emplace_back(x, p);
  }
  for(ll i=0; i<=101; i++){
    ll now=0;
    for(int j=0; j<n; j++){
      auto [x, p]=a[j];
      if(abs(x)<=i) now+=p;
    }
    now-=i*i;
    ans=max(ans, now);
  }
  cout << ans << endl;
  return 0;
}
