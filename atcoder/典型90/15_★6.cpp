#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 場合の数
//解説URL: https://twitter.com/e869120/status/1382827276673306624

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
  ll n; cin >> n;
  ll mod=1e9+7;
  auto [fact, inv]=factorial(n+1, mod);
  auto comb=[&](ll n, ll k){
    return fact[n]*inv[k]%mod*inv[n-k]%mod;
  };
  vector<ll> ans(n+1);
  for(ll k=1; k<=n; k++)for(ll x=1; k*x<=n+k-1; x++){
    ans[k]+=comb(n-(k-1)*(x-1), x); ans[k]%=mod;
  }
  for(int i=1; i<=n; i++) cout << ans[i] << endl;
  return 0;
}