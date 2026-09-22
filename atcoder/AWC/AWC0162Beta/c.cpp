#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 最適化

int main(void){
  ll n, d; cin >> n >> d;
  vector<P> good;
  for(int i=0; i<n; i++){
    ll a, c; cin >> a >> c;
    good.emplace_back(a, c);
  }
  sort(begin(good), end(good));
  vector<ll> mi(n+1, 1e18);
  for(int i=n-1; i>=0; i--) mi[i]=min(mi[i+1], good[i].second);
  ll ans=1e18;
  for(int i=0; i<n; i++){
    auto [a, c]=good[i];
    if(a>=d){
      ans=min(ans, c); continue;
    }
    int k=lower_bound(begin(good), end(good), P(d-a, -1))-begin(good);
    k=max(k, i+1);
    ans=min(ans, c+mi[k]);
  }
  cout << (ans==1e18?-1:ans) << endl;
  return 0; 
}