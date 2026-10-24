#include<iostream>
using namespace std;
using ll = long long;

//Tags: 数え上げ
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
  int n; cin >> n;
  int plus=0, minus=0, zero=0;
  for(int i=0; i<n; i++){
    int c; cin >> c;
    if(c>0) plus++;
    else if(c<0) minus++;
    else zero++;
  }
  ll ans=2, mod=998244353;
  if(plus==0||minus==0){
    cout << modpow(2, n-1, mod) << endl; return 0;
  }
  ans*=modpow(2, plus-1, mod), ans%=mod;
  ans*=modpow(2, minus-1, mod), ans%=mod;
  if(zero) ans*=3, ans%=mod;
  cout << ans << endl;
  return 0; 
}