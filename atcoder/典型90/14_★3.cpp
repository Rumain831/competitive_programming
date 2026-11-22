#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 最適化, 貪欲法
//解説URL: https://twitter.com/e869120/status/1382478816627478530

int main(void){
  int n; cin >> n;
  vector<ll> a(n), b(n);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  ll ans=0;
  for(int i=0; i<n; i++) ans+=abs(a[i]-b[i]);
  cout << ans << endl;
  return 0;
}