#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 数え上げ
//Level: 2
//z=0の場合に帰着できる。(そうでないならx, yをswapし、z, wをswapする)
//yCw*(x+y-w-1)!*x が答え。

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

pair<vector<ll>, vector<ll>> factorial(int n, ll mod){
  vector<ll> fact(n+1, 1), invfact(n+1, 1);
  for(ll i=2; i<=n; i++) fact[i]=fact[i-1]*i%mod;
  invfact[n]=modpow(fact[n], mod-2, mod);
  for(ll i=n-1; i>=1; i--) invfact[i]=invfact[i+1]*(i+1)%mod;
  return {fact, invfact};
}

int main(void){
  ll x, y, z, w; cin >> x >> y >> z >> w;
  if(w==0) swap(x, y), swap(z, w);
  ll ans=1, mod=998244353;
  auto [fact, inv]=factorial(6e5+1, mod);
  ans=fact[y]*inv[w]%mod*inv[y-w]%mod*fact[x+y-w-1]%mod*x%mod;
  cout << ans << endl;
  return 0; 
}