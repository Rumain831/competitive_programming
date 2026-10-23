#include<iostream>
using namespace std;
using ll = long long;

//Tags: 文字列, 数え上げ, 場合分け
//Level: 2.5

ll modpow(ll a, ll b, ll p){
  a%=p;
  ll ans=1;
  while(b>0){
    if(b%2==1) ans=(ans*a)%p;
    b/=2;
    a=(a*a)%p;
  }
  return ans;
}

int main(void){
  ll n; cin >> n;
  if(n==1){
    cout << 2 << endl; return 0;
  }
  ll mod=1e9+7, five=n/2-1;
  ll ans=4*modpow(5, five, mod)%mod;
  if(n&1) ans*=3, ans%=mod;
  cout << ans << endl;
  return 0; 
}