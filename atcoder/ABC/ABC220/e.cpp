#include<iostream>
using namespace std;
using ll = long long;

//Tags: 数え上げ, 木

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
  ll n, d; cin >> n >> d;
  ll mod=998244353;
  ll must=(d+1)/2;
  ll pow0=modpow(2, d, mod), pow1=modpow(2, d-1, mod);
  auto f=[&](ll k){
    ll ans=0;
    //パスの端点のいずれかがLCAと一致するとき
    if(k+d<=n) ans+=pow0*2%mod;
    //パスがLCAで折れ曲がるとき
    //k+l<=n and k+d-l<=n and l>=1 and d-l>=1
    //l<=min(d-1, n-k) and max(1, k+d-n)<=l
    ll c=min(d-1, n-k)-max(1ll, k+d-n)+1;
    ans+=pow1*c%mod;
    return ans;
  };
  ll ans=0;
  for(int k=1; k+must<=n; k++){
    ans+=modpow(2, k-1, mod)*f(k)%mod; ans%=mod;
  }
  cout << ans << endl;
  return 0;
}