#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 貪欲法

int main(void){
  ll n, k; cin >> n >> k;
  vector<ll> p(n);
  for(auto&x:p) cin >> x;
  sort(rbegin(p), rend(p));
  ll ans=0;
  for(int i=0; i<min(n, k); i++) ans+=p[i];
  cout << ans << endl;
  return 0; 
}