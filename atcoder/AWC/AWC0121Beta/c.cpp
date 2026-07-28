#include<iostream>
using namespace std;
using ll = long long;

//Tags: 整数, 全探索, 素数, Miller-Rabin素数判定法

bool Miller_Rabin(ll n){ //少なくともn<=10^18では有効らしい
  using I128 = __int128_t;
  auto Modpow=[](I128 a, ll b, ll p){
    a%=p;
    I128 ans=1;
    while(b){
      if(b&1) ans=(ans*a)%p;
      b/=2;
      a=(a*a)%p;
    }
    return (ll)ans;
  };
  if(n<2) return false;
  if(n==2) return true;
  if(n%2==0) return false;
  ll test[]={2,325,9375,28178,450775,9780504,1795265022};
  ll x=n-1, s=0;
  while(x%2==0) x/=2, s++;
  for(auto a:test){
    if(a%n==0) continue;
    ll base=Modpow(a, x, n);
    if(base==1) continue;
    for(int j=0; j<=s-1; j++){
      if(base==n-1) break;
      if(j==s-1) return false;
      base=I128(base)*base%n;
    }
  }
  return true;
}

int main(void){
  int t; cin >> t;
  while(t--){
    ll n; cin >> n;
    if(n==2){
      cout << 0 << '\n'; continue;
    }
    ll m=n;
    if(n%2==0) m++;
    while(1){
      if(Miller_Rabin(m)){
        cout << m-n << '\n'; break;
      }
      m+=2;
    }
  }
  return 0; 
}