#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 数え上げ, 主客転倒
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

pair<vector<ll>, vector<ll>> factorial(int n, ll mod){
  vector<ll> fact(n+1, 1), invfact(n+1, 1);
  for(ll i=2; i<=n; i++) fact[i]=fact[i-1]*i%mod;
  invfact[n]=modpow(fact[n], mod-2, mod);
  for(ll i=n-1; i>=1; i--) invfact[i]=invfact[i+1]*(i+1)%mod;
  return {fact, invfact};
}

int main(void){
  int n, m; cin >> n >> m;
  ll mod=1e9+7;
  auto [fact, inv]=factorial(2*n+1, mod);
  auto nCk=[&](int n, int k){
    return fact[n]*inv[k]%mod*inv[n-k]%mod;
  };
  ll ans=nCk(2*n, n)*2*n%mod;
  while(m--){
    int t, x, y; cin >> t >> x >> y;
    ll minus, dx, dy;
    if(t==1) dx=n-x-1, dy=n-y;
    else dx=n-x, dy=n-y-1;
    minus=nCk(x+y, x)*nCk(dx+dy, dx)%mod;
    ans=(ans-minus+mod)%mod;
  }
  cout << ans << endl;
  return 0; 
}