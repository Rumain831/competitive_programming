#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 数え上げ
//n+k-1Ck が答え
//例えば、n=6, k=4のとき
//oo|o|oo||o を
//oo -> a1=2
//oo o -> a2=3
//oo o oo -> a3=5
//oo o oo -> a4=5
//と解釈する。

ll modpow(ll a, ll b, ll p){
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
  ll n, k; cin >> n >> k;
  ll mod=1e9+7;
  auto [fact, inv]=factorial(n+k, mod);
  cout << fact[n+k-1]*inv[k]%mod*inv[n-1]%mod << endl;
  return 0;
}