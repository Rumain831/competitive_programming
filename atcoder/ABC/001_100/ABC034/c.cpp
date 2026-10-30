#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: grid, 場合の数

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
  int h, w; cin >> h >> w;
  ll mod=1e9+7;
  auto [fact, invfact]=factorial(h+w+1, mod);
  cout << fact[h+w-2]*invfact[h-1]%mod*invfact[w-1]%mod << endl;
  return 0;
}
