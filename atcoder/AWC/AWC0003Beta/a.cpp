#include<iostream>
using namespace std;
using ll = long long;

int main(void){
  ll n, k; cin >> n >> k;
  int ans=0;
  for(int i=0; i<n; i++){
    ll a, b; cin >> a >> b;
    if(a*b>=k) ans++;
  }
  cout << ans << endl;
  return 0;
}