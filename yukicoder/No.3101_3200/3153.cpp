#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 確率
//Level: 2.5

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
  int n, k; cin >> n >> k;
  ll mod=998244353;
  vector<ll> a(n), rev(n);
  ll maxi=-1;
  for(int i=0; i<n; i++){
    cin >> a[i];
    maxi=max(maxi, a[i]);
    rev[i]=modpow(a[i], mod-2, mod);
  }
  auto prob=[&](ll tar){
    if(tar==0) return 0ll;
    ll ans=1;
    for(int i=0; i<n; i++){
      ans*=(min(tar, a[i])*rev[i])%mod;
      ans%=mod;
    }
    return ans;
  };
  cout << (prob(k)-prob(k-1)+mod)%mod << endl;
  return 0;
}