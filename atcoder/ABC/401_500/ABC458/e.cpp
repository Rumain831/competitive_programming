#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

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
  ll x[3];
  cin >> x[0] >> x[1] >> x[2];
  ll n=x[0]+x[1]+x[2];
  ll mod=998244353;
  auto [fact, rev]=factorial(n+3, mod);
  auto nCk=[&](ll p, ll q){
    if(p<0||q<0||p<q) return 0ll;
    return fact[p]*rev[q]%mod*rev[p-q]%mod;
  };
  auto R=[&](int r){
    if(x[1]<r) return 0ll;
    int rem=x[1]-r;
    return nCk(x[0]+x[2]+rem, rem);
  };
  if(x[0]==0||x[2]==0){
    cout << nCk(n, x[1]) << endl; return 0;
  }
  else if(x[1]==0){
    if(x[0]==0||x[2]==0) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
  }
  ll ans=0;
  for(int p=1; p<=x[2]; p++){
    ll div=nCk(x[2]-1, p-1);
    ll now=0;
    now+=nCk(x[0]-1, p-2)*R(2*p-2)%mod;
    now+=2ll*nCk(x[0]-1, p-1)%mod*R(2*p-1)%mod, now%=mod;
    now+=nCk(x[0]-1, p)*R(2*p)%mod, now%=mod;
    ans+=now*div%mod, ans%=mod;
  }
  cout << ans << endl;
  return 0;
}