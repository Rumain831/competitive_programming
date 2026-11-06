#include<iostream>
using namespace std;
using ll = long long;

//Tags: ゲーム
//Level: 2

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

int main(void){
  ll n, l; cin >> n >> l;
  ll b=(n+l-1)/l, mod=998244353;
  ll ans=modpow(2, b, mod)-1; 
  cout << (ans+mod)%mod << endl;
  return 0; 
}