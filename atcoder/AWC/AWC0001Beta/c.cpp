#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> d(n);
  for(auto&x:d) cin >> x;
  sort(d.rbegin(), d.rend());
  ll ans=0;
  for(int i=k; i<n; i++) ans+=d[i];
  cout << ans << endl;
  return 0;
}