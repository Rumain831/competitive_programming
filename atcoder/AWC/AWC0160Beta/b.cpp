#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 累積和

int main(void){
  int n; cin >> n;
  ll ans=-1e18, now=0, mi=0;
  for(int i=0; i<n; i++){
    ll a; cin >> a; a--;
    now+=a;
    ans=max(ans, now-mi);
    mi=min(mi, now);
  }
  cout << ans << endl;
  return 0; 
}