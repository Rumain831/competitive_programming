#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 数え上げ

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
  int n, k; cin >> n >> k;
  vector<int> h(n);
  ll sum=0, mod=1e9+7;
  for(auto&x:h) cin >> x, sum+=x;
  if(k!=1){
    cout << 0 << endl; return 0;
  }
  auto [fact, inv]=factorial(sum+1, mod);
  ll ans=fact[sum];
  for(int i=0; i<n; i++) ans*=inv[h[i]], ans%=mod;
  cout << ans << endl;
  return 0; 
}