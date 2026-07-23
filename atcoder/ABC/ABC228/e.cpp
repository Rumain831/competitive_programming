#include<iostream>
using namespace std;
using ll = long long;

//Tags: 数え上げ, 整数

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
  ll n, k, m; cin >> n >> k >> m;
  ll mod=998244353;
  //m^(k^n)
  if(m%mod){
    ll p=modpow(k, n, mod-1);
    cout << modpow(m, p, mod) << endl;
  }
  else{
    cout << 0 << endl; return 0;
  }
  return 0;
}