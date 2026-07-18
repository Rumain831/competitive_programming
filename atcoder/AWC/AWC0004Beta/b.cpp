#include<iostream>
using namespace std;
using ll = long long;

int main(void){
  ll n, t; cin >> n >> t;
  ll ans=0;
  for(int i=0; i<n; i++){
    ll a, b; cin >> a >> b;
    ans+=max(a-b*t, 0ll);
  }
  cout << ans << endl;
  return 0;
}