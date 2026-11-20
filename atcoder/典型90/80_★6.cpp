#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: bit演算, 包除原理
//解説URL: https://twitter.com/e869120/status/1410368312760934404

int main(void){
  int n, d; cin >> n >> d;
  vector<ll> a(n);
  for(auto&x:a) cin >> x;
  int mx=(1<<n);
  ll ans=0;
  for(int i=0; i<mx; i++){
    ll f=0, p=0;
    for(int j=0; j<n; j++)if(i>>j&1) f|=a[j], p++;
    int c=0;
    for(int j=0; j<d; j++)if(!(f>>j&1)) c++;
    ans+=(1ll<<c)*(p&1?-1:1);
  }
  cout << ans << endl;
  return 0;
}