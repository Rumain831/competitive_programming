#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: bit全探索

int main(void){
  ll n, w; cin >> n >> w;
  vector<ll> a(n), b(n);
  for(int i=0; i<n; i++) cin >> a[i] >> b[i];
  int mx=(1<<n);
  ll ans=0;
  for(int i=1; i<mx; i++){
    ll now=0, sw=0;
    for(int j=0; j<n; j++)if(i>>j&1){
      now+=a[j], sw+=b[j];
    }
    if(sw<=w) ans=max(ans, now);
  }
  cout << ans << endl;
  return 0; 
}