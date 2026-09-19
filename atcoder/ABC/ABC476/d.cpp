#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 最適化, 全探索, 貪欲法

int main(void){
  ll n, m, k; cin >> n >> m >> k;
  ll x, y; cin >> x >> y;
  vector<ll> a(n), b(m), suma(n+1);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  for(int i=0; i<n; i++) suma[i+1]=suma[i]+a[i];
  auto buyA=[&](ll x){
    if(x<0) return 0ll;
    ll k=upper_bound(begin(suma), end(suma), x)-begin(suma);
    return k-1;
  };
  ll ans=buyA(x+y*k);
  for(int i=0; i<m; i++){
    ll usek=(b[i]+k-1)/k;
    if(usek>y) break;
    x+=usek*k-b[i], y-=usek;
    ans=max(ans, i+1+buyA(x+y*k));
  }
  cout << ans << endl;
  return 0; 
}