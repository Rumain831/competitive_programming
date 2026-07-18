#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(void){
  int n, k; cin >> n >> k;
  vector<ll> a(n), b(n);
  vector<pair<ll, int>> p;
  for(int i=0; i<n; i++){
    cin >> a[i] >> b[i];
    p.emplace_back(a[i]-b[i], i);
  }
  sort(p.rbegin(), p.rend());
  ll ans=0;
  for(int i=0; i<n; i++){
    auto [_, idx]=p[i];
    if(i<k) ans+=b[idx];
    else ans+=a[idx];
  }
  cout << ans << endl;
  return 0;
}