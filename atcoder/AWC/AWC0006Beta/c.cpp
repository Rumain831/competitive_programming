#include<iostream>
using namespace std;
using ll = long long;

int main(void){
  int n, m, d; cin >> n >> m >> d;
  ll ans=0;
  for(int i=0; i<n; i++){
    ll t; cin >> t;
    if(t<=m) continue;
    ll dif=t-m;
    ans+=(t-m+d-1)/d;
  }
  cout << ans << endl;
  return 0;
}