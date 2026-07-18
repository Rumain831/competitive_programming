#include<iostream>
using namespace std;
using ll = long long;

int main(void){
  ll n, m; cin >> n >> m;
  ll ans=-1;
  for(int i=0; i<n; i++){
    ll a, b; cin >> a >> b;
    if(a>m) ans=max(ans, 0ll);
    else{
      ans=max(ans, (m-a+b-1)/b);
    }
  }
  cout << ans << endl;
  return 0;
}