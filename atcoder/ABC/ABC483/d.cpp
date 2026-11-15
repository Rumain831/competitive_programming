#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

//Tags: 累積


ll f(P a){
  return a.second-a.first+1;
}
int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  vector<P> R(n+1);
  P pre=P(0, 0);
  for(int i=n-1; i>=0; i--){
    auto [l, r]=pre;
    ll nl=min(0ll, l+a[i]), nr=max(0ll, r+a[i]);
    R[i]=P(nl, nr);
    pre=R[i];
  } 
  ll ans=f(R[0]);
  pre=P(0, 0);
  ll now=0;
  for(int i=0; i<n; i++){
    auto [l, r]=pre;
    ll pos=now-a[i];
    l=min(pos, l);
    r=max(pos, r);
    auto [dl, dr]=R[i+1];
    l=min(l, pos+dl);
    r=max(r, pos+dr);
    ans=max(ans, r-l+1);
    l=pre.first, r=pre.second;
    now+=a[i];
    l=min(l, now), r=max(r, now);
    pre=P(l, r);
  }
  cout << ans << endl;
  return 0; 
}