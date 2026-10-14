#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

ll modpow(ll a, ll b, ll p){
  ll ans=1;
  while(b>0){
    if(b%2==1) ans=(ans*a)%p;
    b/=2;
    a=(a*a)%p;
  }
  return ans;
}

struct RollingHash{
  const ll MOD=1000000007, Base1=91138233, Base2=3;
  vector<pair<ll, ll>> h;
  vector<ll> power1, power2, inv1, inv2;
  RollingHash(const string& s){
    if(s.empty()) return;
    int n=s.size();
    h.resize(n);
    power1.resize(n); power2.resize(n);
    inv1.resize(n); inv2.resize(n);
    power1[0]=power2[0]=1;
    inv1[0]=inv2[0]=1;
    ll r1=modpow(Base1, MOD-2, MOD);
    ll r2=modpow(Base2, MOD-2, MOD);
    for(int i=1; i<n; i++){
      power1[i]=power1[i-1]*Base1%MOD;
      power2[i]=power2[i-1]*Base2%MOD;
      inv1[i]=inv1[i-1]*r1%MOD;
      inv2[i]=inv2[i-1]*r2%MOD;
    }
    h[0]={s[0]-'a'+1, s[0]-'a'+1};
    for(int i=1; i<n; i++){
      ll now1=(s[i]-'a'+1)*power1[i]%MOD;
      ll now2=(s[i]-'a'+1)*power2[i]%MOD;
      now1+=h[i-1].first; now1%=MOD;
      now2+=h[i-1].second; now2%=MOD;
      h[i]={now1, now2};
    }
  }

  pair<ll, ll> getHash(int l, int r) const { //[l, r], 0-indexed
    auto ans=h[r];
    if(l){
      ans.first=(ans.first-h[l-1].first+MOD)%MOD*inv1[l]%MOD;
      ans.second=(ans.second-h[l-1].second+MOD)%MOD*inv2[l]%MOD;
    }
    return ans;
  }
};

vector<int> rabinKarp(const string& T, const string& P){
  vector<int> ans;
  int n=T.size(), m=P.size();
  RollingHash tar(P);
  RollingHash text(T);
  pair<ll, ll> target=tar.getHash(0, m-1);
  for(int i=0; i<n-m+1; i++){
    if(text.getHash(i, i+m-1)==target) ans.push_back(i);
  }
  return ans;
}