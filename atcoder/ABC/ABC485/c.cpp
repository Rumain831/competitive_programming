#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using PP = pair<P, P>;

//Tags: top2

int main(void){
  int n; cin >> n;
  vector<int> c(n);
  for(auto&x:c) cin >> x;
  P inf1=P(-1e9, -1), inf2=P(1e9, -2);
  vector<PP> l(n+2, PP(inf1, inf1)), r(n+2, PP(inf2, inf2));
  for(int i=0; i<n; i++){
    l[i+1]=l[i];
    auto& [d1, d2]=l[i+1];
    if(d1.second==c[i]) d1=P(i+1, c[i]);
    else{
      swap(d1, d2);
      d1=P(i+1, c[i]);
    }
  }
  for(int i=n-1; i>=0; i--){
    r[i+1]=r[i+2];
    auto& [d1, d2]=r[i+1];
    if(d1.second==c[i]) d1=P(i+1, c[i]);
    else{
      swap(d1, d2);
      d1=P(i+1, c[i]);
    }
  }
  for(int i=0; i<n; i++){
    auto [l1, l2]=l[i];
    auto [r1, r2]=r[i+2];
    ll ans=1e9;
    if(l1.second!=c[i]) ans=min(ans, abs(i+1-l1.first));
    if(l2.second!=c[i]) ans=min(ans, abs(i+1-l2.first));
    if(r1.second!=c[i]) ans=min(ans, abs(i+1-r1.first));
    if(r2.second!=c[i]) ans=min(ans, abs(i+1-r2.first));
    cout << ans << ' ';
  }
  return 0; 
}