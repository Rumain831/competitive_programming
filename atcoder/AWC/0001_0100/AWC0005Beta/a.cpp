#include<iostream>
using namespace std;
using ll = long long;

int main(void){
  ll n, k; cin >> n >> k;
  ll ans=0;
  for(int i=0; i<n; i++){
    ll p; cin >> p;
    if(p%k==0) ans+=p;
  }
  cout << ans << endl;
  return 0;
}