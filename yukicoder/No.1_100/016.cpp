#include<iostream>
using namespace std;
using ll = long long;

//Tags: 整数, ダブリング
//Level: 2

ll modpow(ll a, ll b, ll p){
  ll ans=1;
  while(b>0){
    if(b%2==1) ans=(ans*a)%p;
    b/=2;
    a=(a*a)%p;
  }
  return ans;
}

int main(void){
  ll x, n; cin >> x >> n;
  ll mod=1e6+3;
  ll ans=0;
  for(int i=0; i<n; i++){
    ll a; cin >> a;
    ans+=modpow(x, a, mod);
    ans%=mod;
  }
  cout << ans << endl;
  return 0;
}