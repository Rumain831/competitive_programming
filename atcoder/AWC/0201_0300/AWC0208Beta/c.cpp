#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 貪欲法

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> v(n);
  for(auto&x:v) cin >> x;
  sort(rbegin(v), rend(v));
  ll ans=0;
  for(int i=0; i<n; i+=m) ans+=v[i];
  cout << ans << endl;
  return 0; 
}