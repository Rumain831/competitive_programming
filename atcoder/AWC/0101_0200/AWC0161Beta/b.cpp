#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 貪欲法, ゲーム

int main(void){
  int n; cin >> n;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  sort(rbegin(a), rend(a));
  ll ans=0;
  for(int i=0; i<n; i+=2) ans+=a[i];
  cout << ans << endl;
  return 0; 
}