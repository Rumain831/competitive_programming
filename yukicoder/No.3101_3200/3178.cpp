#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 数え上げ
//Level: 1.5

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
  string s; cin >> s;
  int n=s.size(), m=n;
  vector<ll> cnt(10), fact(2e5+2, 1), invfact(2e5+2, 1);
  ll mod=998244353;
  for(ll i=2; i<=2e5; i++) fact[i]=fact[i-1]*i%mod;
  invfact[2e5]=modpow(fact[2e5], mod-2, mod);
  for(ll i=2e5-1; i>=1; i--) invfact[i]=invfact[i+1]*(i+1)%mod;
  for(auto p:s) cnt[p-'0']++;
  ll ansall=1, lead0=1;
  for(int i=0; i<10; i++) ansall*=fact[m]*invfact[cnt[i]]%mod*invfact[m-cnt[i]]%mod, ansall%=mod, m-=cnt[i];
  m=n;
  if(cnt[0]){
    m--;
    cnt[0]--;
    for(int i=0; i<10; i++) lead0*=fact[m]*invfact[cnt[i]]%mod*invfact[m-cnt[i]]%mod, lead0%=mod, m-=cnt[i];
  }
  else lead0=0;
  //cout << ansall << ' ' << lead0 << endl;
  cout << (ansall-lead0+mod)%mod << endl;
  return 0; 
}